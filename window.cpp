#include "window.hpp"

#include "stdfuncbutton.hpp"
//#include "gauge.hpp"
//#include "checkbox.hpp"
#include "text.hpp"
#include "choose.hpp"
#include <iostream>

using namespace genv;
using namespace std;


window::window(int width, int height) : _width(width),_height(height){D.open(_width,_height);}
window::window(){}/// You have to open in your myapplication the canvas D if you want to use this constructor

void window::run()
{
    gout.open(_width,_height);
    event ev;
    gin.timer(100);
    for(unsigned short c=0;c<widgets.size();c++)
    {
     widgets[c]->canvas_open(_width, _height);
    }
    while(gin >> ev and ev.keycode != key_escape)
    {
        if(ev.type == ev_key  and ev.keycode==key_tab){tab++;}
        if(tab>=int(counter)){tab=0;}
        gout << move_to(0,0) << color(0,0,0) << box_to(_width-1,_height-1);
        gout << stamp(D,0,0);
        for(unsigned short c=0;c<widgets.size();c++)
        {
            widgets[c]->focus(c,tab,focus_visible,ev);
            widgets[c]->checked(ev);
        }
        Masta->knowhatistheretokwnow(widgets);
        Masta->checked(ev);
        if(counter > 0){widgets[tab]->checked(ev);}
        gout << refresh;

    }
}
