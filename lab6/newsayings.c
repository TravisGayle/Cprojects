//
//  MySayings.c
//
//  Created by Travis Gayle on 10/13/15.
//  Copyright © 2015 Travis Gayle. All rights reserved.
//

// INCLUDE

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXI 100
#define MAXI2 80

// DEFINE VARIABLES


char sayings[MAXI2][MAXI];
char ch;
char word[80];
int size = MAXI;


int main()
{
    char filename[30];
    char newfile[30];
    char c[100];
    int i=0;
    char poo;
    int x;
    int z;
    int n;
    int num;
    int size = 100;
    printf("Enter the startup file name: ");
    scanf("%s", &filename);
    FILE *f; //opens file and reads it
    f = fopen(filename, "r");

    while(!feof(f)){ //runs while fdoes not equal end of file
        fgets(sayings[i], size, f); //reads all lines
        i++; //moves to next line
    }
    int choice;
    int ask = 1;
    
    while(ask) {
        printf("\n");
        printf("1: Display all sayings currently in the database.\n");
        printf("2: Enter a new saying into the database. \n");
        printf("3: List sayings that contain a given word (substring) entered by the user\n");
        printf("4: save all sayings in a new text file\n");
	printf("5: Count number of bytes in a line. \n");
        printf("6: Quit the program.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                
                for (x=0; x < i; x++)
                    printf("%s", sayings[x]);
                
                break;
                
            case 2:
                
                printf("\n Enter a new word: ");
                getchar();
                fgets(sayings[i++], size, stdin);
        
                
                break;
            case 3:
                
                printf("\n Enter your word: ");
                scanf("%s", word);
                for (z=0; z<size; z++){
                if (strcasestr(sayings[z], word)){
                    printf("%s", sayings[z]);}
                }
                break;
            case 4:
                
                printf("\n Enter new name to save file under: \n");
                scanf("%s", newfile);
                FILE *newf; //opens new file and reads it
                newf = fopen(newfile, "w");
                for (x=0; x < i; x++)
                    fprintf(newf, "%s", sayings[x]);
                
                break;

            case 5:
                printf("Enter a line number:\n");
                scanf("%d", num);
                char sayings[num];
		n = sizeof(sayings);
		printf("The size of this line is %d bites \n", n);
		break;
            case 6:
                printf("good bye!\n");
                fclose(f);
                ask = 0;
              
                break;
            default:
                printf("Invalid input. Try again. \n");
                
        }
    }
}


