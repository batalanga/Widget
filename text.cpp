#include "text.hpp"
#include <iostream>
#include <sstream>

using namespace std;
using namespace genv;

///dynamic_text///
dynamic_text::dynamic_text(int pos_x, int pos_y):widget(  pos_x, pos_y){}
dynamic_text::dynamic_text(int pos_x, int pos_y, int size1, int size2):widget(  pos_x, pos_y, size1, size2){}
void dynamic_text::checked(event ev)
{
    ///box///
           C << color(100,100,100)
             << move_to(0,0)
             << box(unit1,unit2)
             << color(200,200,200)
             << move_to(((unit1/16)),((unit2/16)))
             << box(unit1-(unit1/8),unit2-(unit2/8));
        ///box_end///

        ///box///
        gout << stamp(C,x,y)
        ///box_end///

        ///text///
            << color(0,0,255)
            << move_to((x+(unit1/16))+2,y+unit2*5/gout.cascent());

        if(letter+(unit1*7/64)>letters.size() and (letters.size()-(letter-counter)<(unit1*7/64)))
        {
            for(size_t c=(letter-counter);c<letters.size();c++)
                {
                    gout << text(letters[c]);
                }
        }
        else
        {
            for(size_t c=(letter-counter);c<(letter-counter)+(unit1*7/64);c++)
                {
                    gout << text(letters[c]);
                }
        }
        ///text_end///
    if(!focused){good=0;}
    if(focused){good=1;}
    if(_x>=(x) and _x <=(x+unit1) and _y>(y) and _y<(y+unit2) and (ev.button==1)){good=1;k=1;}
    if(good)
    {
        ///hitbox///
        if((ev.keycode >= 97 and ev.keycode <= 123) or (ev.keycode==32) or
          (ev.keycode==205 or ev.keycode==211 or ev.keycode==213 or ev.keycode==214 or ev.keycode==218 or ev.keycode==220 or ev.keycode==225 or
            ev.keycode==233 or ev.keycode==237 or ev.keycode==243 or ev.keycode==245 or ev.keycode==246 or ev.keycode==250 or ev.keycode==251 or
            ev.keycode==252) or (ev.keycode >= 48 and ev.keycode <= 57) or (ev.keycode >= 65 and ev.keycode <= 91))
        {letters.insert(letters.begin()+letter,ev.keycode);counter++;letter++;}
        ///hitbox_end///

        ///control panel///
            if(letter < counter){counter=letter;}
            if(ev.keycode==key_right and (letter<letters.size())){counter++;letter++;}
            if(ev.keycode==key_left){if(counter!=0){counter--;}if(letter!=0){letter--;}}
            if(ev.keycode==key_backspace and (letter!=0)){letters.erase(letters.begin()+letter-1);counter--;letter--;}
            if(ev.keycode==key_backspace){backspace=1;time2=ev.time;}
            if(ev.keycode==-key_backspace){backspace=0;time2=0;}
            if(backspace and (letter!=0) and ev.time>time2+500 and time2!=0){letters.erase(letters.begin()+letter-1);counter--;letter--;}
            if(ev.keycode==key_delete and letter!=letters.size()){letters.erase(letters.begin()+letter);}
            if(ev.keycode==key_home){counter=0;letter=0;}
            if(ev.keycode==key_end){counter=(unit1*7/64);letter=letters.size();}
            short switcher;
            if(counter>letters.size() or counter>(unit1*7/64))
            {
                if(counter>letters.size()){switcher=2;}
                if (counter>(unit1*7/64)){switcher=1;}
            }
            else{switcher=0;}
            switch(switcher)
            {
                case 2:
                    counter=letters.size();
                    break;
                case 1:
                    counter=(unit1*7/64);
                    break;
                case 0:
                    break;
            }
            ///control panel_end///


                ///cursor//
                if(ev.time!=0){time=ev.time;}
                if((time/1000)*1000+500>=time and (time/1000)*1000<=time)
                {
        short c_pos=(x-unit1/2+(unit1/16))+2+(gout.twidth(letters.substr(letter-counter,counter)));
        gout << color(0,0,0)
             << move_to(c_pos+unit1/2,y+unit2)
             << line_to(c_pos+unit1/2,y)
             << color (255,255,255);
                }
                ///cursor_end///

    }
}

