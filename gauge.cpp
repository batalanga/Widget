#include "gauge.hpp"
#include <sstream>
#include <fstream>
using namespace std;
using namespace genv;
static unsigned int seldom=0;
///gauge///
gauge::gauge(int pos_x, int pos_y):widget(  pos_x, pos_y),r(100){seldom++;serial=seldom;}
gauge::gauge(int pos_x, int pos_y, int range):widget(  pos_x, pos_y),r(range){seldom++;serial=seldom;}
gauge::gauge(int pos_x, int pos_y, int size1, int size2,int range):widget(  pos_x, pos_y, size1, size2),r(range){seldom++;serial=seldom;}

void gauge::checked(event ev)
{

    gout << color(150,150,150)
     << move_to(x,y)
     << box(unit1,unit2)
        ///arrow-buttons///
         << color (200,200,200)
         << move_to (x,y+unit2/2-unit2*3/16)
         << box(unit2*3/8,unit2*3/8)
     << color(100,100,100)
     << move_to (x+unit2*3/32,y+unit2/2)
     << line_to (x+unit2*3/16,y+unit2/2-unit2*3/32)
     << move_to (x+unit2*3/32,y+unit2/2)
     << line_to (x+unit2*3/16,y+unit2/2+unit2*3/32)
     << line_to (x+unit2*3/16,y+unit2/2-unit2*3/32)
        << color (200,200,200)
        << move_to (x+unit1-unit2*3/8,y+unit2/2-unit2*3/16)
        << box(unit2*3/8,unit2*3/8)
     << color(100,100,100)
     << move_to (x+unit1+unit2*9/32-unit2*3/8,y+unit2/2)
     << line_to (x+unit1+unit2*3/16-unit2*3/8,y+unit2/2-unit2*3/32)
     << move_to (x+unit1+unit2*9/32-unit2*3/8,y+unit2/2)
     << line_to (x+unit1+unit2*3/16-unit2*3/8,y+unit2/2+unit2*3/32)
     << line_to (x+unit1+unit2*3/16-unit2*3/8,y+unit2/2-unit2*3/32)
        ///arrow-buttons_end///
     << color(100,100,100)
     << move_to ((x+unit1/2-(unit1*3/8)),y+unit2/2)
     << line_to(((x+unit1/2+(unit1*3/8))),y+unit2/2);

    ///hitboxes///
    ///pull-thingy///
    if(ev.button==1){leftc=1;}
    if(ev.button==-1){leftc=0;good=0;}
    if((_x>=(x) and _x <=(x+unit1)  and _y>(y) and _y<(y+unit2))and (ev.button==1)){good=1;k=1;}
    if((_x<=(x) or _x >=(x+unit1)  or _y<(y) or _y>(y+unit2))and (ev.button==1)){good=0;}
    if(_x>=(x+unit1/2-(unit1*3/8)) and _x <=((x+unit1/2+(unit1*3/8))) and good and leftc)
    {
        stick_x=_x;
    }
    ///pull-thingy_end///

    if(ev.keycode==key_rshift){lshift=1;}
    if(ev.keycode==-key_rshift){lshift=0;}

    if((_x>(x) and _x <((x)+unit2*3/8)  and _y>(y+unit2/2-unit2*3/16) and _y<((y+unit2/2-unit2*3/16)+unit2*3/8)
       and (ev.button==1) and (stick_x > (x+unit1/2-(unit1*3/8)))) or (focused and (ev.keycode==key_left) and value>0 and !lshift))
    {
        stick_x=(double(value-1))/r*((x+double(unit1/2)+(double(unit1)*3/8))-(x+double(unit1/2)
                -(double(unit1*3/8))))+(x+double(unit1/2)-(double(unit1*3/8)));
    }///hitbox-arrow_left///

    if(focused and ev.keycode==key_left and value>0 and lshift and (value-r/10>=0))
    {
        stick_x=(double(value-(r/10)))/r*((x+double(unit1/2)+(double(unit1)*3/8))-(x+double(unit1/2)
                -(double(unit1*3/8))))+(x+double(unit1/2)-(double(unit1*3/8)));
    }/// shift-arrow =-(range/10) ///

    if((_x>(x+unit1-unit2*3/8) and _x <((x+unit1-unit2*3/8)+unit2*3/8)  and _y>(y+unit2/2-unit2*3/16) and _y<((y+unit2/2-unit2*3/16)+unit2*3/8)
        and (ev.button==1)and (stick_x < ((x+unit1/2+(unit1*3/8))-unit2*3/8))) or (focused and (ev.keycode==key_right)  and value<r and !lshift))
    {
        stick_x=(double(value+1))/r*((x+double(unit1/2)+(double(unit1)*3/8))
                -(x+double(unit1/2)-(double(unit1*3/8))))+(x+double(unit1/2)-(double(unit1*3/8)));
    }///hitbox-arrow_right///

    if(focused and ev.keycode==key_right and value<r and lshift and (value+r/10<=r))
    {
        stick_x=(double(value+(r/10)))/r*((x+double(unit1/2)+(double(unit1)*3/8))-(x+double(unit1/2)
                -(double(unit1*3/8))))+(x+double(unit1/2)-(double(unit1*3/8)));
    }/// shift-arrow =+(range/10) ///
    ///hitboxes_end///

    value=(stick_x-(x+unit1/2-(unit1*3/8)))/((x+unit1/2+(unit1*3/8))-(x+unit1/2-(unit1*3/8)))*r;

    stringstream change;
    change << value;
    string v2;
    change>> v2;
    ///output.txt///
    if(ev.keycode==112)
    {
        ofstream kiir ("output.txt",ios::app);
        kiir <<serial<<". gague value: "<< value<< endl;
        kiir.close();
    }
    ///output.txt_end///

    ///pull-thingy-paint///
    gout << move_to(stick_x-unit2*3/16,y+unit2/2-unit2*3/16)
         << box(unit2*3/8,unit2*3/8)
         << color(255,255,255)
         << move_to(stick_x-unit2*3/16,y+unit2/2-unit2*3/16)
         << text(v2);
    ///pull-thingy-paint_end///
}
///gauge_end///
