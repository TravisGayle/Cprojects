// Travis Gayle
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "gfx.h"



double getfact(int); //prototype for factorial function
double getTaylor(double, int ); //prototype for taylor series function
void dashes(int xsize,int ysize); //prototype for axes & plot function
char *num2str(int); //prototype for converting character to a string

int main()
{
    int xsize = 500; //width of window
    int ysize = 500;//height of window
    int a; //counter for axes function
    double xax=.5*ysize; //halfway between width of window
    double yax= .5*xsize; //halfway between height of window (combined with xax for a point gives you 					center of the window.

    double x, T=0; //base of Taylor series function
    double count, xnew, ynew; //counter for factorial, new scaled x function, new scaled y function
    char op; //keyboard character variable
    int n=1;//number of terms
    int bf=0; //counter that alternates the sign for the taylor series given n terms
    int loop=1; //True variable to keep while loop running
    
    
    
    // Open a new window for drawing.
    gfx_open(xsize, ysize, "Taylor Series of Sin(x) Function"); //opens window
    gfx_clear();
    gfx_color(0,255,0); //sets axes color to green
    gfx_line(0,xax,xsize,xax); //creates line from x midpoint all the way down the middle
    gfx_line(yax,0,yax, ysize);//creates line from y midpoint all the way across the middle
    gfx_flush();
    
    
    
    
    
    while(1) {
        gfx_clear();
        
        
        for (x=-10; x<=10; x+=.01){ //incriments x in small amounts so that many points result in creation of a line.
            gfx_color(0,255,255);
            
            int xalt=(xsize/2)+(xsize/20)*-x; //scales x for sin(x) function
            int yalt= ((ysize/2)+(ysize/20)*sin(x)); //scales y for sin(x) function
            gfx_point(xalt,yalt); //plots point for (x,y) given that y corresponds to a given x
        }
        
        // PLOTTING OF TAYLOR SERIES GRAPH( Similar to sin(x))
        gfx_color(0,255,0); 
        gfx_line(0,xax,xsize,xax);
        gfx_line(yax,0,yax, ysize);
        dashes(xsize,ysize);
        for (x=-10; x<=10; x+=.01){
            xnew=(xsize/2)+(xsize/20)*x;
            ynew= ((ysize/2)+(ysize/20)*getTaylor(x,n));
            gfx_color(255,0,255);
            gfx_point(xnew,ynew);
            ynew=0;
        }
        
        op = gfx_wait();
        gfx_flush();
        
        //BUTTON PRESSES RESULT IN DIFFERENT N VALUES
        if (op =='='){
            n+=2;
        }
        
        if (op== '-'){
            n-=2;
        }
        
        if (op =='q'){ //Quits the program
            loop=0;
            break;
        }
        
        gfx_flush();

	if (n>=0){
        printf("\n Number of terms for n: %d\n", n);
	}
	else if (n<0){
	printf("\n YOU CANNOT HAVE NEGATIVE TERMS.\n");
	}

    }
    
    return 0;
    
}


double getfact(int n){
    
    // finds the factorial of n
    int count;
    
    double fact=1; //important to start at 1 for count and fact because starting at 0 results in 0 				everytime, leading to a 0 in the denominator of the series which would cause T(x)at 				any point to be undefined. We do not want that.

    for (count=1; count<=n;count++){
        fact=fact*count;
    }
    
    return fact; //return factorial
    
}

double getTaylor(double x, int n){
    int count;
    
    double T=0.0;
    int bf=0;
    for(count=1; count<=n; count+=2){
        T=T-(pow(-1,bf))*(pow(x,count))/(getfact(count))*1.0; //Alternating series in which (x^n/n!)*1^bf 				gives the Taylor series of sin(x) based on the number of terms we are looking to 				calculate for.
        bf++; //increments so that sign of term(n) alternates
    }
    bf=0; //resets after for loop exits so that recalculation for different number of terms is affected by 	old information.
    
    return T; //return Taylor series value
    
}


// DRAW AXES
void dashes(int xsize,int ysize){
    int a;
    int p;
    // TICK CREATOR
    for (a=0;a<=xsize+20; a+=xsize/20){
        gfx_line(xsize/2 -3, a+25,xsize/2 + 3,a+25); //The minus 3's and plus 3's establish a tick point 								that was not too long or too short for my graph.
        gfx_line(a+25,ysize/2 - 3, a+25,ysize/2 + 3);
    }
    //TICK LABEL (NUMBER IMPLEMENTATION)
    
    for (a=500; a>=0; a=a-25){
        int x=250;
        *num2str(a);
        gfx_text(xsize/2 +6,a+6 ,num2str((x-a)/25));
        gfx_text(a-6, ysize/2 +12,num2str((a-x)/25));
    }
// GRAPH KEY
    gfx_color(0,255,255);
    gfx_text(50, 75,"--- y=sin(x)"); //Key for Sin(x) graph

    gfx_color(255,0,255);
    gfx_text(50, 50,"--- y=T(x)"); //key for Taylor series

    gfx_color(255,255,255);
    gfx_text(50, 25,"By: TRAVIS GAYLE"); //My name.

}


//NUMBER TO STRING FUNCTION
char *num2str(int m){
    static char arr[10], *p = arr;
    snprintf(p, 10, "%d", m);
    return p;
}






