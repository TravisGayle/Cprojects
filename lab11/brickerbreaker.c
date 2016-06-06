// brick.c
// Author: Sam Mustipher & Travis Gayle
// This program creates the game brick breaker that will have you on the edge of your seat

typedef struct Block_s{
	int xsquare;
	int ysquare;
	int color1;
	int color2;
	int color3;
	int numhits;
}Block;

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include "gfx5.h"
//#include "gfxe.h"

// function prototypes
int isinbounds(double width, double xpos[], double swidth);
void moveslider(double xpos[], double ypos[], double width, double height, double swidth, double sheight, double sdx[], int deltat);
void drawslider(double xpos[], double ypos[], double swidth, double sheight);
int bounce(double width, double height, double xpos[], double ypos[], double velb[], Block specs[], double swidth, double sheight, int *z);
void drawsquares(double xpos[], double ypos[], double velb[], int r, Block specs[]);
int inboard(double ypos[], int sheight, int r);
void blockhit(double xpos[], double ypos[], double velb[], int r, Block specs[]);
void sliderhit(double xpos[], double ypos[], double velb[], double swidth);



int main(int argc, char * argv[]){
	char c='r';
	
	double width = 500;
	double height = 500;
	double middle = width/2;
	double xpos[3] = {0};
	double ypos[3] = {0};
	double sdx[3] = {0}; // every slider will have its own speed
	int r=2;
	gfx_open( 500, 500, "BRICK BREAKER!" );


while(c=='r'){
	// open the main window
	gfx_clear();

	gfx_changefont("lucidasans-24");

	gfx_text( 200, 110, "Welcome " );
	gfx_text( 50, 142, "Are you ready to break bricks?!    " );
	gfx_text( 25, 174, "Please place your cursor on the screen" ); 
		
	// Wait to close
	if(gfx_event_waiting()){
		c=gfx_wait();
	}		

	// Values for the Blocks
	double xsquare,ysquare;
	int numsquares = 50; // 50 squares appear on the screen 
  Block specs[numsquares]; // array of structs 
	specs[0].color1= 255;
	specs[0].color2= 0;	
	specs[0].color3= 51;
	int i;
	// initializes the number of hits
	for(i=0; i<numsquares; i++){
		specs[i].numhits = 0;	
	}
	// initializes the position
	int j,k, index;
	for(j=0;j<5;j++){
		for(k=0;k<10;k++){
			index = 10*j+k;
			specs[index].xsquare = k*50;
			specs[index].ysquare = j*40;
		}
	}

	// initializing values
	int value = 1;
	int deltat = 6000;
	
	// values for the slider
	xpos[0] = middle ;
	ypos[0] = middle+240;
	double swidth = width/10;
	double sheight = 10;
	sdx[0] = 12;

	// values for the ball
	double velb[2];
	velb[0] = 1; // velocity in the x direction
	velb[1] = 1;	// in the y 
	xpos[1] = 300;
	ypos[1] = 300;
  
	
	// initializing the number of lives
	int numlives = 3;
	int *ptr = &numlives; // when passing into the function use *ptr 
	while(numlives>0){
		usleep(deltat);
		gfx_clear();

		// drawing the blocks on the screen
		drawsquares(xpos, ypos, velb,r, specs); 
  
		// draws the slider
		drawslider(xpos, ypos, swidth, sheight);

		// bounces the ball
		bounce(width,height,xpos,ypos, velb, specs, swidth, sheight, &numlives);

		// moves the slider 

		moveslider(xpos,ypos,width,height,swidth,sheight,sdx,deltat); 
		
	}
	
	do{c=gfx_wait();}	
	while(c!='r' && c!='q');


}	
return 0;
}


void moveslider(double xpos[], double ypos[], double width, double height, double swidth, double sheight, double sdx[], int deltat){
	char c; 
	if(gfx_event_waiting()){
		c = gfx_wait();
	}
	if(isinbounds(width, xpos, swidth)){ // checks to see if the slider is in bounds 
		if (c == 83){
			xpos[0] = xpos[0] + sdx[0];
		}
		if (c == 81){
			xpos[0] = xpos[0] - sdx[0];
		}
	}
	else{
		if(xpos[0]<=0){				
				xpos[0] = xpos[0] + sdx[0];
		}
		if(xpos[0]>=width-swidth){
			xpos[0] = xpos[0] - sdx[0];				
		}
	}
	
	drawslider(xpos, ypos, swidth, sheight);
}

