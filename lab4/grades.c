#include <stdio.h>
#include <math.h>

int main(){

    int a[50];
    int i=1;
    double total=0.0;
 
   scanf("%d", &a[i]); //reads in first value
   int j=1;
    double avg=0.0;
    while (a[i] >=0) {
        total+= a[i];
        avg=total/i;
	i=i+1;
        scanf("%d", &a[i]);
    }
    
    int sum=0;
    while (j<i){
   	 sum=(sum+pow(a[j]-avg,2));
   	 j++;
   	 }
    double stddev;
    stddev=sqrt(sum/(j-2));

    printf(" Average is %lf\n", avg);
    printf(" The Standard Deviation is %lf\n", stddev);

    return 0; }


