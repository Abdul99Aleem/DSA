#include <stdio.h>
#include <stdlib.h>

void create2D(int**,int,int);
void read2D(int**,int,int);
void print2D(int**,int,int);
void free2D(int**,int,int);
int add2D(int**,int**,int**,int,int,int,int);
int Mul2D(int**,int**,int**,int,int,int,int);

void create2D(int **A,int m,int n)
 {
    int i=0;
    for(i=0;i<m;i++)
        {
            A[i]=(int*)malloc(n*sizeof(int));
        }
    if(A[i]=NULL)
    {
        printf("No RAM\n");
        exit(0);
    }
 } 

void read2D(int **A,int m,int n)
{
    for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                {
                    printf("Enter A[%d][%d]\n",i,j);
                    scanf("%d",&A[i][j]);
                }
        }
}

void print2D(int **A,int m,int n)
 {
    printf("[A]=\n");
    for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                {
                    printf("%d ",A[i][j]);
                }
            printf("\n");
        }
 }

void free2D(int **A,int m,int n)
{
    for(int i=0;i<m;i++)
        free(A[i]);
    free(A);
}

int add2D(int **A,int **B,int **C,int m,int n,int p,int q)
 {
    for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                {
                    C[i][j]=A[i][j]+B[i][j];
                }
        }
    return 1;
 }

int Mul2D(int **A,int **B,int **D,int m,int n,int p,int q)
 {
    for(int i=0;i<m;i++)
        {
            for(int j=0;j<q;j++)
                {
                    D[i][j]=0;
                    for(int k=0;k<n;k++)
                        D[i][j]+=A[i][k]*B[k][j];
                }
        }
    return 1;
 }

int main(void)
 {
    int m,n,p,q;
    int **A=NULL, **B=NULL, **C=NULL, **D=NULL;
    A=(int**)malloc(sizeof(int*));
    B=(int**)malloc(sizeof(int*));
    C=(int**)malloc(sizeof(int*));
    D=(int**)malloc(sizeof(int*));
    if(NULL==A || NULL==B)
    {
        printf("No RAM\n");
        exit(0);
    }
    printf("Enter m and n-\n");
    scanf("%d %d",&m,&n);
    printf("Enter p and q-\n");
    scanf("%d %d",&p,&q);
    create2D(A,m,n);
    create2D(B,p,q);
    if(m!=p && n!=q)
     {
        printf("Addition not possible");
        exit(0);
     }
    create2D(C,m,n);
    if(n!=p)
     {
        printf("Multiplication not possible");
        exit(0);
     }
    create2D(D,m,n);
    printf("Enter first matrix elements\n");
    read2D(A,m,n);
    printf("Enter second matrix elements\n");
    read2D(B,p,q);
    printf("[A]=\n");
    print2D(A,m,n);
    printf("[B]=\n");
    print2D(B,p,q);
    if((add2D(A,B,C,m,n,p,q))==1)    
        print2D(C,m,n);
    if((Mul2D(A,B,D,m,n,p,q))==1)
        print2D(D,m,q);
    free2D(A,m,n);
    free2D(B,p,q);
    free2D(C,m,n);
    return 1;
 }