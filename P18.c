#include <stdio.h>
#define MAX 100

typedef struct _poly
{
    int exp;
    float coe;
}poly;

poly terms[MAX];

static int avail=0;

void create(int*,int*);
void disp(int,int);

void create(int*s,int*f)
{
    *s=*f=avail;
    do
    {
      printf("\n coe of term");
      scanf("%f",&terms[*f].coe);
      printf("\n exp of terms");
      scanf("%d",&terms[*f].exp);

      avail++;
      *f=*f+1; //*f++ == *(f+1)
    } while (terms[*f-1].exp!=0);
    *f=*f-1; 
}

void disp(int s,int f)
{
    for(int i=s;i<=f;i++)
    {
        printf("%.2f",terms[i].coe);
        if(i!=(f+1))
            printf("x^%d+",terms[i].exp);
    }
}

int main(void)
{
    int sa,sb,fa,fb;
    printf("\n enter a(x)= ");
    create(&sa,&fa);
    printf(" sa=%d fa=%d avail=%d ",sa,fa,avail);
    printf("\n a(x)= ");
    disp(sa,fa);

    printf("\n enter b(x)= ");
    create(&sb,&fb);
    printf(" sb=%d fb=%d avail=%d ",sb,fb,avail);
    printf("\n b(x)= ");
    disp(sb,fb);
    
    return 1;
}