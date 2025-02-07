#include <stdio.h>
#include <stdlib.h>

#define MAX 5
#define EC -1


void doDisp(int *, int *);
int inFirst(int *,int *,int);
int inEnd(int *, int *, int);
int inMid(int *,int *, int);
int AfterVal(int *, int *, int);
int BeforeVal(int *,int *, int);

void doDisp(int *A,int *n)
 {
    printf("n=%d \n",*n);
    for(int i=0;i<*n;i++)
        {
            printf("%d ",A[i]);
        }
 } 

int inFirst(int *A, int *n, int k)
 {
    if(*n>=MAX)
        return EC;
    for(int i=*n-1;i>=0;i--)
        A[i+1]=A[i];
    A[0]=k;
    *n=*n+1;
    return 1;
 }

int inEnd(int *A, int *n, int k)
 {
    if(*n>=MAX)
        return EC;
    A[*n]=k;
    *n=*n+1;
    return 1;
 }

int inMid(int *A, int *n, int k)
 {
    if(*n>=MAX)
        return EC;
    for(int i=*n-1;i>=(*n/2);i--)
        A[i+1]=A[i];
    A[*n/2]=k;
    *n=*n+1;
    return 1;
 }

int main(void)
 {
    int A[MAX]={0};
    int n,k,i;
    int ch;

    printf("Enter n");
    scanf("%d",&n);

    for(i=0;i<n;i++)
     {
        printf("Enter A[%d]=",i);
        scanf("%d",&A[i]);
     }
    do
     {
        printf("\n Enter choice \
                  1. Display \
                  2. Insert at First \
                  3. Insert at End \
                  4. Insert at Middle \
                  9. Exit");
        scanf("%d",&ch);
        switch(ch) 
        {
            case 1:
                doDisp(A,&n);
                break;
            case 2:
                printf("Enter value to insert at first");
                scanf("%d",&k);
                if(inFirst(A,&n,k)==1)
                    printf("Insertion success");
                else
                    printf("Insertion Error !");
                break;
            case 3:
                printf("Enter value to insert at the end");
                scanf("%d",&k);
                if(inEnd(A,&n,k)==1)
                    printf("Insertion success");
                else
                    printf("Insertion Error !");
                break;
            case 4:
                printf("Enter value to insert in the middle");
                scanf("%d",&k);
                if(inMid(A,&n,k)==1)
                    printf("Insertion success");
                else
                    printf("Insertion Error !");
                break;
            case 9:
                printf("Have a nice day !");
                exit(1);
                break;
            default:
                printf("Invalid choice");
                break;
        }
     }while(ch!=9);
 }