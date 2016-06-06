//
//  main.c
//  LAB
//
//  Created by Travis Gayle on 10/5/15.
//  Copyright © 2015 Travis Gayle. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

int main(void) {
    char c;
    int i;
    double sum = 0.0;
    double symbol=0.0;
    double tot=0.0;
    double specialc=0.0;
    double perc=0.0;
    int count[26]={0};
    double space=0.0;
    char infile[20];
    
    printf("Enter the data file name: ");
    scanf("%s", infile);
    FILE *f = fopen(infile, "r"); //opens file and reads it
    while (fscanf(f, "%c", &c) !=EOF) {
        if(isalpha(c)){ //if character is an alphabet
            if (islower(c)){ //if alphabet character is lower case
                c=toupper(c); //change lowercase to upper
                count[c-'A']+=1; //increments count for the letter
            }
            
            else if(isupper(c)){
                count[c-'A']+=1; //increments count for the letter
                }
        }
        else if(isspace(c)){
            space++;
        }

        else{
            specialc++;
        }
    }

    for (i = 0; i<=25; i++){
        printf("%c: %d\n", i + 'a', count[i]);
    }
    	
       for (i = 0; i<=25; i++){
            sum+=count[i];
        }
        
        tot= sum + specialc + space;
        
        perc=(space/tot) * 100;
        
    
        printf("Letter total: %.f \n", sum);
        printf("Character total: %.f \n", tot);
        printf("Blank Space Total: %.f \n", space);
        printf("Blank Space Percentage: %.1f % \n", perc);

        fclose(f);
        
    }

