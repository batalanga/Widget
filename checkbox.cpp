#include "checkbox.hpp"
using namespace genv;
///checkbox///
checkbox::checkbox(int pos_x, int pos_y):widget(  pos_x, pos_y){}

checkbox::checkbox(int pos_x, int pos_y, int size1, int size2):widget(  pos_x, pos_y, size1, size2){}

void checkbox::checked(event ev)
{
       C << color(100,100,100)
         << move_to(0,0)
         << box(unit1,unit2)
         << color(200,200,200)
         << move_to(2,2)
         << box(unit1-4,unit2-4);
         for(size_t c=0;c<unit2/10;c++)
        {
        gout << move_to(x+unit1/2-unit2/7,y+unit2/3+unit2/6+c)
             << line_to(x+unit1/2,y+unit2/2+unit2/10+c)
             << line_to(x+unit1/2+unit2/4,y+unit2/2-unit2/4+unit2/10+c);
        }
        if((_x>=(x) and _x <=((x)+unit1)  and _y>(y) and _y<((y)+unit2) and (ev.button==1))or (focused and (ev.keycode==key_space)))
        {
            k=1;
            check=!check;
        }
        if((_x<(x) or _x >=((x)+unit1)  or _y<(y) or _y>((y)+unit2)) and (ev.button==1)){}
        gout << stamp(C,x,y);
        if(check)
        {
            gout << color(0,200,0);
        }
        else
        {
            gout << color(100,100,100);
        }
        for(size_t c=0;c<unit2/10;c++)
        {
        gout << move_to(x+unit1/2-unit2/7,y+unit2/3+unit2/6+c)
             << line_to(x+unit1/2,y+unit2/2+unit2/10+c)
             << line_to(x+unit1/2+unit2/4,y+unit2/2-unit2/4+unit2/10+c);
        }
}
///checkbox_end///
