// crossword.c
// Authors: Sam Mustipher & Travis Gayle
// 11.6.15
// This program creates a crossword puzzle and outputs a solution, a blank board and clues in the form of direction, position, and anagram

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define _GNU_SOURCE
#define MAX_WORD 20  // up to 20 words
#define MAX_LEN 15  // each saying is 15 characters max

typedef struct Word_s{
    char word[MAX_LEN];
    int row;
    int col;
    int orientation;
} Word;

void showallwords(char [MAX_WORD][MAX_LEN], int);
void makeboard(char [MAX_LEN][MAX_LEN], char);
void printboard(char [MAX_LEN][MAX_LEN]);
void placefirstword(char [MAX_LEN], int [MAX_WORD], int [MAX_WORD], char [MAX_LEN][MAX_LEN]);
void findlength(int, char[MAX_WORD][MAX_LEN], int[]);
void sort(int, int[], char[MAX_WORD][MAX_LEN]);
int cycle(char [MAX_LEN], char [MAX_LEN][MAX_LEN], Word[MAX_WORD], int);
int inbounds(int , int );
int isclearvert(char [MAX_LEN][MAX_LEN], int , int , int , int);
int isclear(char [MAX_LEN][MAX_LEN], int , int , int , int);
int ishorizontal(char [MAX_LEN][MAX_LEN], int , int );
int string_only(const char *s);



int main()
{
    char blank='#';
    int numword = 0;
    char words[MAX_WORD][MAX_LEN];
    int xpos[MAX_WORD];
    int ypos[MAX_WORD];
    char board[MAX_LEN][MAX_LEN];
    Word details[MAX_WORD];
    
    printf("Enter up to 20 words with up to 15 characters \n");
    
    
    //LOADS WORDS INTO ARRAYS
    char theline[MAX_LEN];
    char c,l;
    while(numword<20) {
        int i = 0;
        int q = 0;
        fgets(theline, MAX_LEN, stdin);  // read in the next saying
        
        theline[strlen(theline) - 1] = '\0';
        if (strcmp(theline, ".") ==0) {
            break;
        }
        while(i<(strlen(theline))){
            c = toupper(theline[i]);
            theline[i] = c;
            i++;
        }
        strncpy(words[numword], theline, strlen(theline));
        words[numword][strlen(theline)] = '\0';
        numword++;
        
    }
    
    // Find which ever string is the longest
    int length[MAX_WORD] = {0};
    
    findlength( numword, words, length);
    sort(numword, length, words);
    
    makeboard(board,'.');
    
    printf("\n");
    printf("\n");
    
    placefirstword(words[0], xpos, ypos,  board);
    
    int m;
    for(m = 1; m<numword; m++){
        if(string_only(words[m])){
            if(cycle(words[m],board, details, m)==0){
                printf("Impossible for word %s to be placed\n", words[m]);
            }
            else{
                continue; //ignores words that can't be placed
            }}
        else{
            printf("Also impossible for word %s to be placed. It contains characters not included in the alphabet.\n", words[m]);
            continue; //ignores words with characters that are not in the alphabet
        }
    }
    
    // prints the solution board
    printf("Solution to the Cross Word Puzzle: \n");
    printf("\n");
    printboard(board);
    
    printf("\n");
    
    printf("Blank Cross Word Puzzle : \n");
    printf("\n");
    // prints out the blank crossword puzzle
    int x,y;
    for(x=0; x<MAX_LEN; x++){
        for(y=0; y<MAX_LEN; y++){
            if(isalpha(board[x][y])){
                board[x][y] = ' ';
            }
            else{
                board[x][y] = '#';
            }
        }
    }
    printboard(board);
    
    // prints out the clues
    // edits the details of the first word
    details[0].row = ypos[0];
    details[0].col = xpos[0];
    details[0].orientation = 0;
    int z;
    for(z=0; z<numword; z++){
        strfry(words[z]);
        
        if(details[z].orientation==1){
            printf("%d,%d\t%s\t%s\n", details[z].row, details[z].col, "down", words[z]);
        }
        if(details[z].orientation==0){
            strfry(words[z]);
            printf("%d,%d\t%s\t%s\n", details[z].row, details[z].col, "across", words[z]);
        }
        
    }
    
}

