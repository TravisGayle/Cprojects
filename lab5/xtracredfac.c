//
//  main.c
//  xtra cred
//
//  Created by Travis Gayle on 10/8/15.
//  Copyright © 2015 Travis Gayle. All rights reserved.
//

#include <stdio.h>

int main(void) {
    
    int num,temp,perm,i,f=1, fct=0;
    
    printf("Enter a number: ");
    scanf("%d",&num);
    
    temp=num; //create temporary variable to store valuable of num
    perm=num; //creates permanent variable so as temp and num change, value of num is saved for printing
    while(temp){
        temp=temp/10; //allowing temp to become 0 at some point
        f = f*10;
    }
    
    while(f>1){
        f= f/10;
        printf("%d \n",num/f); //this type of division guarantees one digit printing each time
        for (i=0; (i <= (num/f)); i++){
            fct=fct+i;
        }
        
        num = num % f; //mod takes remainder of the number after being reduced by f which is always a factor of 10.
        
        
        
    }
	fct--;
    if (fct==num){
	
        printf("The sum of the factorials of the digits entered above is %d which equals to the number you entered: %d. \n",fct,perm);}
    else{
	
    	printf("The sum of the factorials of each digit, %d, does not equal the original number entered: %d \n", fct, perm);
    }
    return 0;
}



