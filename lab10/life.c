// life.c
// Author:Travis Gayle
// 12.08.15
// This program replicates Conway's Game of Life

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define _GNU_SOURCE
#define MAX_LEN 40
#define MAX_WIDTH 40

//PROTOTYPES

void initialize_board(char tempboard[MAX_LEN][MAX_WIDTH], char newboard[MAX_LEN][MAX_WIDTH]);
void display_newboard(char newboard[MAX_LEN][MAX_WIDTH]);
void add_cell(char tempboard[MAX_LEN][MAX_WIDTH]);
void remove_cell(char tempboard[MAX_LEN][MAX_WIDTH]);
void make_newboard(char tempboard[MAX_LEN][MAX_WIDTH], char newboard[MAX_LEN][MAX_WIDTH]);
void play_forever(char tempboard[MAX_LEN][MAX_WIDTH], char newboard[MAX_LEN][MAX_WIDTH]);

// MAIN PROGRAM

int main(int argc, char *argv[]) // manually input data or a file
{
    char tempboard[MAX_LEN][MAX_WIDTH] = {};
    char newboard[MAX_LEN][MAX_WIDTH] = {};
    char letter;
    
    initialize_board(tempboard, newboard);
    
    if(argc == 1)
    {
        while(1)
        {
            printf("Interactive Mode:\na: add new cell\nr: remove cell\nn: advance simulation to next iteration\np: play the game continuously\nq: quit program\n");
            scanf(" %c", &letter);
            while(letter!= 'a' && letter!= 'r' && letter!= 'n' && letter!= 'p' && letter!= 'q') //if not correct letter, choose again
            {
                printf("You know that this is not an option. Please pick from the above choices.");
                scanf(" %c", &letter);
            }
		system("clear");
            switch(letter)

            {
                case 'a':
                    add_cell(tempboard);
                    continue;
                case 'r':
                    remove_cell(tempboard);
                    continue;
                case 'n':
                    make_newboard(tempboard,newboard);
                    display_newboard(newboard);
                    printf("\n");
                    continue;
                case 'p':
                    play_forever(tempboard,newboard);
                    continue;
                case 'q':
                    return 0;
                default:
                    continue;
            }
        }
    }

    if(argc == 2)
    {
        file_input(tempboard,newboard,argv);
    }
    return 0;
}


//FUNCTIONS TO GIVE MY PROGRAM LIFE (NO PUN INTENDED...or was intended)


