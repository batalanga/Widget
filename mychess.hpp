#ifndef MYCHESS_HPP_INCLUDED
#define MYCHESS_HPP_INCLUDED
#include "window.hpp"
class mychess : public window{
public:
    mychess(int width, int height);
    void genegrid(genv::canvas & D);
};


#endif // CHESS_HPP_INCLUDED
