
#include <stdio.h>
#include <math.h>


int polar_info(double x, double y, double *r, double *theta){
    *r = sqrt((x*x )+(y*y)); // ponter is being passed in

    *theta = (atan(y/x)*(180/M_PI));
            if(x<0) {
                *theta+=M_PI;
	}

	if(r==0) {
		return 0;
	    }

 if (r>(0)){
           // theta = calcTheta(x,y);

        int polar_info(double x, double y, double *r, double *theta);

        if (*theta>0 && *theta<90){
           return 1; // printf("Your polar coordinates are located in quadrant 1.\n");
        }
	else if  (*theta>270 && *theta<360){
           return 4; // printf("Your polar coordinates are located in quadrant 4.\n");
        }
	else if  (*theta>180 && *theta<270){
           return 3; // printf("Your polar coordinates are located in quadrant 3.\n");
        }
	else if  (*theta>90 && *theta<180){
           return 2; // printf("Your polar coordinates are located in quadrant 2.\n");
        }
	else if  (*theta==0 || *theta==180){
           return -1; // printf("Your polar coordinates lie on the x-axis\n");
        }
         else if  (*theta==90 || *theta==270){
           return -2; // printf("Your polar coordinates lie on the y-axis\n");
        }
    
         else if (*theta>(-360) && *theta<(-270)){
           return 1; // printf("Your polar coordinates are located in quadrant 1.\n");
        }
  	 else if  (*theta<0 && *theta>(-90)){
           return 4; // printf("Your polar coordinates are located in quadrant 4.\n");
        }
	 else if  (*theta>(-180) && *theta<(-90)){
           return 3; // printf("Your polar coordinates are located in quadrant 3.\n");
        }
 	 else if  (*theta>(-270) && *theta<(-180)){
           return 2; // printf("Your polar coordinates are located in quadrant 2.\n");
        }
 	 else if  (*theta==0 || *theta==(-180)){
          return -1; //  printf("Your polar coordinates lie on the x-axis\n");
        }
         else if  (*theta==(-90) || *theta==(-270)){
          return -2;  //  printf("Your polar coordinates lie on the y-axis\n");
        }
	 else if  (*theta==(0)){
          return 0;  //  printf("Your polar coordinates lie on the origin\n");
   	 }
      }
}

