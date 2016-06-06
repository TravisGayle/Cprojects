// symbols.c
// Travis G.
#include <stdio.h>
#include <math.h>
#include "gfx.h"

void draw_poly(int xp, int yp,int r0,int num);
int main()
{
  int wd = 500;  // window width
  int ht = 500;  // window height
  int loop = 1;
  char val;
  int gfx_xpos();
  int gfx_ypos();
  int xp=gfx_xpos();
  int yp=gfx_ypos(); 
  int r=10;

  gfx_open(wd, ht, "Travis Gayle Symbol Program");  // Open a new window for drawing.

  gfx_color(0,0,255);      // Set the current drawing color (blue)

  while(loop) {
    gfx_clear();

    switch(val) {

      case 1:
        xp= gfx_xpos();
        yp= gfx_ypos();
        gfx_color(0,0,255);      // change to blue square if '1' is pressed

        // Draw a blue square on the screen.
        gfx_line(xp-r,yp+r,xp+r,yp+r);
        gfx_line(xp+r,yp-r,xp-r,yp-r);
        gfx_line(xp-r,yp+r,xp-r,yp-r);
        gfx_line(xp+r,yp+r,xp+r,yp-r);

        break;

      case '3':
	gfx_color(76,0,153);	  // changes color to purple
        draw_poly(gfx_xpos(),gfx_ypos() , r, 3);
       
        break;

      case '4':
        gfx_color(76,0,153);	  // changes color to purple
        draw_poly(gfx_xpos(),gfx_ypos() , r, 4);

        break;

      case '5':
        gfx_color(76,0,153);	  // changes color to purple
        draw_poly(gfx_xpos(),gfx_ypos() , r, 5);

        break;

      case '6':
        gfx_color(76,0,153);	  // changes color to purple
        draw_poly(gfx_xpos(),gfx_ypos() , r, 6);

        break;

      case '7':
        gfx_color(76,0,153);	  // changes color to purple
        draw_poly(gfx_xpos(),gfx_ypos() , r, 7);

        break;

      case '8':
        gfx_color(76,0,153);	  // changes color to purple
        draw_poly(gfx_xpos(),gfx_ypos() , r, 8);

        break;

      case '9':
        gfx_color(76,0,153);	  // changes color to purple
	draw_poly(gfx_xpos(),gfx_ypos() , r, 9);

        break;
	
      case 't':

        gfx_color(0,255,0);      // change to green triangle if 't' is pressed    
	
	draw_poly(gfx_xpos(),gfx_ypos() , r, 3);
        //gfx_line(xp-r,yp-r,xp+r,yp-r);
        //gfx_line(xp+r,yp-r,xp,yp);
        //gfx_line(xp,yp,xp-r,yp-r);

        break;

      case 'c':
	xp= gfx_xpos();
        yp= gfx_ypos();	
        gfx_color(255,255,255);      // change to white if 'c' is pressed
        gfx_circle(xp,yp,r);

        break;
    
      case 'q':                  // quit if 'q' is pressed
        loop = 0;
    }

    gfx_flush();                   // flush all output to the window

    val = gfx_wait();              // wait for user input


  }
  return 0;
}



void draw_poly(int xp, int yp,int r,int num){

	int i;
	double theta=(2*M_PI/(num));

	for (i=0; i<num; i++){

	//	gfx_color(76,0,153);      // changes color to purple
	gfx_line(xp+r*cos(i*theta),yp+r*sin(i*theta),xp+r*cos((i+1)*theta),yp+r*sin((i+1)*theta)); 
	}

        }

