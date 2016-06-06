#include <stdio.h>

int main(void)
{
 {
     double p, intr,dmp, b ;
 
    printf("Enter your principal: "); 
  scanf ("%lf", &p);
    printf("Enter your interest: ");
  scanf ("%lf", &intr);
    printf("Enter number desired monthly payment: "); 
  scanf ("%lf", &dmp);
}

 printf("Month     Payment    Interest      Balance");
 
int m = 1
double x, b, p, r;

while (b > 0.00)
    if (b > p){
        r=b*(intr/1200.0);
        b=b-p;
        b=r+b;
        printf("%d\t%.2lf\t%.2lf\t%.2lf",m,p,intr,b);
        printf("\n");
        m=m+1;
        
    }
    else{
        r=b*(intr/1200.0);
        b=r+b;
        b=p;
        b=0.0;
        printf("%d\t%.2lf\t%.2lf\t%.2lf",m,p,intr,b);
    }
        
}
    return 0;
}


