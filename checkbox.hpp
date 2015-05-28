#ifndef CHECKBOX_HPP_INCLUDED
#define CHECKBOX_HPP_INCLUDED
#include "widget.hpp"
class checkbox : public widget
{
private:
    bool check=0;
public:
    checkbox(int pos_x, int pos_y);
    checkbox(int pos_x, int pos_y, int size1, int size2);
    void checked(genv::event ev);
};


#endif // CHECKBOX_HPP_INCLUDED
