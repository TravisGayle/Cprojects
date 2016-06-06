//
//  prime.c
//  Primes
//
//  Created by Travis Gayle on 9/25/15.
//  Copyright © 2015 Travis Gayle. All rights reserved.
//

#include <stdio.h>
#define SIZE 1000


int main(){
    int myArray[1000];	//define array
    int i;                          //i counter
    int a;                          //a counter
    int pC = 0; //counter for prime numbers
    int j=0; //iterates
    
    /* All arrays are set to 1 */
    for ( i = 0; i < SIZE; i++ ) {
        myArray[ i ] = 1;
    }  
    
    /* test for multiples of position */
    for ( i = 1; i < 1000; i++ ) {
        /* start with array subscript two */
        if ( myArray[ i ] == 1 && i != 1 ) {
            
            /* loop through remainder of array */
            for ( a = i; a <= 1000; a++ ) {
                /* sets any multiple looped over to 0 */
                if ( a % i == 0 && a != i ) {
                    myArray[ a ] = 0;
                }
            }
        }
    }
    
    /* prints prime numbers */
    for ( i = 2; i < 1000; i++ ) {
        if ( myArray[ i ] == 1 ) {
            ++pC;
            printf("%5d", i);
            j=j+1;
            if (j ==10){
                printf("\n");
                j=0;
            }
        }
        
    }
    
    printf( "A total of %d prime numbers were found.\n", pC );
    
    return 0;
}
