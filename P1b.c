//Prgram to Demonstrate printing of numbers from 1 to n.

#include <stdio.h>
#include <conio.h>

static int countFunCalls; //for VMS analysis

void doDisp(int);

/*Using Reursion
void doDisp(int n)
{
    countFunCalls++;
    static int i=1;
    printf("\n addr(n)=%p, addr(i)=%p",&n,&i);
    if(i>n)
        return;
    printf(" i=%d",i);
    i++;
    doDisp(n);
}
*/

//Using Iteration
void doDisp(int n)
{
    countFunCalls++;
    printf("\n addr(n)=%p",&n);
    int i=1;
    for(i=1;i<=n;i++)
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