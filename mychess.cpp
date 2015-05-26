#include "mychess.hpp"
#include "pawn.h"
#include "queen.h"
#include "king.h"
#include "rook.h"
#include "bishop.h"
#include "knight.h"

#include "gamemaster.h"

using namespace genv;
using namespace std;

void mychess::genegrid(canvas & D)
{
    for(int e=0;e<800;e+=200)
    {
        for(int d=0;d<800;d+=200)
        {
            D << move_to(d,e) << color(255,255,255) << box(100,100);
        }
    }
    for(int e=100;e<800;e+=200)
    {
        for(int d=100;d<800;d+=200)
        {
            D << move_to(d,e) << color(255,255,255) << box(100,100);
        }
    }

}

mychess::mychess(int width, int height) : window(width, height){

    focus_visible=0;
    D.load_font("FREESCPT.TTF",45);
    D.transparent(1);
    genegrid(D);
    gamemaster * BigMasta = new gamemaster(800,800,0,0);
                ///black///
    chessbutton * pawn_1 = new pawn(5,100,90,100,[&](){BigMasta->get_target(0);},0);
    chessbutton * pawn_2 = new pawn(105,100,90,100,[&](){BigMasta->get_target(1);},0);
    chessbutton * pawn_3 = new pawn(205,100,90,100,[&](){BigMasta->get_target(2);},0);
    chessbutton * pawn_4 = new pawn(305,100,90,100,[&](){BigMasta->get_target(3);},0);
    chessbutton * pawn_5 = new pawn(405,100,90,100,[&](){BigMasta->get_target(4);},0);
    chessbutton * pawn_6 = new pawn(505,100,90,100,[&](){BigMasta->get_target(5);},0);
    chessbutton * pawn_7 = new pawn(605,100,90,100,[&](){BigMasta->get_target(6);},0);
    chessbutton * pawn_8 = new pawn(705,100,90,100,[&](){BigMasta->get_target(7);},0);
    chessbutton * bishop_1 = new bishop(205,0,90,100,[&](){BigMasta->get_target(8);},0);
    chessbutton * bishop_2 = new bishop(505,0,90,100,[&](){BigMasta->get_target(9);},0);
    chessbutton * knight_1 = new knight(105,0,90,100,[&](){BigMasta->get_target(10);},0);
    chessbutton * knight_2 = new knight(605,0,90,100,[&](){BigMasta->get_target(11);},0);
    chessbutton * rook_1 = new rook(5,0,90,100,[&](){BigMasta->get_target(12);},0);
    chessbutton * rook_2 = new rook(705,0,90,100,[&](){BigMasta->get_target(13);},0);
    chessbutton * queen_ = new queen(305,0,90,100,[&](){BigMasta->get_target(14);},0);
    chessbutton * king_ = new king(405,0,90,100,[&](){BigMasta->get_target(15);},0);
                ///white///
    chessbutton * pawn_1_b = new pawn(5,600,90,100,[&](){BigMasta->get_target(16);},1);
    chessbutton * pawn_2_b = new pawn(105,600,90,100,[&](){BigMasta->get_target(17);},1);
    chessbutton * pawn_3_b = new pawn(205,600,90,100,[&](){BigMasta->get_target(18);},1);
    chessbutton * pawn_4_b = new pawn(305,600,90,100,[&](){BigMasta->get_target(19);},1);
    chessbutton * pawn_5_b = new pawn(405,600,90,100,[&](){BigMasta->get_target(20);},1);
    chessbutton * pawn_6_b = new pawn(505,600,90,100,[&](){BigMasta->get_target(21);},1);
    chessbutton * pawn_7_b = new pawn(605,600,90,100,[&](){BigMasta->get_target(22);},1);
    chessbutton * pawn_8_b = new pawn(705,600,90,100,[&](){BigMasta->get_target(23);},1);
    chessbutton * bishop_1_b = new bishop(205,700,90,100,[&](){BigMasta->get_target(24);},1);
    chessbutton * bishop_2_b = new bishop(505,700,90,100,[&](){BigMasta->get_target(25);},1);
    chessbutton * knight_1_b = new knight(105,700,90,100,[&](){BigMasta->get_target(26);},1);
    chessbutton * knight_2_b = new knight(605,700,90,100,[&](){BigMasta->get_target(27);},1);
    chessbutton * rook_1_b = new rook(5,700,90,100,[&](){BigMasta->get_target(28);},1);
    chessbutton * rook_2_b = new rook(705,700,90,100,[&](){BigMasta->get_target(29);},1);
    chessbutton * queen_b = new queen(305,700,90,100,[&](){BigMasta->get_target(30);},1);
    chessbutton * king_b = new king(405,700,90,100,[&](){BigMasta->get_target(31);},1);



    widgets.push_back(pawn_1);widgets.push_back(pawn_2);widgets.push_back(pawn_3);widgets.push_back(pawn_4);widgets.push_back(pawn_5);
    widgets.push_back(pawn_6);widgets.push_back(pawn_7);widgets.push_back(pawn_8);widgets.push_back(bishop_1);widgets.push_back(bishop_2);
    widgets.push_back(knight_1);widgets.push_back(knight_2);widgets.push_back(rook_1);widgets.push_back(rook_2);
    widgets.push_back(queen_);widgets.push_back(king_);
    widgets.push_back(pawn_1_b);widgets.push_back(pawn_2_b);widgets.push_back(pawn_3_b);widgets.push_back(pawn_4_b);widgets.push_back(pawn_5_b);
    widgets.push_back(pawn_6_b);widgets.push_back(pawn_7_b);widgets.push_back(pawn_8_b);widgets.push_back(bishop_1_b);widgets.push_back(bishop_2_b);
    widgets.push_back(knight_1_b);widgets.push_back(knight_2_b);widgets.push_back(rook_1_b);widgets.push_back(rook_2_b);
    widgets.push_back(queen_b);widgets.push_back(king_b);Masta =BigMasta;
    counter+=32;
    run();
}
