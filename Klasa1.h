//
// Created by jakub on 29.10.2019.
//

#ifndef PROJEKT_APLIKACJE_KLASA1_H
#define PROJEKT_APLIKACJE_KLASA1_H
#include <iostream>
#include<fstream>
#include<conio.h>
#include<cmath>
#include<cstdlib>
#include<string.h>
#include<ctime>
#include<SFML/Graphics.hpp>
#include<windows.h>

using namespace std;
enum eKier{STOP=0,LEWO=1,GLEWO=2,DLEWO=3,PRAWO=4,GPRAWO=5,DPRAWO=6};
class cBall
{
private:
    int x,y;
    int pierwszyX,pierwszyY;
    eKier kierunek;
public:
    cBall(int pozX,int pozY)
    {
        pierwszyX=pozX;
        pierwszyY=pozY;
        x=pozX;
        y=pozY;
        kierunek=STOP;
    }
    void Reset()
    {
        x=pierwszyX;
        y=pierwszyY;
        kierunek=STOP;
    }
    void zmienkier(eKier k)
    {
        kierunek = k;
    }

    void loskier()
    {
        kierunek =(eKier((rand()%6)+1));
    }
    inline int getX(){return x;}
    inline int getY(){return y;}
    inline eKier getkierunek(){return kierunek;}
    void ruchball()
    {
        switch(kierunek)
        {
            case STOP:
                break;
            case LEWO:
                x=x-10;
                y=y+0;
                break;
            case PRAWO:
                x=x+10;
                y=y+0;
                break;
            case GLEWO:
                x=x-10;
                y=y-10;
                break;
            case DLEWO:
                x=x-10;
                y=y+10;
                break;
            case GPRAWO:
                x=x+10;
                y=y-10;
                break;
            case DPRAWO:
                x=x+10;
                y=y+10;
                break;
            default:
                break;
        }
    }

    friend ostream & operator<<(ostream & o,cBall c)
    {
        o<<"Pilka ["<<c.x<<" , "<<c.y<<" ][ "<< c.kierunek<<" ]"<<endl;
        return o;
    }
};
class cPaletka
{
private:
    int x,y;
    int pierwszyX,pierwszyY;
public:
    cPaletka()
    {
        x=y=0;
    }
    cPaletka(int pozX,int pozY):cPaletka()
    {
        pierwszyX=pozX;
        pierwszyY=pozY;
        x=pozX;
        y=pozY;
    }
    inline void Reset(){x=pierwszyX;  y=pierwszyY;}
    inline int getX(){return x;}
    inline int getY(){return y;}
    inline void RuchG(){y = y-50;}
    inline void RuchD(){y = y+50;}
    friend ostream & operator<<(ostream & o,cPaletka c)
    {
        o<<"Paletka ["<<c.x<<" , "<<c.y<<" ]"<<endl;
        return o;
    }
};


#endif //PROJEKT_APLIKACJE_KLASA1_H
