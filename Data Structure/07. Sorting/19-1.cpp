// Q. heapSort algorithm 을 사용해서 정수들의 집합에 대해 non-increasing order 로 정렬하여 출력하라.

#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;
#define SWAP(x, y, z) ((z) = (x), (x) = (y), (y) = (z))

typedef struct element
{
    int key;
};

void adjust(element list[], int root, int n)
{
    int child, rootkey;
    element temp = list[root];
    rootkey = list[root].key;
    child = 2 * root;
    while (child <= n)
    {
        if ((child < n) && (list[child].key < list[child + 1].key))
            child++;
        if (rootkey > list[child].key)
            break;
        else
        {
            list[child / 2] = list[child];
            child *= 2;
        }
    }
    list[child / 2] = temp;
}

void heapSort(element a[], int n)
{
    int i;
    element temp;

    for (i = n / 2; i > 0; i--)
        adjust(a, i, n);

    for (i = n - 1; i > 0; i--)
    {
        SWAP(a[1], a[i + 1], temp);
        adjust(a, 1, i);
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
        fscanf(f, "%d", &a[i].key);
        i++;
    }

    fclose(f);

    heapSort(a, i - 1);

    for (int j = i - 1; j >= 1; j--)
        printf("%d ", a[j].key);
    return 0;
}

// in.txt : 5 3 1 2 -1 0 -7 7 5 , Output : 7 5 5 3 2 1 0 -1 -7
