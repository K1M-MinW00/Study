// Q. Iterative merge sort algorithm 을 이용하여 정수들의 집합에 대해 non-decreasing order 로 정렬하여 출력하라.
// 입력 파일의 양식은 다음과 같다. record R_i 는 X_i, Y_i, Z_i 로 구성한다.
// X_1 Y_1 Z_1
//  .   .   .
// X_n Y_n Z_n
// Key 는 scanf 로 'X','Y' 또는 'Z' 를 입력한다. 입력된 key 에 대해 정렬을 수행한다.

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
#define MAX_SIZE 30

typedef struct element
{
    int X;
    int Y;
    int Z;
};

char key;

void merge(element initList[], element mergeList[], int i, int m, int n)
{ // 정렬된 initList[i:m] 과 initList[m+1:n] 을 합쳐 정렬된 mergeList[i:n] 을 얻음

    int j, k, t;
    j = m + 1; // 2번째 sublist 의 index
    k = i;     // merged list 의 index

    if (key == 'X')
        while (i <= m && j <= n)
        {
            if (initList[i].X <= initList[j].X)
                mergeList[k++] = initList[i++];
            else
                mergeList[k++] = initList[j++];
        }

    else if (key == 'Y')
        while (i <= m && j <= n)
        {
            if (initList[i].Y <= initList[j].Y)
                mergeList[k++] = initList[i++];
            else
                mergeList[k++] = initList[j++];
        }

    else if (key == 'Z')
        while (i <= m && j <= n)
        {
            if (initList[i].Z <= initList[j].Z)
                mergeList[k++] = initList[i++];
            else
                mergeList[k++] = initList[j++];
        }

    if (i > m)
        for (t = j; t <= n; t++)
            mergeList[t] = initList[t];
    else
        for (t = i; t <= m; t++)
            mergeList[k + t - i] = initList[t];
}

void mergePass(element initList[], element mergeList[], int n, int s)
{ // n : list 의 element 개수, s : 각각 정렬된 segement 의 크기
    int i;
    for (i = 1; i <= n - 2 * s + 1; i += 2 * s)
        merge(initList, mergeList, i, i + s - 1, i + 2 * s - 1);

    if (i + s - 1 < n)
        merge(initList, mergeList, i, i + s - 1, n);
    else
        for (int j = i; j <= n; j++)
            mergeList[j] = initList[j];
}

void mergeSort(element a[], int n)
{
    int s = 1; // segment 크기
    element extra[MAX_SIZE];

    while (s < n)
    {
        mergePass(a, extra, n, s);
        s *= 2;
        mergePass(extra, a, n, s);
        s *= 2;
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

    element *a = new element;
    int i = 1;

    while (!feof(f))
    {
        fscanf(f, "%d %d %d", &a[i].X, &a[i].Y, &a[i].Z);
        i++;
    }
    fclose(f);

    scanf("%c", &key);

    mergeSort(a, i - 1);

    for (int j = 1; j < i; j++)
        printf("%d %d %d\n", a[j].X, a[j].Y, a[j].Z);
}

/* in.txt
5 3 1
2 -1 0
-7 7 5

Output (X)

2 -1 0
5 3 1
-7 7 5

Output (Y)

2 -1 0
5 3 1
-7 7 5

Output (Z)

2 -1 0
5 3 1
-7 7 5
*/