string dynamic_text::get_text(){return letters;}
void dynamic_text::erase_text(){letters="";counter=0;letter=0;}
///dynamic_text_end///

///dynamic_number///
dynamic_number::dynamic_number(int pos_x, int pos_y):dynamic_text(  pos_x, pos_y){}
dynamic_number::dynamic_number(int pos_x, int pos_y, int size1, int size2):dynamic_text(  pos_x, pos_y, size1, size2){}
void dynamic_number::add_character( char character)
{
    letters.insert(letters.begin()+letter,character);counter++;letter++;
}
void dynamic_number::add_Ans()
{
    letters.insert(letters.begin()+letter,'A');counter++;letter++;
    letters.insert(letters.begin()+letter,'n');counter++;letter++;
    letters.insert(letters.begin()+letter,'s');counter++;letter++;
}

void dynamic_number::find_prior(vector<function<double(double, double)> > &operation,vector<double> &n, vector<bool> &prior)
{
    unsigned int c=0;
    while(c<operation.size())
    {
        if(prior[c])
        {
                n[c+1]=operation[c](n[c],n[c+1]);
                n.erase(n.begin()+c);operation.erase(operation.begin()+c);prior.erase(prior.begin()+c);
        }
        else
        {
            c++;
        }
    }
    for(size_t c=0;c<operation.size();c++)
    {
        n[c+1]=operation[c](n[c],n[c+1]);
    }
}

//void dynamic_number::equial()
//{
//    if(letters.size()!=0)
//    {
//        double _number2=0;
//        vector<double> n;
//        vector<function<double(double, double)> > operation;
//        vector<bool> prior;
//        double a=0;//kezdeti értékadás
//        n.push_back(a);
//        for(unsigned int c=0;c<letters.size();c++)
//        {
//            if(letters[c]=='A' and letters[c+1]=='n' and letters[c+2]=='s')
//            {
//                n[counter2]=Ans;
//            }
//            if(letters[c]=='+' or letters[c]=='-' or letters[c]=='/' or letters[c]=='*')
//            {
//                part=0;//tizedesjegyek után mûvelet jön -> tizedesjegy igaz kikapcsolva
//                n[counter2]=n[counter2]+_number2/decimal;//mûveletvégzõ alakra hozás
//                if(letters[c]=='+')
//                {
//                function<double(double, double)> op = plus<double>();
//                operation.push_back(op);
//                prior.push_back(0);
//                }
//                if(letters[c]=='-')
//                {
//                function<double(double, double)> op = minus<double>();
//                operation.push_back(op);
//                prior.push_back(0);
//                }
//                if(letters[c]=='*')
//                {
//                function<double(double, double)> op = multiplies<double>();
//                operation.push_back(op);
//                prior.push_back(1);
//                }
//                if(letters[c]=='/')
//                {
//                function<double(double, double)> op = divides<double>();
//                operation.push_back(op);
//                prior.push_back(1);
//                }
//                if(letters[c]=='(')
//                {
//                //operation.push_back(op);
//                }
//                if(letters[c]==')')
//                {
//                //operation.push_back(op);
//                }
//                double a=0;//új szám felvétele
//                n.push_back(a);
//                counter2++;
//            }
//            if(letters[c]=='.')
//            {
//                _number2=0;
//                decimal=1;
//                part=1;
//            }
//            if ((letters[c]=='0' or letters[c]=='1' or letters[c]=='2' or letters[c]=='3' or letters[c]=='4' or letters[c]=='5'
//            or letters[c]=='6' or letters[c]=='7' or letters[c]=='8' or letters[c]=='9'))
//            {
//                int temp;
//                stringstream change;
//                change<<letters[c];
//                change>>temp;
//            if(part)
//            {
//                _number2=_number2*10+temp;
//                decimal*=10;
//            }
//            else
//            {
//                n[counter2]=n[counter2]*10+temp;
//            }
//            }
//        }
//        find_prior(operation,n,prior);
//        done2="";
//        stringstream change;
//        done=n[n.size()-1];
//        Ans=done;
//        change<<done;
//        change>>done2;
//        letters="";
//        counter2=0;
//        counter=(unit1*7/64);
//        letter=letters.size();
//        part=0;
//        decimal=1;
//        done=0;
//    }
//}

