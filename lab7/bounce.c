// A program with a lot of bounce...
// Travis Gayle
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "gfx.h"

int main()
{
  int wd = 500;  // window width
  int ht = 400;  // window height
  int x=gfx_xpos();
  int y=gfx_ypos();
  int dx;
  int dy;
  double dt = 0.01;    // basic increment for animation
  int r = 20;
  char c;
  int i;
  
  time_t t;

  srand(time(&t));
  
  dy=(rand()%9)-4;
  dx=(rand()%9)-4;

  gfx_open(wd, ht, "Travis's Bounce Ball");  // Open a new window for drawing.

  gfx_color(255,0,0);      // Set the current drawing color.

  while(1) { 
    
		if (x>480){
			x = wd-r;
                        dx=-dx;
                        }

                if (y>380){
			y = ht -r;
                        dy= -dy;
                        }

                if (x<20){
			x = r;
			dx= -dx;
                        }
		
                if (y<20){
			y = r;
			dy = -dy;
                        }


		gfx_clear();
		gfx_circle(x,y,r);
		gfx_flush();

    usleep(8000);      // pause for 8 milliseconds
    x+=dx;
    y+=dy;
    if(gfx_event_waiting()) {
      c = gfx_wait();
      gfx_flush();
      if (c == 'q') { break;}
      if (c==1){
	dx=(rand()%25)-12; //random velocity
	x = gfx_xpos();
	y = gfx_ypos();
        gfx_circle(x,y,r);
        gfx_flush();

}
}
}      
  return 0;

}


