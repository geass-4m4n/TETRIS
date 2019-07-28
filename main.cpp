#include <SFML/Graphics.hpp>
#include <time.h>
#include <bits/stdc++.h>
using namespace sf;
 using namespace std;
float speed =0.3;
const int M = 20;
const int N = 10;
int field[M][N] = {0};
bool goon =true;
struct Point
{int x,y;} a[4], b[4];

int figures[7][4] =
{
  1,3,5,7, // I
  2,4,5,7, // Z
  3,5,4,6, // S
  3,5,4,7, // T
  2,3,5,7, // L
  3,5,7,6, // J
  2,3,4,5, // O
};
int highscore =0;
bool check()
{
   for (int i=0;i<4;i++)
    if (a[i].x<0 || a[i].x>=N || a[i].y>=M) return 0;
      else if (field[a[i].y][a[i].x]) return 0;

   return 1;
};

int score =0;
int main()
{
    srand(time(0));  

  RenderWindow window(VideoMode(320, 480), "The Game!");
   Font font;
   if(!font.loadFromFile("AllerDisplay.ttf"))
   {
      cout<<"error in font"<<endl;
   }

    Texture t1,t2,t3,t4;
  t1.loadFromFile("images/tiles.png");
  t2.loadFromFile("images/background.png");
  t3.loadFromFile("images/frame.png");
  t4.loadFromFile("images/gameover.png");

  Sprite s(t1), background(t2), frame(t3),gameover(t4);

    int dx=0; bool rotate=0; int colorNum=1;
  float timer=0,delay=speed; 

  colorNum=1+rand()%7;
     int n=rand()%7;
     for (int i=0;i<4;i++)
       {
        a[i].x = figures[n][i] % 2;
        a[i].y = figures[n][i] / 2;
       }

  Clock clock;

    while (window.isOpen())
    {
          if(goon)
          window.draw(background);

    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer+=time;

        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();

      if (e.type == Event::KeyPressed)
        if (e.key.code==Keyboard::Up) rotate=true;
        else if (e.key.code==Keyboard::Left) dx=-1;
        else if (e.key.code==Keyboard::Right) dx=1;
        else if (e.key.code==Keyboard::R)
        {
          for (int i=0;i<M;i++)
          for (int j=0;j<N;j++)
            field[i][j]=0;
          goon =true;
          colorNum=1+rand()%7;
          int n=rand()%7;
          for (int i=0;i<4;i++)
          {
            a[i].x = figures[n][i] % 2;
            a[i].y = figures[n][i] / 2;
          }
          speed=0.3;
          score=0;
        }
        else if (e.key.code==Keyboard::S) 
        {
          if(speed<0.5)
            speed=speed+0.05;
        }
        else if (e.key.code==Keyboard::E) window.close();




    }

  if (Keyboard::isKeyPressed(Keyboard::Down)) delay=0.05;

  //// <- Move -> ///
  for (int i=0;i<4;i++)  { b[i]=a[i]; a[i].x+=dx; }
    if (!check()) for (int i=0;i<4;i++) a[i]=b[i];

  //////Rotate//////
  if (rotate)
    {
    Point p = a[1]; //center of rotation
    for (int i=0;i<4;i++)
      {
      int x = a[i].y-p.y;
      int y = a[i].x-p.x;
      a[i].x = p.x - x;
      a[i].y = p.y + y;
      }
        if (!check()) for (int i=0;i<4;i++) a[i]=b[i];
    }

  ///////Tick//////
  if (timer>delay)
    {
      for (int i=0;i<4;i++) { b[i]=a[i]; a[i].y+=1; }

    if (!check())
    {
     for (int i=0;i<4;i++) field[b[i].y][b[i].x]=colorNum;

     colorNum=1+rand()%7;
     int n=rand()%7;
     for (int i=0;i<4;i++)
       {
        a[i].x = figures[n][i] % 2;
        a[i].y = figures[n][i] / 2;
       }
    }

      timer=0;
    }

  ///////check lines//////////



  int k=M-1;
  for (int i=M-1;i>0;i--)
  {
    int count=0;
    for (int j=0;j<N;j++)
    {
        if (field[i][j]) count++;
        field[k][j]=field[i][j];
    }
    if (count<N) k--;
    else
    {
         score++;
         cout<<"score = "<<score<<endl;
         if(score>highscore)
          highscore=score;
    }
  }
   
   for(int i=0;i<N;i++)
   {
    if(field[0][i])
      {gameover.setPosition(40,50);
       cout<<"ov--er"<<endl;
      window.draw(gameover);
      goon=false;
    }
   }
    dx=0; rotate=0; delay=speed;

    /////////draw//////////
    //window.clear(Color::White); 
      
      if(goon)
  for (int i=0;i<M;i++)
   for (int j=0;j<N;j++)
     {
         if (field[i][j]==0) continue;
     s.setTextureRect(IntRect(field[i][j]*18,0,18,18));
     s.setPosition(j*18,i*18);
     s.move(28,31); //offset
     window.draw(s);
     }


   if(goon)
  for (int i=0;i<4;i++)
    {
    s.setTextureRect(IntRect(colorNum*18,0,18,18));
    s.setPosition(a[i].x*18,a[i].y*18);
    s.move(28,31); //offset
    window.draw(s);
    }
   if(goon)
  window.draw(frame);
  //////////////display score
  stringstream ss,hh;
        ss << score;
    Text text;
    text.setFont(font);
    text.setString( ss.str().c_str() );
    text.setColor(Color :: Red);
    text.setCharacterSize(40);
    text.setPosition(265,80);
    window.draw(text);

    
    text.setFont(font);
    text.setString("SCORE");
    text.setColor(Color :: Red);
    text.setCharacterSize(25);
    text.setPosition(240,55);
    window.draw(text);
   

   text.setFont(font);
    text.setString("  HIGH");
    text.setColor(Color :: Red);
    text.setCharacterSize(25);
    text.setPosition(240,200);
    window.draw(text);


    text.setFont(font);
    text.setString("SCORE");
    text.setColor(Color :: Red);
    text.setCharacterSize(25);
    text.setPosition(240,225);
    window.draw(text);

      hh << highscore;

   
    text.setFont(font);
    text.setString( hh.str().c_str() );
    text.setColor(Color :: Red);
    text.setCharacterSize(40);
    text.setPosition(260,250);
    window.draw(text);

  window.display();
  }

    return 0;
}