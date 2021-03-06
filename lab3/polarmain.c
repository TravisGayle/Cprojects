
#include <stdio.h>
#include <math.h>


int main()

{
float x,y;
double r, theta, degtheta;


    printf("Enter a value for x and y respectively: \n"); //requests an x & y v$
    scanf("%f%f", &x, &y);

    r = calcRadius(x,y);  //this function takes two arguments, x & y, and calcu$

    if(x==0) {
	printf("you're on the y axis\n");
        return 0;
    }

    if (r>(0)){
            theta = calcTheta(x,y);

            degtheta= (theta/(2*M_PI))*360; //conversion to radians
            if(degtheta < 0) {
                degtheta = 360+degtheta;
            }
            printf("Your polar coordinates are %lf , %lf\n", r, theta);
        if (degtheta>0 && degtheta<90){
            printf("Your polar coordinates are located in quadrant 1.\n");
        }
	else if  (degtheta>270 && degtheta<360){
            printf("Your polar coordinates are located in quadrant 4.\n");
        }
	else if  (degtheta>180 && degtheta<270){
            printf("Your polar coordinates are located in quadrant 3.\n");
        }
	else if  (degtheta>90 && degtheta<180){
            printf("Your polar coordinates are located in quadrant 2.\n");
        }
	else if  (degtheta==0 || degtheta==180){
            printf("Your polar coordinates lie on the x-axis\n");
        }
         else if  (degtheta==90 || degtheta==270){
            printf("Your polar coordinates lie on the y-axis\n");
        }
    }
    else {
	printf("You are at the origin. Try another set of coordinates.\n");
    }
}
