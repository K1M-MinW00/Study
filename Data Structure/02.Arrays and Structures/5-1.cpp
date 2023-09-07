// Q. 두 다항식을 입력받고 다항식 덧셈 연산을 수행 후 그 결과를 출력하는 프로그램을 작성하라.
// 다항식 덧셈은 void padd(int starta, int finisha, int startb, int finishb, int *startd, int *finishd) 와
// void attach(float coefficient, int exponent) 함수 사용
// 다항식 입력과 출력은 각각 함수로 구현

#include <iostream>
#include <cstdio>
#define COMPARE(x, y) (((x) < (y)) ? -1 : ((x) == (y) ? 0 : 1))
#define MAX_TERMS 100
using namespace std;

typedef struct
{
    float coef;
    int expon;
} polynomial;

polynomial terms[MAX_TERMS];
int avail = 0;

void init_poly()
{
    scanf("%f %d",&terms[avail].coef, &terms[avail].expon);
    avail++;
}

void attach(float coefficient, int exponent)
{
    if(avail >= MAX_TERMS)
    {
        fprintf(stderr,"Too many terms in the polynomial\n");
        exit(1);
    }
    terms[avail].coef= coefficient;
    terms[avail++].expon = exponent;
}

void padd(int starta, int finisha, int startb, int finishb, int *startd, int *finishd)
{
    float coefficient;
    *startd = avail;
    while (starta <= finisha && startb <= finishb)
    {
        switch (COMPARE(terms[starta].expon, terms[startb].expon))
        {
        case -1:
            attach(terms[startb].coef, terms[startb].expon);
            startb++;
            break;
        case 0:
            coefficient = terms[starta].coef + terms[startb].coef;
            if (coefficient)
                attach(coefficient, terms[starta].expon);
            starta++;
            startb++;
            break;
        case 1:
            attach(terms[starta].coef, terms[starta].expon);
            starta++;
        }
    }

    for(; starta<=finisha;starta++)
        attach(terms[starta].coef,terms[starta].expon);
    
    for(; startb<=finishb;startb++)
        attach(terms[startb].coef,terms[startb].expon);
    
    *finishd = avail - 1;
}

void print_poly(int start,int finish)
{
    for(int i=start;i<=finish;i++)
    {
        if(terms[i].expon !=0)
            printf("%lfx^%d ",terms[i].coef,terms[i].expon);
        else
            printf("%lf ",terms[i].coef);
        if(i != finish)
            printf("+ ");

    }
}
int main()
{
    int item_A, item_B, startd, finishd;

    printf("<< D(x) = A(x) + B(x) >>\n");
    printf("Input the number of items of A(x) : ");
    scanf("%d", &item_A);
    printf("Input the number of items of B(x) : ");
    scanf("%d", &item_B);

    printf("\nInput in descending order\n");

    for(int i=0;i<item_A;i++)
    {
        printf("the %d's coefficient and exponent of A(x), (ex) 10 3 : ",i+1);
        init_poly();
    }
    printf("\n");

    for(int i=0;i<item_B;i++)
    {
        printf("the %d's coefficient and exponent of B(x), (ex) 10 3 : ",i+1);
        init_poly();
    }
    
    padd(0,item_A-1,item_A,item_A+item_B-1,&startd,&finishd);
    printf("\nA(x) = ");
    print_poly(0, item_A-1);
    printf("\nB(x) = ");
    print_poly(item_A, item_A+item_B-1);
    printf("\nD(x) = ");
    print_poly(startd,finishd);

    return 0;
}
// EX) Input : A(x) = 2x^1000 + 1 , B(x) = x^4 + 10x^3 + 3x^2 + 1 , Output : D(x) = 2x^1000 + x^4 + 10x^3 + 3x^2 + 2
