#include "chessbutton.h"
#include <iostream>
 using namespace genv;
  using namespace std;


chessbutton::chessbutton(int pos_x, int pos_y, std::function<void()> fv, bool col)
:stdfuncbutton(pos_x, pos_y, fv), bw(col){}
chessbutton::chessbutton(int pos_x, int pos_y, int size1, int size2, std::function<void()> fv, bool col)
:stdfuncbutton(  pos_x, pos_y,size1,size2, fv),bw(col){}


