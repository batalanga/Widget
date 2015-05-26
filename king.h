#ifndef KING_H_INCLUDED
#define KING_H_INCLUDED
#include "chessbutton.h"
class king : public chessbutton
{
private:
    int r=0;
    int g=0;
    int b=0;
    genv::canvas K;
public:
    king(int pos_x, int pos_y, std::function<void()> fv, bool col);
    king(int pos_x, int pos_y, int size1, int size2, std::function<void()> fv, bool col);
    virtual void checked(genv::event ev);
};


#endif // KING_H_INCLUDED