void initialize_board(char tempboard[MAX_LEN][MAX_WIDTH], char newboard[MAX_LEN][MAX_WIDTH]) //create blank board
{
    int i,j;
    for(i=0;i<MAX_LEN;i++)
    {
        for(j=0;j<MAX_WIDTH;j++)
        {
            tempboard[i][j] = ' ';
            newboard[i][j] = ' ';
        }
    }
}
void display_newboard(char newboard[MAX_LEN][MAX_WIDTH])
{
    int i,j;
    for(i=0;i<MAX_LEN;i++)
    {
        printf("|");
        for(j=0;j<MAX_WIDTH;j++)
        {
            printf("%c ",newboard[i][j]); //display new board
        }
        printf("\n");
    }
    printf("\n");
}
void add_cell(char tempboard[MAX_LEN][MAX_WIDTH])
{
    int xpos, ypos;
    printf("Enter coordinates for new cell (separate with a space):");
    scanf(" %d %d",&xpos, &ypos);
    while ((xpos > MAX_WIDTH || xpos < 0) || (ypos > MAX_LEN || ypos < 0)) //if x and y coordinates not within boundaries, choose again
    {
        printf("Invalid choice. Please choose coordinates within the 40 x 40 table:");
        scanf(" %d %d", &xpos, &ypos);
    }
    if(tempboard[ypos][xpos] != 'X') //if no X in space
    {
        tempboard[ypos][xpos] = 'X'; //set X in space of given coordinates
    }
    printf("\n");
}
void remove_cell(char tempboard[MAX_LEN][MAX_WIDTH])
{
    int xpos, ypos;
    printf("Enter coordinates of cell being removed (separate with a space):");
    scanf("%d %d",&xpos, &ypos);
    while ((xpos > MAX_WIDTH || xpos < 0) || (ypos > MAX_LEN || ypos < 0)) //check that coordinates are in bounds
    {
        printf("INVALID. Choose coordinates in the 40 x 40 parameter of the board.");
        scanf("%d %d", &xpos, &ypos);
    }
    if(tempboard[ypos][xpos] == 'X')
    {
        tempboard[ypos][xpos] = ' '; //set space that has an X equal to null
    }
    printf("\n");
}
void make_newboard(char tempboard[MAX_LEN][MAX_WIDTH], char newboard[MAX_LEN][MAX_WIDTH])
{
    int i, j;
    for(i=0;i<MAX_LEN;i++)
    {
        for(j=0;j<MAX_WIDTH;j++)
        {
            if((neighbors(i,j,tempboard) == 3) && (tempboard[i][j] == ' '))
            {
                newboard[i][j] = 'X' ;//if cell has 3 neighbors and is dead, bring it to life
            }
            else if((neighbors(i,j,tempboard) == 2 || neighbors(i,j,tempboard) == 3) && (tempboard[i][j] == 'X'))
            {
                newboard[i][j] = 'X'; //if cell has 2 or 3 neighbors it lives
            }
            else
            {
                newboard[i][j] = ' '; //if the cell has more than 3 neighbors or less than 2, it dies
            }
        }
    }
    for(i=0;i<MAX_LEN;i++)
    {
        for(j=0;j<MAX_WIDTH;j++)
        {
            tempboard[i][j] = newboard[i][j]; //set temporary board = new board
        }
    }
}
int neighbors(int row, int col, char newboard[MAX_LEN][MAX_WIDTH])
{
    int cellcount = 0;
    if(row < 39)
    {
        if(newboard[row+1][col] == 'X')//check below
            cellcount++;
    }
    if(row < 39 && col > 0)
    {
        if(newboard[row+1][col-1] == 'X')//check bottom-left
            cellcount++;
    }
    if(col > 0)
    {
        if(newboard[row][col-1] == 'X')//check left
            cellcount++;
    }
    if(row > 0 && col > 0)
    {
        if(newboard[row-1][col-1] == 'X')//check top-left
            cellcount++;
    }
    if(row > 0)
    {
        if(newboard[row-1][col] == 'X')//check above
            cellcount++;
    }
    if(row > 0 && col < 39)
    {
        if(newboard[row-1][col+1] == 'X')//check top-right
            cellcount++;
    }
    if(col <39)
    {
        if(newboard[row][col+1] == 'X')//check right
            cellcount++;
    }
    if(row < 39 && col < 39)
    {
        if(newboard[row+1][col+1] == 'X')//check bottom-right
            cellcount++;
    }
    return cellcount;
}
void play_forever(char tempboard[MAX_LEN][MAX_WIDTH], char newboard[MAX_LEN][MAX_WIDTH])
{
    while(1)
    {
        make_newboard(tempboard,newboard);
        display_newboard(newboard); 
        printf("\n");
        
        usleep(50000); //delay time of display
        system("clear");//clears screen
        printf("\n");
    }
}

file_input(char tempboard[MAX_LEN][MAX_WIDTH], char newboard[MAX_LEN][MAX_WIDTH], char *argv[])
{
    int xpos, ypos;
    char choice;
    FILE *infile;
    infile = fopen(argv[1],"r");
    while(!feof(infile))
    {
        fscanf(infile,"%c %d %d", &choice,&xpos,&ypos); 
        
        switch(choice)
        {
            case 'a':
                if(tempboard[ypos][xpos] != 'X') //if no X in space
                {
                    tempboard[ypos][xpos] = 'X'; //set X in space of given coordinates
                }
                continue;
            case 'p':
                play_forever(tempboard,newboard);
        }
    }
    
}
