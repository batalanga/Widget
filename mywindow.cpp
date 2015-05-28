#include "mywindow.hpp"

#include "stdfuncbutton.hpp"
#include "gauge.hpp"
#include "checkbox.hpp"
#include "text.hpp"
#include "choose.hpp"
using namespace genv;
using namespace std;

mywindow::mywindow(int width, int height) : window(width, height){
    focus_visible=1;
    D.load_font("FREESCPT.TTF",45);
    D.transparent(1);
    D << move_to(0,0)<<color(255,255,255)<< text("press 'p' to print values");

    dynamic_text *text1= new dynamic_text(100,200,100,30);

    vector <string> start1;start1.push_back("a");start1.push_back("b");
    choose *choose1= new choose(10,300,250,40,start1,4,1);
    choose *choose2= new choose(500,300,160,40,start1,3,1.5);
    vector <string> filler;
    filler.push_back("alma");filler.push_back("körte");filler.push_back("szilva");filler.push_back("barack");
    filler.push_back("cseresznye");filler.push_back("meggy");filler.push_back("szilva");filler.push_back("retek");
    choose2->fill_up(filler);choose1->fill_up(filler);

    stdfuncbutton *Stdfuncbutton= new stdfuncbutton (80,250,[&]()
    {string get=text1->get_text();if(get!=""){choose1->fill_up(get);text1->erase_text();}
    },[](){gout << line(0,-10)<< line(0,20)<< line(0,-10)<< line(-10,0)<< line(20,0)<< line(-10,0);});

    stdfuncbutton *Stdfuncbutton2= new stdfuncbutton (325,270,[&]()
    {string get=choose1->erase_choosen();if(get!=""){choose2->fill_up(get);}
    },[](){gout << line(-10,-10)<< line(10,10)<< line(-10,10);});

    stdfuncbutton *Stdfuncbutton3= new stdfuncbutton (325,330,[&]()
    {string get=choose2->erase_choosen();if(get!=""){choose1->fill_up(get);}
    },[](){gout << line(10,10)<< line(-10,-10)<< line(10,-10);});

    stdfuncbutton *Stdfuncbutton4= new stdfuncbutton (80,350,[&]()
    {choose1->erase_choosen();
    },[](){gout << line(-10,0)<< line(20,0);});

    widgets.push_back(choose1);widgets.push_back(choose2);widgets.push_back(text1);
    widgets.push_back(Stdfuncbutton);widgets.push_back(Stdfuncbutton2);widgets.push_back(Stdfuncbutton3);widgets.push_back(Stdfuncbutton4);
    counter+=3;
    run();
    }
