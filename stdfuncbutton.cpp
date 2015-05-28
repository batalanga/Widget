#include "stdfuncbutton.hpp"
#include "graphics.hpp"
using namespace genv;

stdfuncbutton::stdfuncbutton(int pos_x, int pos_y, std::function<void()> fv)
:widget(  pos_x, pos_y), f(fv){}
stdfuncbutton::stdfuncbutton(int pos_x, int pos_y, int size1, int size2, std::function<void()> fv)
:widget(  pos_x, pos_y,size1,size2), f(fv){}






















///prototype event-handler
//void stdfuncbutton::checked(genv::event ev)
//{
//
//    if(ev.button==1)
//    {
//        click=1;
//    }
//    if(ev.button==-1)
//    {
//        click=0;
//    }
//    if((click and _x < x+unit1 and _x > x and _y< y+unit2 and _y > y) or (focused and ev.keycode==genv::key_space))
//    {
//        r=0;g=175;b=0;
//    }
//    if((!click or _x > x+unit1 or _x < x or _y> y+unit2 or _y < y)and (!focused or ev.type!=1))
//    {
//        r=200;g=100;b=0;
//    }
//                                 genv::gout << genv::move_to(x,y)
//                                            << genv::color(r,g,b)
//                                            << genv::box(unit1,unit2)
//                                            << genv::move_to(x+unit1/2,y+unit2/2)
//                                            << genv::color(0,0,0);
//                                            rajz();
//    if((_x < x+unit1 and _x > x and _y< y+unit2 and _y > y and ev.button==-1) or (focused and ev.keycode==genv::key_space))
//    {f();}
//}


