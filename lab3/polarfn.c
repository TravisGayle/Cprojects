// CALLING THE FUNCTIONS

#include <math.h>

double calcRadius(float x, float y){
    double r = sqrt((x*x )+(y*y));
    return r;
}
double calcTheta(float x, float y){
    double theta = (atan(y/x));
            if(x<0) {
                theta+=M_PI;
            }
    return theta;
}