void drawslider(double xpos[], double ypos[], double swidth, double sheight){
	gfx_fill_rectangle(xpos[0], ypos[0], swidth, sheight); 
}

int isinbounds(double width, double xpos[0], double swidth){
	int value = 1;
	if( (xpos[0]>=width-swidth) || (xpos[0]<=0) ){
		value = 0;
	}
	return value;
}

int bounce(double width, double height, double xpos[], double ypos[], double velb[], Block specs[], double swidth, double sheight, int *numlives){
	int r = 1;
	int value = 1;
	char life[9];
	//print lives
		if((*numlives)==0){ 
		 gfx_color(255,0,0);
		strcpy(life,"Lives: 0");
		}
		if((*numlives)==1){
		 gfx_color(175,0,0);
		 strcpy(life,"Lives: 1");
		}
		if((*numlives)==2){
		gfx_color(0,175,0);
		 strcpy(life,"Lives: 2");
		}
		if((*numlives)==3){
		 gfx_color(0,255,0);
		 strcpy(life,"Lives: 3");
		}
		gfx_text( 25,400, life); 
	// bound checker for the slider
	gfx_circle(xpos[1], ypos[1], r);
	if ((xpos[1]-r)<=0 || (xpos[1]+r)>=width){
		velb[0] = -velb[0]; //change direction	

	}
	if((ypos[1]-r)<=0){
		velb[1] = -velb[1]; // change direction 
	}

	if((ypos[1] >= height)){
		(*numlives)--;
		if(*numlives==0){
		velb[1] = velb[1];
		gfx_changefont("lucidasans-24");
		gfx_text( 190, 325, "FATALITY! " );
		gfx_text( 75, 350, "Press r to replay or q to quit");
		value = 0;
		}
		else if(*numlives>0){
		velb[1] = -velb[1];
		}

	}

	blockhit(xpos, ypos, velb,r, specs);
	sliderhit(xpos, ypos, velb, swidth);
	xpos[2] = xpos[1]; // stores a copy pf the position
	ypos[2] = ypos[1]; // stores a copy of the y position 
	xpos[1] = xpos[1] + velb[0];
	ypos[1] = ypos[1] + velb[1];
	gfx_circle(xpos[1],ypos[1],r);	
}

void drawsquares(double xpos[], double ypos[], double velb[], int r, Block specs[]){
	int i; // initializing the counters
	gfx_color(specs[0].color1,specs[0].color2,specs[0].color3);
	for(i=0; i<50; i++){
		if(specs[i].numhits>0){
			continue; // won't draw the block
		}
		else{
			gfx_fill_rectangle(specs[i].xsquare, specs[i].ysquare, 25, 10); // 25 is the width of the block, 10 is the height of the block
		}
	}  
}

void sliderhit(double xpos[], double ypos[], double velb[], double swidth){
	if(((xpos[0]+swidth>=xpos[1])&&(xpos[0]<=xpos[1]))&&(ypos[0]<=ypos[1])){
		velb[1] = -velb[1]; 
	}
}

void blockhit(double xpos[], double ypos[], double velb[], int r, Block specs[]){
	int i;
	for(i=0; i<50; i++){
		if(specs[i].numhits==0){
			if((specs[i].xsquare<xpos[1])&&(specs[i].xsquare+25>xpos[1])&&(specs[i].ysquare<ypos[1])&&(specs[i].ysquare+10>ypos[1])){ // checks if the ball was "inside"
				if((specs[i].ysquare>=ypos[2])||(specs[i].ysquare+10<=ypos[2])){ // checks to see which constraint was actually violated 
					velb[1] = -1.03*velb[1];
				}
				if((specs[i].xsquare>=xpos[2])||(specs[i].xsquare+25<=xpos[2])){ 
					velb[0] = -1.03*velb[0];
				}
				specs[i].numhits++;
				//printf("numhits: %d\n", specs[i].numhits++
			}
		}
	}	
}

int inboard(double ypos[], int sheight, int r){
	int value = 1;
	if(ypos[1]>=ypos[0]+sheight){ // if the ypos of the ball is greater than the board+the height of the slider
		value = 0;
	}
	return value;
}


