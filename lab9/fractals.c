// recursive function to generate the Sierpinski triangle fractal.
// from main, you would call this function to draw the outer triangle
// NOTE:
// you may only use this code if you fully understand how it works.

#include <stdio.h>
#include <math.h>
#include "gfx3.h"

void sierpinski( int x1, int y1, int x2, int y2, int x3, int y3 );
int mytriangledrawingfunction( int x1, int y1, int x2, int y2, int x3, int y3 );
void shrinksquare(double, double, double, double);
void spiralsquare(double, double, double, double,double,double);
void circlelace(double , double , double );
void snowflake(double , double, double);
void cooltree(double,double,double,double);
void coolfern(double, double,double, double);
void nestedspirals(double, double,double, double);


int main()
{
   double wd = 600, ht = 600, xpos = 150, ypos = 150, xpos2=300, ypos2=300, xpos3=5*xpos2/6, ypos3 = 5*ypos2/6, len=200;
    char c;
    int loop=1;
    int r=150, r0=275;
    double theta=(2*M_PI/180);
   gfx_open(wd, ht, "Fractals");
   while(loop) {
      gfx_text(100, 20, "click anywhere to see fractals; hit 'q' to quit");
      gfx_clear();
    switch(c) {

      case '1':
	sierpinski( wd/2 ,ht,(wd/2)-300, (ht/2)-300, (wd/2)+300,(ht/2)-300 );
    break;
      case '2':
	shrinksquare(xpos, ypos, wd/2, ht/2);
    break;
      case '3':
	spiralsquare(550, 725, wd/5, ht/5,0, r0);
    break;
      case '4':
	circlelace(xpos2, ypos2, 180);
    break;
      case '5':
	snowflake(xpos2,ypos2,len);
    break;
      case '6':
        cooltree(300,600,175,M_PI/2);
    break;
      case '7':
        coolfern(300,600,350,M_PI/2);
    break;
      case '8':
        nestedspirals(850,0,M_PI/2,350);
    break;

     case 'q':                  // quit if 'q' is pressed
        loop = 0;
    
   }
    gfx_flush();                   // flush all output to the window

    c = gfx_wait();              // wait for user input
}

}

//FOR RECURSIVE SIERPINSKI TRIANGLES

void sierpinski( int x1, int y1, int x2, int y2, int x3, int y3 ){

  gfx_line(x1,y1,x2,y2);
  gfx_line(x1,y1,x3,y3);
  gfx_line(x2,y2,x3,y3);


  usleep(100); gfx_flush();

   // Base case. 
   if( abs(x2-x1) < 2 )return;
{mytriangledrawingfunction( x1, y1,  x2,  y2,  x3,  y3 );}

}


   // Draw the triangle
int mytriangledrawingfunction(int x1,int y1, int x2, int y2, int x3, int y3 ){

   // Recursive calls
   sierpinski( x1, y1, (x1+x2)/2, (y1+y2)/2, (x1+x3)/2, (y1+y3)/2 );
   sierpinski( (x1+x2)/2, (y1+y2)/2, x2, y2, (x2+x3)/2, (y2+y3)/2 );
   sierpinski( (x1+x3)/2, (y1+y3)/2, (x2+x3)/2, (y2+y3)/2, x3, y3 );


}

// FOR SHRINKING SQUARES

void shrinksquare(double x0, double y0, double wd, double ht){

  gfx_rectangle(x0,y0,wd,ht);

  usleep(100); gfx_flush();

   //Base case. 
   if( wd < 6.95 )return;

   shrinksquare(x0-wd*.24, y0-ht*.24, wd*.465, ht*.465);
   shrinksquare(x0+wd*.76, y0-ht*.24, wd*.465, ht*.465);
   shrinksquare(x0-wd*.24, y0+ht*.76, wd*.465, ht*.465);
   shrinksquare(x0+wd*.76, y0+ht*.76, wd*.465, ht*.465);
}

// FOR SPIRAL SQUARES

void spiralsquare(double x0, double y0, double wd, double ht,double theta, double r0){
  gfx_rectangle(x0,y0,wd,ht);

  //usleep(100); gfx_flush();

   //Base case. 
   if( r0 < 1 )return;

   spiralsquare(x0-r0*cos(theta),y0-r0*sin(theta), wd*.9, ht*.9, theta+(M_PI/5), r0*.9);
  
}




// FOR CIRCULAR LACE

void circlelace(double xc, double yc, double rc){
double theta=M_PI/3;
  gfx_circle(xc,yc,rc);

  //usleep(100); gfx_flush();

   //Base case. 
   if( rc < 1 )return;

circlelace(xc-rc,yc,rc/3);
circlelace(xc+rc,yc,rc/3);
circlelace(xc-rc*cos(theta),yc-rc*sin(theta),rc/3);
circlelace(xc+rc*cos(theta),yc+rc*sin(theta),rc/3);
circlelace(xc-rc*cos(theta),yc+rc*sin(theta),rc/3);
circlelace(xc+rc*cos(theta),yc-rc*sin(theta),rc/3);

}

// FOR SNOWFLAKE

void snowflake(double x, double y,double len){

double theta=2*M_PI/5;
int i=0, i2=0;

while (i<5){
 gfx_line(x,y,x+len*cos((theta*5/4)+theta*i),y+len*sin((theta*5/4)+theta*i));
i++;
}

   //Base case. 
   if( len<2)return;

while (i2<5){
snowflake(x+len*cos((theta*5/4)+theta*i2),y+len*sin((theta*5/4)+theta*i2),len/3);
i2++;
}

}

//FOR TREE

void cooltree(double x, double y,double len, double theta){

gfx_line(x,y,x-len*cos(theta),y-len*sin(theta));

   //Base case. 
   if( len<1)return;

cooltree(x-len*cos(theta),y-len*sin(theta),len*.65,theta+(M_PI/6));
cooltree(x-len*cos(theta),y-len*sin(theta),len*.65,theta-M_PI/6);

}


// FOR FERN

void coolfern(double x, double y,double len, double theta){

gfx_line(x,y,x-len*cos(theta),y-len*sin(theta));
double dl=.31;
   //Base case. 
   if( len<8)return;

int i=1;
while (i<5){
coolfern(x-len*cos(theta)*.25*i,y-len*sin(theta)*.25*i,len*dl,theta-(M_PI/6));
coolfern(x-len*cos(theta)*.25*i,y-len*sin(theta)*.25*i,len*dl,theta+(M_PI/6));
i++;
}
}

// FOR SPIRAL OF SPIRAL

void nestedspirals(double x0, double y0,double theta, double r0){
  gfx_point((x0+r0*cos(theta)),(y0+r0*sin(theta)));

   //Base case. 
   if( r0 < 1.02 )return;

nestedspirals(x0+r0*cos(theta),y0+r0*sin(theta),theta+(2*M_PI/11),r0*.9);
//nestedspirals(x0-r0*cos(theta),y0-r0*sin(theta),theta+(M_PI/6),r0*.5);
nestedspirals(x0+r0*cos(theta),y0+r0*sin(theta),theta+(2*M_PI/11),r0*.325);


}
