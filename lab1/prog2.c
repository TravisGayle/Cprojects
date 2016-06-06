#include <stdio.h>

int main(void)

{
   int TD; //  number of touchdowns to be entered by user 
   int EP; // number of extra points to be entered by user
   int FG; // number of field goals to be entered by user
   int SF; // number of safeties to be entered by user
   int sum; // variable in which total number of points by ND will be stored    

   printf( "Enter number of touchdowns:\n" ); // prompt
   scanf( "%d", &TD ); // read an integer

   printf( "Enter number of extra points:\n" ); // prompt
   scanf( "%d", &EP ); // read an integer

   printf( "Enter number of field goals:\n" ); // prompt
   scanf( "%d", &FG ); // read an integer

   printf( "Enter number of safeties:\n" ); // prompt
   scanf( "%d", &SF ); // read an integer

   sum =(TD*6)+(EP*1)+(FG*3)+(SF*2); // assign total to sum

   printf( "The Notre Dame Fighting Irish scored %d\n", sum); // print sum
   printf( "GO IRISH! BEAT LONGHORNS!\n" );

} // end function main
