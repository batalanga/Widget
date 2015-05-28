#include "widget.hpp"
#include <fstream>
#include <sstream>
using namespace std;
using namespace genv;
///widget///

///constructor///
widget::widget(int pos_x, int pos_y):unit1(120),unit2(40), x(pos_x),y(pos_y)
{
    ofstream kiir ("output.txt");
    kiir.close();
}
///constructor_end///


///constructor_full///
widget::widget(int pos_x, int pos_y, int size1, int size2):unit1(size1),unit2(size2), x(pos_x),y(pos_y)
{
    ofstream kiir ("output.txt");
    kiir.close();
}
///constructor_full_end///

void widget::focus(short c, int &tab,bool f_visible, event &ev)
{
    if(ev.type == ev_mouse and ev.button==0)
    {
        _x=ev.pos_x;
        _y=ev.pos_y;
    }
    focused=0;
    if(k){tab=c;k=0;}
    if(tab==c)
    {
    focused=1;
    if(f_visible)
    {
    gout << color(255,0,0)
         << move_to(x-5,y-5)
         << box(unit1+10,unit2+10)
         << color (0,0,0)
         << move_to(x-3,y-3)
         << box(unit1+6,unit2+6);
    }
    }
    if(!f_visible)
    {
        focused=1;
    }
}


void widget::canvas_open(const int width,const int height)
{
    C.open(width,height);
    C.transparent(1);
}



///widget_end///
