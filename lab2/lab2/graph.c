#include <stdio.h>
#include <math.h>

int main (void)
{

printf("GRAPH OF y = sin(x)+2*cos(x) from x=0 to x=20.\n");
printf(" X	Y\n");

float x;
float y;
int z;
float min = sin(0) + 2*cos(0);
float max = sin(0) + 2*cos(20);
for (x=0.0;x <= 20; x = x+0.2 ){
    y = sin(x)+2*cos(x);
    printf("%5.2f	%5.2f",x,y);
    if (max <y){
        max=y;
    }
    if (min > y){
        min=y;
    }
    for (z=1; z <=y; z = z++){
       printf("#");
}
printf("The maximum value is %.2f and the minimum is %.2f.\n", max, min);
return 0;

}}
