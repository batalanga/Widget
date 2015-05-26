#ifndef CHESSBUTTON_H_INCLUDED
#define CHESSBUTTON_H_INCLUDED
#include "stdfuncbutton.hpp"

class chessbutton : public stdfuncbutton
{
protected:
    bool bw;
public:
    chessbutton(int pos_x, int pos_y, std::function<void()> fv, bool color);
    chessbutton(int pos_x, int pos_y, int size1, int size2, std::function<void()> fv, bool col);
    virtual void checked(genv::event ev)=0;
};


#endif // CHESSBUTTON_H_INCLUDED
