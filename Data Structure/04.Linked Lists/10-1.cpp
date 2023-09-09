// Q. polynomial 의 non-zero term 에 대한 <coefficient, exponent> 데이터를 file 에서 입력 받아 linked list 로 표현하고,
// polynomial addition 결과를 출력하는 코드를 작성하라.
// 데이터의 입력은 c_1 e_1 c_2 e_2 ... c_m e_m
// 각 e_i 는 차수를 나타내며, e_i > e_(i+1) 이다.
// 각 c_i 는 차수 e_i 항의 coefficient 를 나타낸다.

#include <iostream>
#include <cstdio>
#include <cstdlib>
#define COMPARE(x, y) (((x) < (y)) ? -1 : ((x) == (y) ? 0 : 1))
using namespace std;

typedef struct polyNode *polyPointer;
typedef struct polyNode
{
    int coef;
    int expon;
    polyPointer link;
};
polyPointer a, b;

void attach(float coefficient, int exponent, polyPointer *ptr)
{
    polyPointer temp;
    temp = (polyPointer)malloc(sizeof(*temp));
    temp->coef = coefficient;
    temp->expon = exponent;
    (*ptr)->link = temp;
    *ptr = temp;
}

polyPointer padd(polyPointer a, polyPointer b)
{
    polyPointer c, rear, temp;
    int sum;
    rear = (polyPointer)malloc(sizeof(*rear));
    c = rear;
    while (a && b)
    {
        switch (COMPARE(a->expon, b->expon))
        {
        case -1:
            attach(b->coef, b->expon, &rear);
            b = b->link;
            break;
        case 0:
            sum = a->coef + b->coef;
            if (sum)
                attach(sum, a->expon, &rear);
            a = a->link;
            b = b->link;
            break;
        case 1:
            attach(a->coef, a->expon, &rear);
            a = a->link;
        }
    }

    for (; a; a = a->link)
        attach(a->coef, a->expon, &rear);
    for (; b; b = b->link)
        attach(b->coef, b->expon, &rear);
    rear->link = NULL;
    temp = c;
    c = c->link;
    free(temp);
    return c;
}

int main()
{
    polyPointer r1, r2, t1, t2, c;
    r1 = (polyPointer)malloc(sizeof(*r1));
    r2 = (polyPointer)malloc(sizeof(*r2));

    FILE *fp1 = fopen("in1.txt", "r");
    if (fp1 == NULL)
    {
        printf("File Open fail\n");
        exit(1);
    }
    int coef, expon;

    a = r1;
    while (!feof(fp1))
    {
        fscanf(fp1, "%d %d", &coef, &expon);
        attach(coef, expon, &r1);
    }
    r1->link = NULL;
    t1 = a;
    a = a->link;
    free(t1);

    FILE *fp2 = fopen("in2.txt", "r");
    if (fp2 == NULL)
    {
        printf("File Open fail\n");
        exit(1);
    }

    b = r2;
    while (!feof(fp2))
    {
        fscanf(fp2, "%d %d", &coef, &expon);
        attach(coef, expon, &r2);
    }
    r2->link = NULL;
    t2 = b;
    b = b->link;
    free(t2);

    c = padd(a, b);

    for (; c; c = c->link)
        printf("%d %d ", c->coef, c->expon);

    fclose(fp1);
    fclose(fp2);

    return 0;
}
// EX) in1.txt : -1 10 10 5 , in2.txt : 1 10 2 8 9 0 , Output : 2 8 10 5 9 0
// Ex) in1.txt 1 15 2 3 7 2 -3 1 , in2.txt : 2 10 3 3 8 2 5 0 , Output: 1 15 2 10 5 3 15 2 -3 1 5 0
