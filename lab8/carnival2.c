// A program with a lot of bounce...
// Travis Gayle
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "gfx3.h"

int getspheres(int smallr,int smallr2, int smallr3, int x, int y,double ang2, int a, int b, int c);

int main()
{
  int wd = 700;  // window width
  int ht = 700;  // window height
  int x=gfx_xpos();
  int y=gfx_ypos();
  int dx;
  int dy;
  double ang=0.0;
  double ang2=0.0;
  double dt = 0.1;    // basic increment for animation
  int r = 50; 
  int r2 =20;
  int r3=120;
  int smallr=20;
  int smallr2=8;
  int smallr3=48;
 
  char c;
  int i;
  
  time_t t;

  srand(time(&t));
  
  dy=(rand()%3)-1;
  dx=(rand()%9)-4;

  gfx_open(wd, ht, "Travis's Carnival Ride");  // Open a new window for drawing.
  
  gfx_color(255,255,255);      // Set the current drawing color.

  while(1) { 

    
		if (x>650){
			x = wd-r;
                        dx=-dx;
                        }

                if (y>650){
			y = ht -r;
                        dy= -dy;
                        }

                if (x<50){
			x = r;
			dx= -dx;
                        }
		
                if (y<50){
			y = r;
			dy = -dy;
                        }


		gfx_clear();
		
// LOWER PLATFORM
		gfx_color(0,0,255); //blue lines 
		gfx_line(500,450,x+r3*cos(ang)+r2,100+y+r3*sin(ang));
		gfx_line(200,450,x+r3*cos(ang)-r2,100+y+r3*sin(ang));
		gfx_ellipse(r3*cos(ang)+ x,100+r3*sin(ang)+y,r*.45, r2*.45 );
		gfx_color(255,0,0); //red lines		
		gfx_line(500,450,x+smallr3*cos(ang2)+smallr2,100+y+smallr3*sin(ang2));
		gfx_line(200,450,x+smallr3*cos(ang2)-smallr2,100+y+smallr3*sin(ang2));
		gfx_ellipse(smallr3*cos(ang2)+ x,100+smallr3*sin(ang2)+y, smallr*.45, smallr2*.45 );

gfx_color(255,255,255); //white


 //lines connecting two platforms
gfx_line(500,450,700,350);
gfx_line(200,450,0,350);
gfx_line(smallr3*cos(ang2)+x,smallr3*sin(ang2)+y+smallr, x+smallr3*cos(ang2),100+y+smallr3*sin(ang2));
gfx_line(r3*cos(ang)+x,r3*sin(ang)+y+r, x+r3*cos(ang),100+y+r3*sin(ang));

//CREATE BIG SPHERE AND ROPES

getspheres(r,r2, r3, x, y, ang, 0, 0, 255);
ang=ang+0.03;

//CREATE SMALL SPHERE AND ROPES
getspheres(smallr,smallr2, smallr3, x, y, ang2, 255, 0, 0);
ang2=ang2-0.03;

gfx_color(0,0,255);
gfx_text(175,40, "THE GREAT AMERICAN SPHERE RIDE:");		
gfx_color(255,0,0);
gfx_text(200,60, "A GAYLE CLASSIC");
gfx_flush();

    usleep(8000);      // pause for 8 milliseconds
    x=350;
    y=350;
    if(gfx_event_waiting()) {
      c = gfx_wait();
      gfx_flush();
      if (c == 'q') { break;}
      if (c==1){

        gfx_flush();

}
}
}      
  return 0;

}

//FUNCTION FOR GETTING SPHERES WITH ATTACHED WIRES
//smallr is the circle radius, smallr2 is the elipse shorter radius, smallr3 is the radius of rotation, x and y are position of ball, ang2 is the angle at which ball rotates, and (a,b,c) represents the sphere color

		int getspheres(int smallr,int smallr2, int smallr3, int x, int y,double ang2, int a, int b, int c){
		gfx_color(a,b,c); //red sphere
		gfx_circle(smallr3*cos(ang2)+x,smallr3*sin(ang2)+y,smallr);
		gfx_ellipse(smallr3*cos(ang2)+ x, smallr3*sin(ang2)+y, smallr, smallr2 );
		gfx_color(255,255,255); //white platform 
		gfx_line(700,350,x+smallr+smallr3*cos(ang2),y+smallr3*sin(ang2));
		gfx_line(0,350,x-smallr+smallr3*cos(ang2),y+smallr3*sin(ang2));
		gfx_flush();

ang2=ang2-0.03;
		}



