#include "mycalcualtor.hpp"

#include "stdfuncbutton.hpp"
#include "gauge.hpp"
#include "checkbox.hpp"
#include "text.hpp"
#include "choose.hpp"

using namespace genv;
using namespace std;

mycalculator::mycalculator(int width, int height) : window(width, height){
    D << move_to(0,0)<< color(100,100,100)<<box(_width,_height);
    gout.load_font("LiberationSans-Regular.ttf",20);
    dynamic_number *text1= new dynamic_number(20,150,250,30);
    ///numbers///
    stdfuncbutton *Stdfuncbutton1= new stdfuncbutton (30,420,50,50,[&](){text1->add_character('1');},[](){gout << text('1');});
    stdfuncbutton *Stdfuncbutton4= new stdfuncbutton (100,420,50,50,[&](){text1->add_character('2');},[](){gout << text('2');});
    stdfuncbutton *Stdfuncbutton5= new stdfuncbutton (170,420,50,50,[&](){text1->add_character('3');},[](){gout << text('3');});
    stdfuncbutton *Stdfuncbutton2= new stdfuncbutton (30,350,50,50,[&](){text1->add_character('4');},[](){gout << text('4');});
    stdfuncbutton *Stdfuncbutton6= new stdfuncbutton (100,350,50,50,[&](){text1->add_character('5');},[](){gout << text('5');});
    stdfuncbutton *Stdfuncbutton8= new stdfuncbutton (170,350,50,50,[&](){text1->add_character('6');},[](){gout << text('6');});
    stdfuncbutton *Stdfuncbutton3= new stdfuncbutton (30,280,50,50,[&](){text1->add_character('7');},[](){gout << text('7');});
    stdfuncbutton *Stdfuncbutton7= new stdfuncbutton (100,280,50,50,[&](){text1->add_character('8');},[](){gout << text('8');});
    stdfuncbutton *Stdfuncbutton9= new stdfuncbutton (170,280,50,50,[&](){text1->add_character('9');},[](){gout << text('9');});
    ///operators///
    stdfuncbutton *Stdfuncbutton10= new stdfuncbutton (240,350,50,50,[&](){text1->add_character('+');},[](){gout << text('+');});
    stdfuncbutton *Stdfuncbutton11= new stdfuncbutton (310,350,50,50,[&](){text1->add_character('-');},[](){gout << text('-');});
    stdfuncbutton *Stdfuncbutton12= new stdfuncbutton (240,280,50,50,[&](){text1->add_character('*');},[](){gout << text('*');});
    stdfuncbutton *Stdfuncbutton13= new stdfuncbutton (310,280,50,50,[&](){text1->add_character('/');},[](){gout << text('/');});
    stdfuncbutton *Stdfuncbutton15= new stdfuncbutton (310,420,50,50,[&](){text1->equial();},[](){gout << text('=');});
    stdfuncbutton *Stdfuncbutton14= new stdfuncbutton (380,280,50,50,[&](){text1->reset_partial();},[](){gout << text('C');});
    stdfuncbutton *Stdfuncbutton16= new stdfuncbutton (240,420,50,50,[&](){text1->add_Ans();},[](){gout <<genv::move(-15,0)<< text("Ans");});



    widgets.push_back(text1);widgets.push_back(Stdfuncbutton1);widgets.push_back(Stdfuncbutton2);widgets.push_back(Stdfuncbutton3);
    widgets.push_back(Stdfuncbutton4);widgets.push_back(Stdfuncbutton5);widgets.push_back(Stdfuncbutton6);widgets.push_back(Stdfuncbutton7);
    widgets.push_back(Stdfuncbutton8);widgets.push_back(Stdfuncbutton9);widgets.push_back(Stdfuncbutton10);widgets.push_back(Stdfuncbutton11);
    widgets.push_back(Stdfuncbutton12);widgets.push_back(Stdfuncbutton13);widgets.push_back(Stdfuncbutton14);widgets.push_back(Stdfuncbutton15);
    widgets.push_back(Stdfuncbutton16);
    run();
}
