//Prgram to Demonstrate printing of numbers from n to 1.

#include <stdio.h>
#include <conio.h>

static int countFunCalls; //for VMS analysis

void doDisp(int);


/*Using Recursion
void doDisp(int n)
{
    countFunCalls++;
    printf("\n addr(n)=%p",&n);
    if(n<=0)
        return;
    printf(" n=%d",n);
    n--;
    doDisp(n);
}
*/


//Using iteration
void doDisp(int n)
{
    countFunCalls++;
    printf("\n addr(n)=%p",&n);
    int i=1;
    for(i=n;i>0;i--)
        printf("%4d",i);
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