#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "gfx.h"


void makemaze(double x, double y,double len, double theta);

int main()
{
double wd = 300, ht = 300;
char c;
int loop=1;
   gfx_open(wd, ht, "A-maze-ing");
      while(loop) {
            gfx_text(100, 20, "click anywhere to see fractals; hit 'q'to quit");
      gfx_clear();
      switch(c) {
                   case '1':
                   makemaze(wd/2,ht,20,M_PI/2);
                        break;
                   case 'q':                  // quit if 'q' is pressed
        loop = 0;
               }
                   gfx_flush();                   // flush all output to the window
                   
                   c = gfx_wait();              // wait for user input
               }             
}

void makemaze(double x, double y,double len, double theta){

gfx_line(x,y,x-len*cos(theta),y-len*sin(theta));

    time_t t;
    srand(time(&t));

//int randx=(rand()%3)-2;
//int randy=(rand()%3)-2;

if(x<20 )return;

makemaze(x-len*cos(theta)+(theta),y-len*sin(theta)+(theta),len,theta+(theta));

}

