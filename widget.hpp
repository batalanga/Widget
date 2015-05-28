#ifndef WIDGET_HPP_INCLUDED
#define WIDGET_HPP_INCLUDED
#include "graphics.hpp"
#include <vector>
class widget
{
protected:
    friend class gamemaster;
    unsigned int unit1,unit2,x,y,_y,_x;
    genv::canvas C;
    bool focused;
    bool k=0;
    std::string a;
    widget(int pos_x, int pos_y);
    widget(int pos_x, int pos_y, int size1, int size2);
public:
    virtual void focus(short c, int &tab,bool f_visible,genv:: event &ev);
    virtual void canvas_open(const int width,const int height);
    virtual void checked(genv::event ev)=0;
};
#endif // WIDGET_H_INCLUDED
