#include <stdio.h>
#include <stdlib.h>

void create2D(int**,int,int);
void read2D(int**,int,int);
void print2D(int**,int,int);
void free2D(int**,int,int);
void printTransp(int**,int**,int,int);

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

void printTransp(int **A,int **S,int m,int n)
 {
    for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                S[i][j]=A[j][i];
        }
    print2D(S,m,n);
 }

void free2D(int **A,int m,int n)
{
    for(int i=0;i<m;i++)
        free(A[i]);
    free(A);
}

int main(void)
 {
    int m,n;
    int **A=NULL, **S=NULL;
    int i=0;
    A=(int**)malloc(sizeof(int*));
    S=(int**)malloc(sizeof(int*));
    if(NULL==A || NULL==S)
    {
        printf("No RAM\n");
        exit(0);
    }
    printf("Enter m and n-\n");
    scanf("%d %d",&m,&n);
    create2D(A,m,n);
    create2D(S,m,n);
    read2D(A,m,n);
    print2D(A,m,n);
    free2D(A,m,n);
    return 1;
 }