//Program to Print nth Fibonacci number.

#include <stdio.h>
#include <conio.h>

static int countFunCalls; //for VMS analysis

int getFib(int);
/*
//Using Recursion
int getFib(int n)
{
    countFunCalls++;
    printf("\n addr(n)=%p",&n);
    if(n<=2)
        return 1;
    return (getFib(n-1)+getFib(n-2));
}

*/
//Using Iteration
int getFib(int n)
{ 
    if (n <= 1) 
        return n; 
    int a = 0, b = 1, c; 
    for(int i = 2; i <= n; i++)
     {
        c = a + b; a = b; b = c; 
     } 
    return b;
}


int main(void)
{
    int n;
    printf("Enter Value of n ");
    scanf("%d",&n);
    int fib=getFib(n);
    printf("nth fibonacci term of %d is %d",n,fib);
    printf("\n VMS=%d",countFunCalls*sizeof(int));
    return 1;
}

