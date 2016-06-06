
#include <stdio.h>
#include <math.h>
#include "gfx3.h"

void coolfern(double, double,double, double,int,int,int,double);

int main()
{
char c;
int wd=1350;
int ht=800;
int loop=1;

   gfx_open(wd, ht, "Fern Gallery");
   while(loop) {
      gfx_text(100, 20, "click anywhere to see fractals; hit 'q' to quit");
      gfx_clear();
    switch(c) {
      case '1':
//RED FERN GROWTH
        coolfern(1200,150,300,2*M_PI,255,0,0,.33); 
        coolfern(300,275,150,-M_PI/2,255,0,0,.18); 
        coolfern(450,250,150,-M_PI/3,255,0,0,.27); 
        coolfern(600,225,150,-M_PI/2,255,0,0,.31); 

//GREEN FERN GROWTH
        coolfern(750,225,150,-M_PI/2,0,255,0,.31); 
        coolfern(900,250,150,-M_PI/3+5*M_PI/3,0,255,0,.27); 
        coolfern(1050,275,150,-M_PI/2,0,255,0,.18); 
        coolfern(150,150,300,-M_PI,0,255,0,.33); 

//YELLOW FERN GROWTH
        coolfern(1200,600,300,M_PI/2,255,255,0,.33); 
        coolfern(300,625,150,M_PI/2,255,255,0,.18); 
        coolfern(450,650,150,M_PI/3,255,255,0,.27); 
        coolfern(600,675,150,M_PI/2,255,255,0,.31); 

//BLUE FERN GROWTH
        coolfern(750,675,150,M_PI/2,0,0,255,.31); 
        coolfern(900,650,150,M_PI/3-5*M_PI/3,0,0,255,.27); 
        coolfern(1050,625,150,M_PI/2,0,0,255,.18); 
       coolfern(150,600,300,M_PI/2,0,0,255,.33); 




    break;

      case 'q':                  // quit if 'q' is pressed
        loop = 0;
    
   }
    gfx_flush();                   // flush all output to the window

    c = gfx_wait();              // wait for user input
}
}



// FOR FERN

void coolfern(double x, double y,double len, double theta,int color1, int color2,int color3,double dl){

gfx_color(color1,color2,color3);
gfx_line(x,y,x-len*cos(theta),y-len*sin(theta));
//double dl=.31;
   //Base case. 
   if( len<8)return;

int i=1;
while (i<5){
coolfern(x-len*cos(theta)*.25*i,y-len*sin(theta)*.25*i,len*dl,theta-(M_PI/6),color1,color2,color3,dl);
coolfern(x-len*cos(theta)*.25*i,y-len*sin(theta)*.25*i,len*dl,theta+(M_PI/6),color1,color2,color3,dl);
i++;
}
}
