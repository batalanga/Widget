#ifndef WINDOW_HPP_INCLUDED
#define WINDOW_HPP_INCLUDED
#include "widget.hpp"
#include "gamemaster.h"
class window{
protected:
    genv::canvas D;
    unsigned int counter=0;
    bool focus_visible=0;
    int tab = 0;
    int _width=0;
    int _height=0;
    std::vector <widget *> widgets;
    gamemaster * Masta;
    window(int width, int height);
    window();
public:
    void run();
};



#endif // WINDOW_HPP_INCLUDED
