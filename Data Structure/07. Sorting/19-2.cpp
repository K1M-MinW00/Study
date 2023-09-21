// Q. Radix sort algorithm 을 이용하여 in.txt 로 주어진 정수들을 non-decreasing order 로 정렬하여 출력하라.
// 각 정수는 0~9 의 숫자 2개로 구성된다.

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int digit(int num, int index, int d)
{
    if (index == 1)
        return num % d;
    else if (index == 0)
        return num / d;
}

int radixSort(int a[], int link[], int d, int n)
{
    int front[10], rear[10];
    int i, bin, cur, first, last;

    first = 1;
    for (i = 1; i < n; i++)
        link[i] = i + 1;

    link[n] = 0;

    for (i = d - 1; i >= 0; i--)
    {
        for (bin = 0; bin < 10; bin++)
            front[bin] = 0;

        for (cur = first; cur; cur = link[cur])
        {
            bin = digit(a[cur], i, 10);
            if (front[bin] == 0)
                front[bin] = cur;
            else
                link[rear[bin]] = cur;
            rear[bin] = cur;
        }

        for (bin = 0; !front[bin]; bin++);
        first = front[bin];
        last = rear[bin];
        for (bin++; bin < 10; bin++)
            if (front[bin])
            {
                link[last] = front[bin];
                last = rear[bin];
            }
        link[last] = 0;
    }
    return first;
}

int main()
{
    FILE *f = fopen("in.txt", "r");
    if (f == NULL)
    {
        printf("file open fail\n");
        exit(1);
    }

    int *a = new int;

    int i = 1;

    while (!feof(f))
    {
        fscanf(f, "%d", &a[i]);
        i++;
    }
    int *link = new int;
    fclose(f);

    int k = radixSort(a, link, 2, i - 1);

    for (int j = k; j; j = link[j])
        printf("%d ", a[j]);

    return 0;
}

// in.txt : 12 2 16 30 8 28 4 10 20 6 18 , Output : 2 4 6 8 10 12 16 18 20 28 30