//PRINTS WORDS
void showallwords(char str[MAX_WORD][MAX_LEN], int n){
    int i;
    for (i=0; i<n; i++){
        printf ("%s\n",str[i]);
    }
}

//MAKE THE BOARD
void makeboard(char board[MAX_LEN][MAX_LEN], char blank){
    int i,j;
    for (i = 0; i < MAX_LEN; i++) {
        for (j = 0; j < MAX_LEN; j++) {
            board[i][j] = blank;
        }
    }
}

//PRINT THE BOARD
void printboard(char board[MAX_LEN][MAX_LEN]){
    int i,j;
    for (i = 0; i < MAX_LEN; i++) {
        for (j = 0; j < MAX_LEN; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n"); //prints board
    }
    printf("\n");
}

//FUNCTION PLACES FIRST WORD
void placefirstword(char word[MAX_LEN], int xpos[MAX_LEN], int ypos[MAX_LEN], char board[MAX_LEN][MAX_LEN]){
    int pos;
    int start=(15-strlen(word))/2;
    for (pos=0; pos<strlen(word); pos++){
        board[7][start+pos]=word[pos];
    }
    xpos[0]=start;
    ypos[0]=7;
    
    int i;
}

// finding the length of each of the strings and placing it in an array to be accessed by the sort function
void findlength(int numword, char words[MAX_WORD][MAX_LEN], int length[MAX_WORD]){
    int i = 0;
    for(i = 0; i<numword; i++){
        length[i] = strlen(words[i]);
    }
}

// SORTS THE LIST IN DECREASING LENGTH ORDER
void sort(int numword, int length[MAX_WORD], char words[MAX_WORD][MAX_LEN]){
    int i,j;
    char change[MAX_LEN];
    for (i = 0 ; i < ( numword - 1 ); i++){
        for (j = 0 ; j < numword - i - 1; j++){
            if (strlen(words[j]) < strlen(words[j+1])){
                strcpy(change,words[j]);
                strcpy(words[j],words[j+1]);
                strcpy(words[j+1], change);
                
            }
        }
    }
}

int cycle(char word[MAX_LEN],char board[MAX_LEN][MAX_LEN], Word details[MAX_WORD], int num){
    // checks through the board
    int i,j,k,l;
    int success = 0;
    int isclearflag;
    int isclearvertflag;
    int xpos, ypos;
    
    for(i=0;i<MAX_LEN;i++){
        for(j=0;j<MAX_LEN;j++){
            if(isupper(board[i][j])){
                for(k = 0; k < strlen(word); k++){ // checks if there is a match
                    if(board[i][j] == word[k]){
                        if(ishorizontal(board, i, j)){ // call isbounds() in the is horizontal function
                            if(!(inbounds(i-k,j))){ // checks if first letter within match is inbounds, continues to the next letter then
                                continue;
                            }
                            if(!(inbounds(i-k+strlen(word),j))){ // checks if first letter within match is inbounds, continues to the next letter then
                                continue;
                            }
                            isclearflag=1;
                            if (inbounds(i-k-1,j)){
                                if (isupper(board[i-k-1][j])){
                                    isclearflag=0;
                                }
                            }
                            if (inbounds(i-k+strlen(word),j)){
                                if (isupper(board[i-k+strlen(word)][j])){
                                    isclearflag=0;
                                }
                            }
                            for(l = 0; l < strlen(word); l++){ //iterate through the string you are placing
                                
                                if(!(isclear(board, i , j, k, l))){
                                    
                                    isclearflag=0;// goes to the next letter of the string you are looking to place
                                    break; // no longer checking letters
                                }
                            }
                            if (isclearflag==0){
                                continue;
                            }
                            // iterate over the same indicies of board and place
                            details[num] .row= i-k;
                            details[num].col = j;
                            int m;
                            for(m = 0; m < strlen(word); m++){
                                board[i-k][j] = word[m];
                                i++;
                            }
                            // giving the details its data
                            details[num].orientation = 1 ;
                            
                            success = 1;
                            return success;
                        }
                        else{ // word on the board is vertical
                            if(!(inbounds(i,j-k))){
                                continue;
                            }
                            if(!(inbounds(i,j-k+strlen(word)))){
                                continue;
                            }
                            isclearvertflag=1;
                            if (inbounds(i,j-k-1)){
                                if (isupper(board[i][j-k-1])){
                                    isclearvertflag=0;
                                }
                            }
                            if (inbounds(i,j-k+strlen(word))){
                                if (isupper(board[i][j-k+strlen(word)])){
                                    isclearvertflag=0;
                                }
                            }
                            for(l = 0; l < strlen(word); l++){ //iterate through the string you are placing
                                
                                if(!(isclearvert(board, i , j, k, l))){
                                    
                                    isclearvertflag=0;// goes to the next letter of the string you are looking to place
                                    break; // no longer checking letters
                                }
                            }
                            if (isclearvertflag==0){
                                continue;
                            }
                            details[num].row = i;
                            details[num].col = j-k;
                            // iterate over the same indicies of board and place
                            int m;
                            for(m = 0; m < strlen(word); m++){
                                board[i][j-k] = word[m];
                                j++;
                            }
                            details[num].orientation = 0; // across
                            success = 1;
                            return;
                        }
                    }
                }
            }
        }
    }
}

int ishorizontal(char board[MAX_LEN][MAX_LEN], int rowmatch, int colmatch){
    int choice = 0;
    if(inbounds(rowmatch, colmatch - 1)){
        if((isupper(board[rowmatch][colmatch-1]))){
            choice = 1;
        }
    }
    if(inbounds(rowmatch, colmatch+1)){
        if(isupper(board[rowmatch][colmatch+1])){
            choice = 1;
        }
    }
    return choice;
}

// checks the case where you are placing vertical word
int isclear(char board[MAX_LEN][MAX_LEN], int row, int matchcol, int offset, int downoffset){
    int clear = 1;
   	int rowstart = row - offset;
    int rowtocheck = rowstart + downoffset;
    if (rowtocheck == row){
        return 1;
    }
    if(inbounds(rowtocheck,matchcol - 1)){
        if( isupper(board[rowtocheck][matchcol - 1])) {
            clear = 0;
        }
    }
    
    if (inbounds(rowtocheck,matchcol+1)){
        if(isupper(board[rowtocheck][matchcol + 1])){
            clear = 0;
        }
    }
    return clear;
}

// checks the case where you have placed a horizontal word
int isclearvert(char board[MAX_LEN][MAX_LEN], int matchrow, int col, int offset, int horoffset){
    int clear = 1;
   	int colstart =  col - offset;
    int coltocheck = colstart + horoffset;
    if (coltocheck == col){
        return 1;
    }
    if(inbounds(matchrow -1 , coltocheck)){
        if( isupper(board[matchrow-1][coltocheck])) {
            clear = 0;
        }
    }
    
    if (inbounds(matchrow+1, coltocheck)){
        if(isupper(board[matchrow+1][coltocheck])){
            clear = 0;
        }
    }
    return clear;
}

//CHECKS TO SEE THAT STRING ONLY CONTAINS ALPHABETIC CHARACTERS
int string_only(const char *s)
{
    while (*s) {
        if (isalpha(*s++) == 0) return 0;
    }
    
    return 1;
}

int inbounds(int row, int col){
    return ( row>=0 && row<=MAX_LEN-1 && col>=0 && col<= MAX_LEN-1);
}

