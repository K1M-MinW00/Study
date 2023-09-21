// Q. Radix sort algorithm 을 이용하여 in.txt 로 주어진 단어들을 lexicographic order 로 정렬하여 출력하라.
// 각 단어는 'a'~'z' 의 문자로 1 보다 크거나 같고 5보다 작거나 같은 개수의 문자로 구성된다.

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

int digit(char t[], int index)
{
    if (strlen(t) <= index)
        return 0;
    else
        return t[index] - 97;
}

int radixSort(char a[][6], int link[], int d, int r, int n)
{
    int front[26], rear[26];
    int i, bin, cur, first, last;
    first = 1;

    for (i = 1; i < n; i++)
        link[i] = i + 1;

    link[n] = 0;

    for (i = d - 1; i >= 0; i--)
    {
        for (bin = 0; bin < r; bin++)
            front[bin] = 0;

        for (cur = first; cur; cur = link[cur])
        {
            bin = digit(a[cur], i);
            if (front[bin] == 0)
                front[bin] = cur;
            else
                link[rear[bin]] = cur;
            rear[bin] = cur;
        }

        for (bin = 0; !front[bin]; bin++)
            ;
        first = front[bin];
        last = rear[bin];
        for (bin++; bin < r; bin++)
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

    char a[100][6];

    int i = 1;

    while (!feof(f))
    {
        fscanf(f, "%s", a[i]);
        i++;
    }
    int *link = new int;
    fclose(f);

    int k = radixSort(a, link, 5, 26, i);

    for (int j = k; j; j = link[j])
        printf("%s ", a[j]);

    return 0;
}

// in.txt : aim dol abc bza bbb , Output : abc aim bbb bza dol
