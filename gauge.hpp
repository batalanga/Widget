#ifndef GAUGE_H_INCLUDED
#define GAUGE_H_INCLUDED
#include "widget.hpp"
class gauge: public widget
{
private:
    double stick_x=x+unit1/2-(unit1*3/8);
    bool leftc;
    bool good=0;
    int value=0;
    int lshift=0;
    int r=0;
    int serial;
public:
    gauge(int pos_x, int pos_y);
    gauge(int pos_x, int pos_y, int range);
    gauge(int pos_x, int pos_y, int size1, int size2,int range);
    void checked(genv::event ev);
};


#endif // GAUGE_H_INCLUDED
