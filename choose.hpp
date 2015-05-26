#ifndef CHOOSE_HPP_INCLUDED
#define CHOOSE_HPP_INCLUDED
#include "widget.hpp"
struct choose : public widget
{
private:
    std::vector <std::string> pieces;
    bool active=0;
    bool lshift=0;
    unsigned int counter=0;
    unsigned int choosenn=0;
    unsigned int serial,c_p;
    double wmp;
    std::string choosen="";
public:
    choose(int pos_x, int pos_y);
    choose(int pos_x, int pos_y,std::string start);
    choose(int pos_x, int pos_y,std::vector <std::string> start);
    choose(int pos_x, int pos_y, int size1, int size2,std::vector <std::string> start,int choosable_piecenumber,double width_multiplier);
    virtual void checked(genv::event ev);
    void fill_up(std::vector<std::string> data);
    void fill_up(std::string data);
    std::string erase_choosen();
};



#endif // CHOOSE_HPP_INCLUDED
