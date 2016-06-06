#include <stdio.h>

int main(void)

{
   int a, b, c;

printf("Enter two integers: ");
scanf("%d%d", &a, &b);
c = gcd(a, b);
printf("The greatest common divisor of these two numbers is: %d\n", c);

return 0;

}

int gcd( int a, int b)
{
    int sub;
    while (b != 0)
    {
        sub = a % b;

        a = b;
        b = sub;
    }
    return a;
}

