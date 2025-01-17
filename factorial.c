//Prgram to Demonstrate factorial of a given number n.

#include <stdio.h>
#include <conio.h>

static int countFunCalls; //for VMS analysis

int getFact(int);

//Using Reursion
int getFact(int n)
{
    countFunCalls++;
    printf("\n addr(n)=%p",&n);
    if(n<=1)
        return 1;
    return (n*getFact(n-1));
}

/*
//Using Iteration
int getFact(int n)
{
    countFunCalls++;
    printf("\n addr(n)=%p",&n);
    int res = 1;
    for (int i = 2; i <= n; i++)
        res *= i;
    return res;
}
*/

int main(void)
{
    int n;
    printf("Enter Value of n ");
    scanf("%d",&n);
    int fact=getFact(n);
    printf("Factorial of %d is %d",n,fact);
    printf("\n VMS=%d",countFunCalls*sizeof(int));
    return 1;
}