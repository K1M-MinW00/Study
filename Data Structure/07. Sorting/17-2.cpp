// Q. 데이터를 입력받아서 insert sort 를 수행한 결과를 파일 및 화면에 출력하라.
// 각 레코드는 (key , name , grade) 의 필드로 구성된다.

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define FALSE 0
#define TRUE 1
#define MAX_VERTICES 10

typedef struct element
{
    int key;
    char name[10];
    int grade;
};

void insert(element e, element a[], int i)
{
    a[0] = e;
    while (e.key < a[i].key)
    {
        a[i + 1] = a[i];
        i--;
    }
    a[i + 1] = e;
}

void insertionSort(element a[], int n)
{
    for (int i = 2; i <= n; i++)
    {
        element temp = a[i];
        insert(temp, a, i - 1);
    }
}

int main()
{
    FILE *f = fopen("in.txt", "r");
    if (f == NULL)
    {
        printf("file open fail\n");
        exit(1);
    }

    int n;
    fscanf(f, "%d", &n);

    element a[10];

    for (int i = 1; i <= n; i++)
    {
        fscanf(f, "%d %s %d\n", &a[i].key, a[i].name, &a[i].grade);
    }

    fclose(f);

    insertionSort(a, n);

    for (int i = 1; i <= n; i++)
    {
        printf("%d %s %d\n", a[i].key, a[i].name, a[i].grade);
    }
    return 0;
}

/* in.txt
7
10 Kim 95
35 Joe 89
25 Park 59
50 Hong 33
15 Lee 65
11 Jung 78
33 Choi 67

Output
10 Kim 95
11 Jung 78
15 Lee 65
25 Park 59
33 Choi 67
35 Joe 89
50 Hong 33
*/
