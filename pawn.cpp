#include "pawn.h"
#include <iostream>
#include "stdfuncbutton.hpp"
#include "graphics.hpp"
#include <fstream>
#include <iostream>
using namespace genv;
using namespace std;

pawn::pawn(int pos_x, int pos_y, std::function<void()> fv, bool col) : chessbutton (pos_x, pos_y, fv,col){}
pawn::pawn(int pos_x, int pos_y, int size1, int size2, std::function<void()> fv, bool col) : chessbutton (pos_x, pos_y, size1, size2, fv,col)
{
    K.open(101,101);
    K.transparent(1);
    int r=255;int g=255;int b=255;
    ifstream paraszt;
    if(bw)
    {
    paraszt.open ("pawn.kep");
    }
    else
    {
    paraszt.open ("pawn2.kep");
    }
    paraszt >> r >> r;
    for(int c=0;c<100;c++)
    {
        for(int d=0;d<51;d++)
        {
            paraszt >> r >> g >> b;
            if(r < 25){r=0;g=0;b=0;}
            K << move_to(d,c)<< color(r,g,b) << dot;
        }
    }
}

void pawn::checked(genv::event ev)
{
    gout << stamp(K,x+20,y);
    if((_x < x+unit1 and _x > x and _y< y+unit2 and _y > y and ev.button==-1))
    {f();k=1;}
}
