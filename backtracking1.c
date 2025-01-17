//Prgram to Demonstrate printing of numbers from n to 1 using backtracking.

#include <stdio.h>
#include <conio.h>
static int countFunCalls;

void doDisp(int);
void doDisp(int n)
{
    countFunCalls++;
    int i=0;
    printf("\n addr(n)=%p, addr(i)=%p",&n,&i);
    if(i>n)
        return;
    i++;
    doDisp(n);
    printf(" i=%d",i);
}

int main(void)
{
    int n;
    printf("Enter Value of n ");
    scanf("%d",&n);
    doDisp(n);
    printf("\n VMS=%d",countFunCalls*sizeof(int));
    return 1;
}