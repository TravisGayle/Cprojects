#include <stdio.h>

int main(void)

{
   double  subtotal; //  subtotal to be entered by user
   double tax;
   double grandtotal;
   double taxrate; 
   
   printf( "Enter your subtotal: \n" ); // prompt
   scanf( "%lf", &subtotal ); // read an integer
   if(subtotal<0)
      printf(" YOU CANNOT HAVE NEGATIVE MONEY! \n");
   else
      printf( "Enter taxrate: \n" );
      scanf( "%lf",&taxrate );
      tax=taxrate * subtotal;
      grandtotal=subtotal + tax;
      printf( "The tax on %.2lf is %.2lf. Therefore, your grandtotal is %.2lf\n", subtotal, tax, grandtotal);    
      printf( "Here is your receipt! \n" );

return 0;
} // end function main

  
                    
