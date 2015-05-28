#ifndef TEXT_HPP_INCLUDED
#define TEXT_HPP_INCLUDED
#include "widget.hpp"
#include <functional>

struct openuber
{
    std::function<double(double, double)> op;
    double num;
};

class dynamic_text: public widget
{
protected:
    int time=0;
    int time2=0;
    bool backspace=0;
    bool good=0;
    unsigned short counter=0;
    unsigned int letter=0;
    std::string letters;
public:
    dynamic_text(int pos_x, int pos_y);
    dynamic_text(int pos_x, int pos_y, int size1, int size2);
    void checked(genv::event ev);
    std::string get_text();
    void erase_text();
};

class dynamic_number: public dynamic_text
{
private:
    std::string done2="0";
    double Ans=0;
    void find_prior(std::vector<std::function<double(double, double)> > &operation, std::vector<double> &n, std::vector<bool> &prior);
    void find_prior(std::vector<openuber> all);
public:
    dynamic_number(int pos_x, int pos_y);
    dynamic_number(int pos_x, int pos_y, int size1, int size2);
    void add_character( char character);
    void reset_partial(){done2="0";Ans=0;}
    void add_Ans();
    void equial();
    virtual void checked(genv::event ev);
};

class static_text: public widget
{
protected:
    std::string text_out="sample";
public:
    static_text(int pos_x, int pos_y);
    static_text(int pos_x, int pos_y, int size1, int size2);
    void fill_up(std::string text){text_out=text;}
    virtual void checked(genv::event ev);
};

#endif // TEXT_HPP_INCLUDED
