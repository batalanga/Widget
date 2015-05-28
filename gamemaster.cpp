#include "gamemaster.h"
#include <iostream>
using namespace genv;
using namespace std;

gamemaster::gamemaster(int pos_x, int pos_y) : widget(pos_x, pos_y){}
gamemaster::gamemaster(int pos_x, int pos_y, int size1, int size2)  : widget(pos_x, pos_y, size1, size2){}



void gamemaster::knowhatistheretokwnow(vector<widget*> & figures)
{
    while(widgets.size()!=0){
    widgets.pop_back();
    }
    widgets.insert(widgets.end(), figures.begin(), figures.end());
    if(havetokill!=33)
    {
        figures[havetokill]->x=800;figures[havetokill]->y=800;
    }
}

unsigned short gamemaster::thereisnothingthere(unsigned int __x, unsigned int __y)
{
        for(size_t c=0;c<widgets.size();c++)
        {
            if(widgets[c]->x==__x and widgets[c]->y==__y)
            {
                return c;
            }
        }
        return 33;

}

void gamemaster::checked(event ev)
{
    cout<<endl;
    havetokill=33;
    if(ev.type == ev_mouse and ev.button==0)
    {
        _x=ev.pos_x;
        _y=ev.pos_y;
    }
//    cout << _pos << endl;
//    if(target!=33){cout << _x << ","<<_y<<" " << widgets[target]->x<<"," << widgets[target]->y<< endl;}
    if(ev.button==1)
    {
        if (target<8)
        {
            if(_y<=widgets[target]->y+200 and _y>widgets[target]->y+100
            and _x<=widgets[target]->x+95 and _x>widgets[target]->x-5
            and 33==thereisnothingthere(widgets[target]->x,widgets[target]->y+100))
            {
                widgets[target]->y+=100;
            }
            if(_y<=widgets[target]->y+200 and _y>widgets[target]->y+100
                and _x<=widgets[target]->x+195 and _x>widgets[target]->x+95)
            {
                size_t temp=thereisnothingthere(widgets[target]->x+100,widgets[target]->y+100);
                if(33!=temp and 15<=temp)
                {
                widgets[target]->y+=100;widgets[target]->x+=100;
                havetokill=temp;
                }

            }
            if( _y<=widgets[target]->y+200 and _y>widgets[target]->y+100
                and _x>=widgets[target]->x-105 and _x<widgets[target]->x-5)
            {
                size_t temp=thereisnothingthere(widgets[target]->x-100,widgets[target]->y+100);
                if(33!=temp and 15<=temp)
                {
                widgets[target]->y+=100;widgets[target]->x-=100;
                havetokill=temp;
                }
            }
        }
        if (target>15 and target < 24)
        {
            if(_y>=widgets[target]->y-100 and _y<widgets[target]->y
            and _x<=widgets[target]->x+95 and _x>widgets[target]->x-5
            and 33==thereisnothingthere(widgets[target]->x,widgets[target]->y-100))
            {
                widgets[target]->y-=100;
            }
            if(_y>=widgets[target]->y-100 and _y<widgets[target]->y
                and _x<=widgets[target]->x+195 and _x>widgets[target]->x+95)
            {
                size_t temp=thereisnothingthere(widgets[target]->x+100,widgets[target]->y-100);
                if(33!=temp and 15>temp)
                {
                widgets[target]->y-=100;widgets[target]->x+=100;
                havetokill=temp;
                }

            }
            if(_y>=widgets[target]->y-100 and _y<widgets[target]->y
                and _x>=widgets[target]->x-105 and _x<widgets[target]->x-5)
            {
                size_t temp=thereisnothingthere(widgets[target]->x-100,widgets[target]->y-100);
                if(33!=temp and 15>temp)
                {
                widgets[target]->y-=100;widgets[target]->x-=100;
                havetokill=temp;
                }
            }
        }
        if (target==8 or target==9 or target==24 or target==25)
        {
            for(unsigned int k=0;k<=700;k+=100)
            {
                size_t temp=thereisnothingthere(widgets[target]->x+100+k,widgets[target]->y+100+k);
                if(_y<=widgets[target]->y+200+k and _y>widgets[target]->y+100+k
                and _x<=widgets[target]->x+195+k and _x>widgets[target]->x+95+k and helper==33)
                {

                    if((15<temp and (target==8 or target==9)) or ((temp<=15 or temp==33) and (target==24 or target==25)))
                    {
                        widgets[target]->y+=k+100;widgets[target]->x+=k+100;
                        if(33!=temp)
                        {
                            havetokill=temp;
                        }
                    }
                }
                helper=temp;

            }
            for(unsigned int k=0;k<=700;k+=100)
            {
                size_t temp=thereisnothingthere(widgets[target]->x-100-k,widgets[target]->y+100+k);
                if(_y<=widgets[target]->y+200+k and _y>widgets[target]->y+100+k
                and _x>=widgets[target]->x-105-k and _x<widgets[target]->x-5-k and helper==33)
                {
                    if((15<temp and (target==8 or target==9)) or ((temp<=15 or temp==33) and (target==24 or target==25)))
                    {
                        widgets[target]->y+=k+100;widgets[target]->x-=k+100;
                        if(33!=temp)
                        {
                            havetokill=temp;
                        }
                    }
                }
                helper=temp;

            }
             for(unsigned int k=0;k<=700;k+=100)
            {
                size_t temp=thereisnothingthere(widgets[target]->x+100+k,widgets[target]->y-100-k);
                if(_y>=widgets[target]->y-100-k and _y<widgets[target]->y-k
                and _x<=widgets[target]->x+195+k and _x>widgets[target]->x+95+k and helper==33)
                {
                    if((15<temp and (target==8 or target==9)) or ((temp<=15 or temp==33) and (target==24 or target==25)))
                    {

                        widgets[target]->y-=k+100;widgets[target]->x+=k+100;
                        if(33!=temp)
                        {
                            havetokill=temp;
                        }
                    }

                }
                helper=temp;

            }
            for(unsigned int k=0;k<=700;k+=100)
            {
                size_t temp=thereisnothingthere(widgets[target]->x-100-k,widgets[target]->y-100-k);
                if(_y>=widgets[target]->y-100-k and _y<widgets[target]->y-k
                and _x>=widgets[target]->x-105-k and _x<widgets[target]->x-5-k and helper==33)
                {
                    if((15<temp and (target==8 or target==9)) or ((temp<=15 or temp==33) and (target==24 or target==25)))
                    {
                        widgets[target]->y-=k+100;widgets[target]->x-=k+100;
                        if(33!=temp)
                        {
                            havetokill=temp;
                        }
                    }
                }
                helper=temp;

            }
        }
        if(target == 12 or target == 13 or target == 28 or target == 29)
        {
            for(unsigned int k=0;k<=700;k+=100)
            {
                size_t temp=thereisnothingthere(widgets[target]->x,widgets[target]->y+100+k);
                if(_y<=widgets[target]->y+200+k and _y>widgets[target]->y+100+k
                and _x<=widgets[target]->x+95 and _x>widgets[target]->x-5 and helper==33)
                {

                    if((15<temp and (target==12 or target==13)) or ((temp<=15 or temp==33) and (target==28 or target==29)))
                    {
                        widgets[target]->y+=k+100;
                        if(33!=temp)
                        {
                            havetokill=temp;
                        }
                    }
                }
                helper=temp;

            }
            for(unsigned int k=0;k<=700;k+=100)
            {
                size_t temp=thereisnothingthere(widgets[target]->x-100-k,widgets[target]->y);
                if(_y<=widgets[target]->y+200 and _y>widgets[target]->y
                and _x>=widgets[target]->x-105-k and _x<widgets[target]->x-5-k and helper==33)
                {
                    if((15<temp and (target==12 or target==13)) or ((temp<=15 or temp==33) and (target==28 or target==29)))
                    {
                        widgets[target]->x-=k+100;
                        if(33!=temp)
                        {
                            havetokill=temp;
                        }
                    }
                }
                helper=temp;

            }
            for(unsigned int k=0;k<=700;k+=100)
            {
                size_t temp=thereisnothingthere(widgets[target]->x,widgets[target]->y-100-k);
                if(_y>=widgets[target]->y-100-k and _y<widgets[target]->y-k
                and _x<=widgets[target]->x+95 and _x>widgets[target]->x-5 and helper==33)
                {
                    if((15<temp and (target==12 or target==13)) or ((temp<=15 or temp==33) and (target==28 or target==29)))
                    {

                        widgets[target]->y-=k+100;
                        if(33!=temp)
                        {
                            havetokill=temp;
                        }
                    }

                }
                helper=temp;

            }
             for(unsigned int k=0;k<=700;k+=100)
            {
                size_t temp=thereisnothingthere(widgets[target]->x+100+k,widgets[target]->y);
                if(_y<=widgets[target]->y+200 and _y>widgets[target]->y
                and _x<=widgets[target]->x+195+k and _x>widgets[target]->x+95+k and helper==33)
                {
                    if((15<temp and (target==12 or target==13)) or ((temp<=15 or temp==33) and (target==28 or target==29)))
                    {
                        widgets[target]->x+=k+100;
                        if(33!=temp)
                        {
                            havetokill=temp;
                        }
                    }

                }
                helper=temp;

            }
        }
        if(target == 30 or target == 14)
        {
             for(unsigned int k=0;k<=700;k+=100)
            {
                size_t temp=thereisnothingthere(widgets[target]->x+100+k,widgets[target]->y+100+k);
                if(_y<=widgets[target]->y+200+k and _y>widgets[target]->y+100+k
                and _x<=widgets[target]->x+195+k and _x>widgets[target]->x+95+k and helper==33)
                {

                    if((15<temp and target==14) or ((temp<=15 or temp==33) and target==30))
                    {
                        widgets[target]->y+=k+100;widgets[target]->x+=k+100;
                        if(33!=temp)
                        {
                            havetokill=temp;
                        }
                    }
                }
                helper=temp;

            }
            for(unsigned int k=0;k<=700;k+=100)
            {
                size_t temp=thereisnothingthere(widgets[target]->x-100-k,widgets[target]->y+100+k);
                if(_y<=widgets[target]->y+200+k and _y>widgets[target]->y+100+k
                and _x>=widgets[target]->x-105-k and _x<widgets[target]->x-5-k and helper==33)
                {
                    if((15<temp and target==14) or ((temp<=15 or temp==33) and target==30))
                    {
                        widgets[target]->y+=k+100;widgets[target]->x-=k+100;
                        if(33!=temp)
                        {
                            havetokill=temp;
                        }
                    }
                }
                helper=temp;

            }
             for(unsigned int k=0;k<=700;k+=100)
            {
                size_t temp=thereisnothingthere(widgets[target]->x+100+k,widgets[target]->y-100-k);
                if(_y>=widgets[target]->y-100-k and _y<widgets[target]->y-k
                and _x<=widgets[target]->x+195+k and _x>widgets[target]->x+95+k and helper==33)
                {
                    if((15<temp and target==14) or ((temp<=15 or temp==33) and target==30))
                    {

                        widgets[target]->y-=k+100;widgets[target]->x+=k+100;
                        if(33!=temp)
                        {
                            havetokill=temp;
                        }
                    }

                }
                helper=temp;

            }
            for(unsigned int k=0;k<=700;k+=100)
            {
                size_t temp=thereisnothingthere(widgets[target]->x-100-k,widgets[target]->y-100-k);
                if(_y>=widgets[target]->y-100-k and _y<widgets[target]->y-k
                and _x>=widgets[target]->x-105-k and _x<widgets[target]->x-5-k and helper==33)
                {
                    if((15<temp and target==14) or ((temp<=15 or temp==33) and target==30))
                    {
                        widgets[target]->y-=k+100;widgets[target]->x-=k+100;
                        if(33!=temp)
                        {
                            havetokill=temp;
                        }
                    }
                }
                helper=temp;

            }

            for(unsigned int k=0;k<=700;k+=100)
            {
                size_t temp=thereisnothingthere(widgets[target]->x,widgets[target]->y+100+k);
                if(_y<=widgets[target]->y+200+k and _y>widgets[target]->y+100+k
                and _x<=widgets[target]->x+95 and _x>widgets[target]->x-5 and helper==33)
                {

                    if((15<temp and target==14) or ((temp<=15 or temp==33) and target==30))
                    {
                        widgets[target]->y+=k+100;
                        if(33!=temp)
                        {
                            havetokill=temp;
                        }
                    }
                }
                helper=temp;

            }
            for(unsigned int k=0;k<=700;k+=100)
            {
                size_t temp=thereisnothingthere(widgets[target]->x-100-k,widgets[target]->y);
                if(_y<=widgets[target]->y+200 and _y>widgets[target]->y
                and _x>=widgets[target]->x-105-k and _x<widgets[target]->x-5-k and helper==33)
                {
                    if((15<temp and target==14) or ((temp<=15 or temp==33) and target==30))
                    {
                        widgets[target]->x-=k+100;
                        if(33!=temp)
                        {
                            havetokill=temp;
                        }
                    }
                }
                helper=temp;

            }
            for(unsigned int k=0;k<=700;k+=100)
            {
                size_t temp=thereisnothingthere(widgets[target]->x,widgets[target]->y-100-k);
                if(_y>=widgets[target]->y-100-k and _y<widgets[target]->y-k
                and _x<=widgets[target]->x+95 and _x>widgets[target]->x-5 and helper==33)
                {
                    if((15<temp and target==14) or ((temp<=15 or temp==33) and target==30))
                    {

                        widgets[target]->y-=k+100;
                        if(33!=temp)
                        {
                            havetokill=temp;
                        }
                    }

                }
                helper=temp;

            }
             for(unsigned int k=0;k<=700;k+=100)
            {
                size_t temp=thereisnothingthere(widgets[target]->x+100+k,widgets[target]->y);
                if(_y<=widgets[target]->y+200 and _y>widgets[target]->y
                and _x<=widgets[target]->x+195+k and _x>widgets[target]->x+95+k and helper==33)
                {
                    if((15<temp and target==14) or ((temp<=15 or temp==33) and target==30))
                    {
                        widgets[target]->x+=k+100;
                        if(33!=temp)
                        {
                            havetokill=temp;
                        }
                    }

                }
                helper=temp;

            }

        }
        if(target == 31 or target == 15)
        {

                if(_y<=widgets[target]->y+200 and _y>widgets[target]->y+100
                and _x<=widgets[target]->x+195 and _x>widgets[target]->x+95 and helper==33)
                {
                    size_t temp=thereisnothingthere(widgets[target]->x+100,widgets[target]->y+100);
                    if((15<temp and target==15) or ((temp<=15 or temp==33) and target==31))
                    {
                        widgets[target]->y+=100;widgets[target]->x+=100;
                        if(33!=temp)
                        {
                            havetokill=temp;
                        }
                    }
                }



                if(_y<=widgets[target]->y+200 and _y>widgets[target]->y+100
                and _x>=widgets[target]->x-105 and _x<widgets[target]->x-5 and helper==33)
                {
                    size_t temp=thereisnothingthere(widgets[target]->x-100,widgets[target]->y+100);
                    if((15<temp and target==15) or ((temp<=15 or temp==33) and target==31))
                    {
                        widgets[target]->y+=100;widgets[target]->x-=100;
                        if(33!=temp)
                        {
                            havetokill=temp;
                        }
                    }
                }



                if(_y>=widgets[target]->y-100 and _y<widgets[target]->y
                and _x<=widgets[target]->x+195 and _x>widgets[target]->x+95 and helper==33)
                {
                    size_t temp=thereisnothingthere(widgets[target]->x+100,widgets[target]->y-100);
                    if((15<temp and target==15) or ((temp<=15 or temp==33) and target==31))
                    {
                        widgets[target]->y-=100;widgets[target]->x+=100;
                        if(33!=temp)
                        {
                            havetokill=temp;
                        }
                    }

                }



                if(_y>=widgets[target]->y-100 and _y<widgets[target]->y
                and _x>=widgets[target]->x-105 and _x<widgets[target]->x-5 and helper==33)
                {
                    size_t temp=thereisnothingthere(widgets[target]->x-100,widgets[target]->y-100);
                    if((15<temp and target==15) or ((temp<=15 or temp==33) and target==31))
                    {
                        widgets[target]->y-=100;widgets[target]->x-=100;
                        if(33!=temp)
                        {
                            havetokill=temp;
                        }
                    }
                }





                if(_y<=widgets[target]->y+200 and _y>widgets[target]->y+100
                and _x<=widgets[target]->x+95 and _x>widgets[target]->x-5 and helper==33)
                {
                    size_t temp=thereisnothingthere(widgets[target]->x,widgets[target]->y+100);
                    if((15<temp and target==15) or ((temp<=15 or temp==33) and target==31))
                    {
                        widgets[target]->y+=100;
                        if(33!=temp)
                        {
                            havetokill=temp;
                        }
                    }
                }




                if(_y<=widgets[target]->y+200 and _y>widgets[target]->y
                and _x>=widgets[target]->x-105 and _x<widgets[target]->x-5 and helper==33)
                {
                    size_t temp=thereisnothingthere(widgets[target]->x-100,widgets[target]->y);
                    if((15<temp and target==15) or ((temp<=15 or temp==33) and target==31))
                    {
                        widgets[target]->x-=100;
                        if(33!=temp)
                        {
                            havetokill=temp;
                        }
                    }
                }




                if(_y>=widgets[target]->y-100 and _y<widgets[target]->y
                and _x<=widgets[target]->x+95 and _x>widgets[target]->x-5 and helper==33)
                {
                    size_t temp=thereisnothingthere(widgets[target]->x,widgets[target]->y-100);
                    if((15<temp and target==15) or ((temp<=15 or temp==33) and target==31))
                    {

                        widgets[target]->y-=100;
                        if(33!=temp)
                        {
                            havetokill=temp;
                        }
                    }

                }




                if(_y<=widgets[target]->y+200 and _y>widgets[target]->y
                and _x<=widgets[target]->x+195 and _x>widgets[target]->x+95 and helper==33)
                {
                    size_t temp=thereisnothingthere(widgets[target]->x+100,widgets[target]->y);
                    if((15<temp and target==15) or ((temp<=15 or temp==33) and target==31))
                    {
                        widgets[target]->x+=100;
                        if(33!=temp)
                        {
                            havetokill=temp;
                        }
                    }

                }



        }
    }

}
