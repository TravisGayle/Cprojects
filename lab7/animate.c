// A program with a lot of bounce...
// Travis Gayle
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "gfx.h"

int main()
{
  int wd = 500;  // window width
  int ht = 400;  // window height
  int x=gfx_xpos();
  int y=gfx_ypos();
  int a=250;
  int b=20;
  int dx;
  int p=0;
  int dy;
  double dt = 0.01;    // basic increment for animation
  int r = 20;
  char c;
  int i;
  int rbig=120;
  int rsmall=30;
  double ang=0.0;
 int rotate=1;
  
  time_t t;

  srand(time(&t));
  
  dy=(rand()%7)-3;
  dx=(rand()%7)-3;

  gfx_open(wd, ht, "Three Shots at Feve");  // Open a new window for drawing.
  gfx_color(255,0,0);      // Set the current drawing color.

  while(1) { 
		if (x>480){
			x = wd-r;
                        dx=-dx;
                        gfx_color(255,0,0);  // red
                        gfx_clear_color(0,0,0);
                        gfx_clear();
                        }

                if (y>380){
			y = ht -r;
                        dy= -dy;
                        gfx_color(255,255,0); // yellow  
                        gfx_clear_color(255,255,255);
                        gfx_clear();
                        }

                if (x<r){
			x = r;
			dx= -dx;
                        gfx_color(0,0,255); // blue
                        gfx_clear_color(0,0,0);
                        gfx_clear();
                        }
		
                if (y<3*r){
			y = 3*r;
			dy = -dy;
                        gfx_color(0,255,0); // green
                        gfx_clear_color(255,255,255);
                        gfx_clear();

                        // COUNTER FOR GLASSES OF SODA CONSUMED
                    if(x>(0.5*wd)-(3*r) && x<(0.5*wd)+(3*r)){
                       p++;
                        } 


}


 gfx_clear();

if (c==1){

                 // THE 21 YEAR OLD NOTRE DAME PARTY STUDENT
		 gfx_circle(x,y,r);
                 gfx_line(x,y-r,x-r,y);  //square inscribed in circle
                 gfx_line(x-r,y,x,y+r);
                 gfx_line(x,y+r,x+r,y);
                 gfx_line(x+r,y,x,y-r);
                 gfx_circle(x,y,.5*r);  //circle inscribed in square
}


if (c=='d'){
                 if (p>=3){
//DANCE IN A CIRCLE
                 x=wd/2;
                 y=ht/2;
                 gfx_color(0,255,127); // lighter green
                 gfx_circle(rbig*cos(ang)+x,rbig*sin(ang)+y,r);
                 gfx_line(rbig*cos(ang)+x,rbig*sin(ang)+y-r,rbig*cos(ang)+x-r,rbig*sin(ang)+y);  //square inscribed in circle
                 gfx_line(rbig*cos(ang)+x-r,rbig*sin(ang)+y,rbig*cos(ang)+x,rbig*sin(ang)+y+r);
                 gfx_line(rbig*cos(ang)+x,rbig*sin(ang)+y+r,rbig*cos(ang)+x+r,rbig*sin(ang)+y);
                 gfx_line(rbig*cos(ang)+x+r,rbig*sin(ang)+y,rbig*cos(ang)+x,rbig*sin(ang)+y-r);
                 gfx_circle(rbig*cos(ang)+x,rbig*sin(ang)+y,.5*r);  //circle inscribed in square

        ang=ang+.05;

//DANCE IN A small CIRCLE
                 x=3*wd/4;
                 y=3*ht/4;
                 gfx_color(255,128,0); // orange
                 gfx_circle(rsmall*cos(ang)+x,rsmall*sin(ang)+y,r);
                 gfx_line(rsmall*cos(ang)+x,rsmall*sin(ang)+y-r,rsmall*cos(ang)+x-r,rsmall*sin(ang)+y);  //square inscribed in circle
                 gfx_line(rsmall*cos(ang)+x-r,rsmall*sin(ang)+y,rsmall*cos(ang)+x,rsmall*sin(ang)+y+r);
                 gfx_line(rsmall*cos(ang)+x,rsmall*sin(ang)+y+r,rsmall*cos(ang)+x+r,rsmall*sin(ang)+y);
                 gfx_line(rsmall*cos(ang)+x+r,rsmall*sin(ang)+y,rsmall*cos(ang)+x,rsmall*sin(ang)+y-r);
                 gfx_circle(rsmall*cos(ang)+x,rsmall*sin(ang)+y,.5*r);  //circle inscribed in square

        ang=ang+.02;


//DANCE IN A small CIRCLE
                 x=wd/4;
                 y=ht/4;
                 gfx_color(153,51,255); //hot purple
                 gfx_circle(rsmall*cos(ang)+x,rsmall*sin(ang)+y,r);
                 gfx_line(rsmall*cos(ang)+x,rsmall*sin(ang)+y-r,rsmall*cos(ang)+x-r,rsmall*sin(ang)+y);  //square inscribed in circle
                 gfx_line(rsmall*cos(ang)+x-r,rsmall*sin(ang)+y,rsmall*cos(ang)+x,rsmall*sin(ang)+y+r);
                 gfx_line(rsmall*cos(ang)+x,rsmall*sin(ang)+y+r,rsmall*cos(ang)+x+r,rsmall*sin(ang)+y);
                 gfx_line(rsmall*cos(ang)+x+r,rsmall*sin(ang)+y,rsmall*cos(ang)+x,rsmall*sin(ang)+y-r);
                 gfx_circle(rsmall*cos(ang)+x,rsmall*sin(ang)+y,.5*r);  //circle inscribed in square

        ang=ang+.02;


}
                else if (p<3){
		 gfx_circle(x,y,r);
                 gfx_line(x,y-r,x-r,y);  //square inscribed in circle
                 gfx_line(x-r,y,x,y+r);
                 gfx_line(x,y+r,x+r,y);
                 gfx_line(x+r,y,x,y-r);
                 gfx_circle(x,y,.5*r);  //circle inscribed in square
                 }
}

                  // THE BARTENDER
                  gfx_circle(a,b,r);
                  gfx_line(a-.5*r,b-.5*r,a+.5*r,b+.5*r);
                  gfx_line(a-.5*r,b+.5*r,a+.5*r,b-.5*r);

                  // THE BAR
                  gfx_line(0,2*r,wd,2*r); 
                  gfx_line(0.5*wd-3*r,0,0.5*wd-3*r,2*r); 
                  gfx_line(0.5*wd+3*r,0,0.5*wd+3*r,2*r); 
		  gfx_flush();

    usleep(8000);      // pause for 8 milliseconds

    x+=dx;
    y+=dy;
    if(gfx_event_waiting()) {
      c = gfx_wait();
      gfx_flush();

//THE FOLLOWING QUITS
      if (c == 'q')
        { break;}

//THE FOLLOWING LEADS TO MOTION
      if (c==1){
	dx=(rand()%25)-12; //random velocity
	x = gfx_xpos();
	y = gfx_ypos();
        gfx_color(255,255,0);
        gfx_circle(x,y,r);
          gfx_flush();
    
}



}
}      

// STATUS OF STUDENT AFTER DRINKING SODA
if (p<3){
 printf("This student has consumed %d shots of soda \n", p);
 printf("This student is having some fun!\n");}
else if (p>=3){
 printf("This student has consumed %d shots of soda \n", p);
 printf("This student is killing on the dance floor!\n");}
  return 0;

}












































































































