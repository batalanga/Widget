#ifndef stdfuncbutton_HPP_INCLUDED
#define stdfuncbutton_HPP_INCLUDED
#include <functional>
#include "widget.hpp"
class stdfuncbutton : public widget
{
protected:
    std::function<void()> f;
public:
    stdfuncbutton(int pos_x, int pos_y, std::function<void()> fv);
    stdfuncbutton(int pos_x, int pos_y, int size1, int size2, std::function<void()> fv);
    virtual void checked(genv::event ev)=0;
};


#endif // CHECKBOX_HPP_INCLUDED
