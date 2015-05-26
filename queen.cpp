#include "queen.h"
#include <iostream>
#include "stdfuncbutton.hpp"
#include "graphics.hpp"
#include <fstream>
using namespace genv;
using namespace std;

queen::queen(int pos_x, int pos_y, std::function<void()> fv, bool col) : chessbutton (pos_x, pos_y, fv,col){}
queen::queen(int pos_x, int pos_y, int size1, int size2, std::function<void()> fv, bool col) : chessbutton (pos_x, pos_y, size1, size2, fv,col)
{
    K.open(101,101);
    K.transparent(1);
    int r=255;int g=255;int b=255;int w;int h;
    ifstream paraszt;
    if(bw)
    {
    paraszt.open ("king.kep");
    }
    else
    {
    paraszt.open ("king2.kep");
    }    paraszt >> w >> h;
    for(int c=0;c<h;c++)
    {
        for(int d=0;d<w;d++)
        {
            paraszt >> r >> g >> b;
            if(r < 75){if(bw){r=0;g=0;b=0;}}
            K << move_to(d,c)<< color(r,g,b) << dot;
        }
    }
}

void queen::checked(genv::event ev)
{

    gout << stamp(K,x+20,y);
    if((_x < x+unit1 and _x > x and _y< y+unit2 and _y > y and ev.button==-1))
    {f();k=1;}
}
