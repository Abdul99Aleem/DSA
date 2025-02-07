#include <stdio.h>
#define MAX 100

typedef struct _poly
{
    int exp;
    float coe;
} poly;

poly terms[MAX];

static int avail = 0;

void create(int*, int*);
void disp(int, int);
void padd(int, int, int, int, int*, int*);

void create(int* s, int* f)
{
    *s = *f = avail;
    do
    {
        printf("\ncoe of term: ");
        scanf("%f", &terms[*f].coe);
        printf("\nexp of term: ");
        scanf("%d", &terms[*f].exp);

        avail++;
        *f = *f + 1;
    } while (terms[*f - 1].exp != 0);
    *f = *f - 1;
}

void disp(int s, int f)
{
    for (int i = s; i <= f; i++)
    {
        printf("%.2f", terms[i].coe);
        if (i != f)
            printf("x^%d + ", terms[i].exp);
        else
            printf("x^%d", terms[i].exp);
    }
    printf("\n");
}

void padd(int sa, int fa, int sb, int fb, int* sc, int* fc)
{
    *sc = *fc = avail;
    while (sa <= fa && sb <= fb)
    {
        if (terms[sa].exp > terms[sb].exp)
        {
            terms[*fc].coe = terms[sa].coe;
            terms[*fc].exp = terms[sa].exp;
            *fc = *fc + 1;
            avail++;
            sa++;
        }
        else if (terms[sa].exp < terms[sb].exp)
        {
            terms[*fc].coe = terms[sb].coe;
            terms[*fc].exp = terms[sb].exp;
            sb++;
            *fc = *fc + 1;
            avail++;
        }
        else
        {
            terms[*fc].coe = terms[sa].coe + terms[sb].coe;
            terms[*fc].exp = terms[sa].exp;  // Keep the exponent the same
            sa++;
            sb++;
            *fc = *fc + 1;
            avail++;
        }
    }

    while (sa <= fa)
    {
        terms[*fc].exp = terms[sa].exp;
        terms[*fc].coe = terms[sa].coe;
        *fc = *fc + 1;
        sa++;
        avail++;
    }
    while (sb <= fb)
    {
        terms[*fc].exp = terms[sb].exp;
        terms[*fc].coe = terms[sb].coe;
        *fc = *fc + 1;
        sb++;
        avail++;
    }
}

int main(void)
{
    int sa, sb, fa, fb, sc, fc;
    printf("\nEnter a(x):");
    create(&sa, &fa);
    printf("\nEnter b(x):");
    create(&sb, &fb);
    printf("\nA(x) = ");
    disp(sa, fa);
    printf("\nB(x) = ");
    disp(sb, fb);
    padd(sa, fa, sb, fb, &sc, &fc);
    fc = fc - 1;
    printf("\nC(x) = ");
    disp(sc, fc);
    return 0;
}
