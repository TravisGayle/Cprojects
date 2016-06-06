#include <stdio.h>
#include <string.h>
#include <math.h>


int main(void)

{
    int a, b, c;
    char ops;
    
    printf("Enter an operation in all caps: ");
    scanf("%c", &ops);
    printf("Enter a value for a and b respectively: \n");
    scanf("%d%d", &a, &b);
    
    
    if (ops== 'A')
    {
        c=A(a,b);
    }
    else if (ops== 'S')
    {
        c=S(a,b);
    }
    else if (ops =='M')
    {
        c=M(a,b);
    }
    
    else if (ops == 'D')
    {
        c=D(a,b);
    }
    
    printf("Your value for c equals to %d\n", c);
    
    return 0;
 }

int A(int a, int b) {
    return a+b;
}
int S(int a, int b) {
    return a-b;
}
int M(int a, int b) {
    return a*b;
}
int D(int a, int b) {
    return a/b;
} 
