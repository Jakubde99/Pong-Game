#include "Klasa1.h"

class RenderWindow;

using namespace std;
int main()
{

    sf::RenderWindow okno ( sf::VideoMode(1000, 600, 32 ), "249575 - pong" );
    sf::Texture tekstura1;
    sf::Texture tekstura2;
    sf::Texture tekstura3;
    sf::Texture tekstura4;
    tekstura1.loadFromFile( "sprites1.png" );
    tekstura2.loadFromFile( "sprites2.png" );
    tekstura3.loadFromFile( "sprites3.png" );
    tekstura4.loadFromFile( "sprites4.png" );
    sf::Sprite Tytul;
    sf::Sprite player1;
    sf::Sprite player2;
    sf::Sprite ball;
    player1.setTexture( tekstura1 );
    player2.setTexture( tekstura2 );
    ball.setTexture( tekstura3 );
    cBall c(500,300);
    cPaletka p1(0,300);
    cPaletka p2(960,300);
    player1.setPosition( p1.getX(), p1.getY()  );
    player2.setPosition(p2.getX(), p2.getY()  );
    ball.setPosition(c.getX(),c.getY());
    int wynik1 = 0,wynik2 = 0;
    c.loskier();
    while( okno.isOpen() )
    {
        _sleep(20);
        sf::Event zdarzenie;
        while( okno.pollEvent( zdarzenie ))
        {
//switch case
            switch(zdarzenie.type) {
                case (sf::Event::Closed):
                    okno.close();

                case (sf::Event::KeyPressed): {
                    switch (zdarzenie.key.code) {
                        case (sf::Keyboard::O): {
                            cBall c(500, 300);
                            cPaletka p1(0, 300);
                            cPaletka p2(960, 300);
                            player1.setPosition(p1.getX(), p1.getY());
                            player2.setPosition(p2.getX(), p2.getY());
                            ball.setPosition(c.getX(), c.getY());
                            //int wynik1 = 0,wynik2 = 0;
                            wynik1 = wynik2 = 0;
                        }

                        case (sf::Keyboard::Escape):
                            okno.close();

                        case (sf::Keyboard::Up): {
                            if( p2.getY()>0) {
                                p2.RuchG();
                                player2.move(0, -50);
                            }
                            break;

                        };

                        case (sf::Keyboard::Down): {
                            if(p2.getY() < 500) {
                                p2.RuchD();
                                player2.move(0, 50);
                            }
                            break;
                        };
                        case (sf::Keyboard::W): {
                            if(p1.getY() > 0) {
                                p1.RuchG();
                                player1.move(0, -50);
                            }
                            break;
                        };

                        case (sf::Keyboard::S): {
                            if(  p1.getY() < 500) {
                                p1.RuchD();
                                player1.move(0, 50);
                            }
                            break;
                        }

                    }
                }
            }
                //stary fragm.
            /*
                while ( zdarzenie.type == sf::Event::Closed )
                okno.close();
            while ( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape )
                okno.close();
           // while ( zdarzenie.type == sf::Event::MouseButtonPressed && zdarzenie.mouseButton.button == sf::Mouse::Middle )
             //   okno.close();
            while ( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Up && p2.getY()>0)
            {
                p2.RuchG();
                player2.move(0,-50);
                break;
            }
            while ( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Down && p2.getY()<500)
            {
                p2.RuchD();
                player2.move(0,50);
                break;
            }
            while ( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::W && p1.getY()>0)
            {
                p1.RuchG();
                player1.move(0,-50);
                break;
            }
            while ( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::S&& p1.getY()<500 )
            {
                p1.RuchD();
                player1.move(0,50);
                break;
            }*/


            }

        for(int i=0;i<120;i++)                          //odbicie od paletkki 1
            if(c.getX()==p1.getX()+20)
                if(c.getY()==p1.getY()+i)
                    c.zmienkier((eKier) (rand()%3 +4));
        for(int i=0;i<120;i++)                          //odbicie od paletki 2
            if(c.getX()==p2.getX()-30)
                if(c.getY()==p2.getY()+i)
                    c.zmienkier((eKier) (rand()%3 +1));
        if(c.getY()>=550)                               //odbicie od scianki dolnej
        {
            if(c.getkierunek()==DPRAWO)
                c.zmienkier(GPRAWO);
            else c.zmienkier(GLEWO);
        }
        if(c.getY()<=0)                                 //odbicie od scianki gornej
        {
            if(c.getkierunek()==GPRAWO)
                c.zmienkier(DPRAWO);
            else c.zmienkier(DLEWO);
        }
        if(c.getX()>=980)                               //punkt gracz 1
        {
            wynik1++;
            c.Reset();
            c.loskier();
            p1.Reset();
            p2.Reset();

            player1.setPosition( p1.getX(), p1.getY()  );
            player2.setPosition(p2.getX(), p2.getY()  );
            ball.setPosition(c.getX(),c.getY());
        }
        if(c.getX()<0)                                  //punkt gracz 2
        {
            wynik2++;
            c.Reset();
            c.loskier();
            p1.Reset();
            p2.Reset();

            player1.setPosition( p1.getX(), p1.getY()  );
            player2.setPosition(p2.getX(), p2.getY()  );
            ball.setPosition(c.getX(),c.getY());
            //cout<<wynik1<<"  WYNIK  "<<wynik2<<endl;
            //cout<<c.getX()<<"     "<<c.getY()<<endl;
            cout<<ball.getPosition().x<<" pilka "<<ball.getPosition().y<<endl<<endl;

            //cout<<player2.getPosition().x<<" gr2 "<<player2.getPosition().y<<endl;
            //cout<<p2.getX()<<" gracz2 "<<p2.getY()<<endl<<endl;
            //cout<<player1.getPosition().x<<" gr1 "<<player1.getPosition().y<<endl;
            //cout<<p1.getX()<<" gracz1 "<<p1.getY()<<endl<<endl;

        }

        c.ruchball();
        ball.setPosition(c.getX(),c.getY());

        okno.clear( sf::Color::Black );
        okno.draw( player1 );
        okno.draw( player2 );
        okno.draw( ball );
        okno.display();
    }

    return 0;
}