void dynamic_number::checked(event ev)
{
//     ///box///
//           C << color(200,200,200)
//             << move_to(0,0)
//             << box(unit1,unit2)
//             << color(0,0,0)
//             << move_to(((unit1/16)),((unit2/16)))
//             << box(unit1-(unit1/8),unit2-(unit2/8));
//        ///box_end///
        ///text///
        gout << stamp(C,x,y)
             << color(0,0,255)
             << move_to((x+(unit1/16))+2,y+unit2*5/gout.cascent());
        if(letter+(unit1*7/64)>letters.size() and (letters.size()-(letter-counter)<(unit1*7/64)))
        {
            for(size_t c=(letter-counter);c<letters.size();c++)
                {
                    gout << text(letters[c]);
                }
        }
        else
        {
            for(size_t c=(letter-counter);c<(letter-counter)+(unit1*7/64);c++)
                {
                    gout << text(letters[c]);
                }
        }

        gout << color(0,255,191)
             << move_to((x+(unit1/16))+2,(y+unit2*5/gout.cascent())-(10+gout.cascent()+gout.cdescent()))
             << text("partial result: "+done2);
        ///text_end///
    if(!focused){good=0;}
    if(focused){good=1;}
    if(_x>=(x) and _x <=(x+unit1) and _y>(y) and _y<(y+unit2) and (ev.button==1)){good=1;k=1;}
    if(good)
    {
        ///hitbox///
        if(/*40-41 zárójelek*/(ev.keycode>=42 and ev.keycode<=43) or (ev.keycode >= 45 and ev.keycode <= 57))
        {letters.insert(letters.begin()+letter,ev.keycode);counter++;letter++;}
            if(ev.keycode==44){letters.insert(letters.begin()+letter,ev.keycode+2);counter++;letter++;}
        ///hitbox_end///
        ///control panel///
            if(letter < counter){counter=letter;}
            if(ev.keycode==key_right and (letter<letters.size())){counter++;letter++;}
            if(ev.keycode==key_left){if(counter!=0){counter--;}if(letter!=0){letter--;}}
            if(ev.keycode==key_backspace and (letter!=0)){letters.erase(letters.begin()+letter-1);counter--;letter--;}
            if(ev.keycode==key_backspace){backspace=1;time2=ev.time;}
            if(ev.keycode==-key_backspace){backspace=0;time2=0;}
            if(backspace and (letter!=0) and ev.time>time2+500 and time2!=0){letters.erase(letters.begin()+letter-1);counter--;letter--;}
            if(ev.keycode==key_delete and letter!=letters.size()){letters.erase(letters.begin()+letter);}
            if(ev.keycode==key_home){counter=0;letter=0;}
            if(ev.keycode==key_end){counter=(unit1*7/64);letter=letters.size();}
            short switcher;
            if(counter>letters.size() or counter>(unit1*7/64))
            {
                if(counter>letters.size()){switcher=2;}
                if (counter>(unit1*7/64)){switcher=1;}
            }
            else{switcher=0;}
            switch(switcher)
            {
                case 2:
                    counter=letters.size();
                    break;
                case 1:
                    counter=(unit1*7/64);
                    break;
                case 0:
                    break;
            }
            ///control panel_end///


                ///cursor//
                if(ev.time!=0){time=ev.time;}
                if((time/1000)*1000+500>=time and (time/1000)*1000<=time)
                {
        short c_pos=(x-unit1/2+(unit1/16))+2+(gout.twidth(letters.substr(letter-counter,counter)));
        gout << color(0,0,0)
             << move_to(c_pos+unit1/2,y+unit2)
             << line_to(c_pos+unit1/2,y)
             << color (255,255,255);
                }
                ///cursor_end///
                if(ev.keycode==key_enter)
                {
//                    equial();
                }
    }

}
///dynamic_number_end///



///static_text///
static_text::static_text(int pos_x, int pos_y):widget(  pos_x, pos_y){}
static_text::static_text(int pos_x, int pos_y, int size1, int size2):widget(  pos_x, pos_y, size1, size2){}

void static_text::checked(event ev)
{
        gout << move_to(x,y)
             << color(255,255,255)
             << text(text_out);
}
///static_text_end///
