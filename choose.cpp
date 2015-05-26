#include "choose.hpp"
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;
using namespace genv;
static unsigned int seldom=0;
///choose///
choose::choose(int pos_x, int pos_y):widget(  pos_x, pos_y), c_p(4),wmp(1)
{seldom++;serial=seldom;}
choose::choose(int pos_x, int pos_y, string start):widget(  pos_x, pos_y),c_p(4),wmp(1)
{seldom++;serial=seldom;pieces.push_back(start);}
choose::choose(int pos_x, int pos_y, vector <string> start):widget(  pos_x, pos_y), pieces(start),c_p(4),wmp(1)
{seldom++;serial=seldom;}
choose::choose(int pos_x, int pos_y, int size1, int size2, vector <string> start,int choosable_piecenumber,double width_multiplier)
:widget(  pos_x, pos_y, size1, size2), pieces(start),c_p(choosable_piecenumber),wmp(width_multiplier)
{seldom++;serial=seldom;}
void choose::checked(event ev)
{
    ///f1_f12 bind//
    if(ev.keycode == key_rshift){lshift=1;}
    if(ev.keycode ==-key_rshift){lshift=0;}
    if(focused)
    {
        for(size_t c=0;c<pieces.size();c++)
        {
            if(lshift and ev.keycode==(131073+int(c))){choosen=pieces[c];}
        }
    if(ev.button==5 and (c_p+counter<pieces.size())){counter++;}
    if(ev.button==4 and (counter >0)){counter--;}
    }
    ///f1_f12 bind_end///


    ///output.txt///
    if (ev.keycode == 112)
    {
        ofstream kiir ("output.txt",ios::app);
        kiir <<serial <<". choosen one: "<< choosen<< endl;
        kiir.close();
    }
    ///output.txt_end///

        gout << color(175,175,175)
             << move_to(x,y)
             << box(unit1,unit2)
             << color(255,255,255)
             << move_to(x+3,y+3)
             << box(unit1-6,unit2-6)
             << move_to(x+6,y+unit2*2/3)
             << color (0,0,0)
             << text(choosen)

             ///arrow-thingy_button///
             << color(125,125,125)
             << move_to(x+unit1+3-unit2,y+3)
             << box(unit2-6,unit2-6)
             << color(0,0,0);
         for(size_t c=0;c<(unit2*2/3-c);c++)
         {
             gout << move_to(x+unit1-unit2+float(unit2/3)+c,y+float(unit2/3))
                  << line_to(x+unit1-unit2+float(unit2/2)+float(c/2),y+float(unit2*2/3)-c);
         }
             ///arrow-thingy_button_end///

         if((_x > (x) and _x < (x+unit1)and _y > (y) and _y < (y+unit2) and (ev.button==1))){active=1;k=1;focused=1;}
         if(pieces.size()==0){choosen="";}
         if(pieces.size()!=0 and choosen==""){choosen=pieces[0];}//0-rol feltoltes: elso elem hozzaad
         if(active and (pieces.size()!=0))
        {
        if(((_x < (x) or _x > (x+unit1) or _y < (y) or _y > (y+unit2*(pieces.size()+1)))and (ev.button==1)) or !focused)
            {active=0;} ///turn-off//

             ///short version///
            if(pieces.size()<=c_p)
            {
            gout << color(225,225,255)
                 << move_to(x,y+unit2)
                 << box((unit1*wmp),(unit2*pieces.size()))
                 << color(0,0,0);
                 for(size_t c=1;c<pieces.size()+1;c++)
                 {

                    string temp;
                    stringstream change;
                    change << c;
                    change >> temp;
                    gout << move_to(x+6,y+unit2/2+unit2*c)
                          << text(pieces[c-1])
                          << move_to(x+6+unit1/2,y+unit2/2+unit2*c)
                          << text("shift-f")
                          << text(temp);
                    if((_x > (x) and _x < (x+unit1*wmp) and _y > (y+unit2*c) and _y < (y+unit2*(c+1))) and (ev.button==1) )
                        {choosen=pieces[c-1];active=0;choosenn=counter+(c);}
                 }
            }///short version_end///
            else
            {///scrolling(full) version///
            gout << color(225,225,255)
                 << move_to(x,y+unit2)
                 << box((unit1*wmp),(unit2*c_p))
                 << color(0,0,0);
                 for(size_t c=(1+counter);c<(c_p+1+counter);c++)
                 {
                    gout << move_to(x+6,y+unit2/2+unit2*(c-counter))
                         << text(pieces[c-1]);
                          if(c<13)
                    {
                    string temp;
                    stringstream change;
                    change << c;
                    change >> temp;
                    gout << move_to(x+unit1*wmp-90,y+unit2/2+unit2*(c-counter))
                         << text("shift-f")
                         << text(temp);
                    }
                    for(size_t c=0;c<c_p;c++)
                    {
                    if((_x > (x) and _x < (x+unit1*wmp) and _y > (y+unit2*(c+1)) and _y < (y+unit2*(c+2))) and (ev.button==1) )
                        {choosenn=counter+(c);choosen=pieces[counter+(c)];active=0;}
                    }
                 }
            }///scrolling(full) version_end///
        }
}

void choose::fill_up(string data)
{
    pieces.push_back(data);
}

void choose::fill_up(vector<string> data)
{
    pieces.insert(pieces.end(), data.begin(), data.end());
}

string choose::erase_choosen()
{
    string temp="";
    if(pieces.size()>0)
    {
        temp=choosen;
       /// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! ///
        if((choosenn) < pieces.size()){pieces.erase(pieces.begin()+choosenn);}
        if(pieces.size() <= choosenn and choosenn!=0){choosenn--;counter--;}
        choosen=pieces[choosenn];
    }
    return temp;
}
