// Q. qsort function 을 이용하여 18-1.cpp 와 같은 작업을 수행하라.
#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    FILE *f = fopen("in.txt", "r");
    if (f == NULL)
    {
        printf("file open fail\n");
        exit(1);
    }

    int idx = 0;
    int *arr = new int;

    while (!feof(f))
    {
        fscanf(f, "%d", &arr[idx++]);
    }

    fclose(f);

    qsort(arr, idx, sizeof(int), compare);

    for (int i = 0; i < idx; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

// in.txt : 5 3 1 2 -1 0 -7 7 5 , Output : -7 -1 0 1 2 3 5 5 7
