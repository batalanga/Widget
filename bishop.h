#ifndef BISHOP_H_INCLUDED
#define BISHOP_H_INCLUDED
#include "chessbutton.h"
class bishop : public chessbutton
{
private:
    int r=0;
    int g=0;
    int b=0;
    genv::canvas K;
public:
    bishop(int pos_x, int pos_y, std::function<void()> fv, bool col);
    bishop(int pos_x, int pos_y, int size1, int size2, std::function<void()> fv, bool col);
    virtual void checked(genv::event ev);
};




#endif // BISHOP_H_INCLUDED
