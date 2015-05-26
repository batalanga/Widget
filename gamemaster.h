#ifndef GAMEMASTER_H_INCLUDED
#define GAMEMASTER_H_INCLUDED
#include "widget.hpp"
class gamemaster : public widget
{
private:
    unsigned short helper=33;
    unsigned short target=33;
    unsigned short havetokill=33;
    std::vector<widget*> widgets;
public:
    gamemaster(int pos_x, int pos_y);
    gamemaster(int pos_x, int pos_y, int size1, int size2);
    void checked(genv::event ev);
    void get_target(unsigned short y){target=y;}
    unsigned short thereisnothingthere(unsigned int __x, unsigned int __y);
    void knowhatistheretokwnow(std::vector<widget*> & figures);
};


#endif // GAMEMASTER_H_INCLUDED
