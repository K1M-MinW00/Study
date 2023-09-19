// Q. quicksort algorithm 을 이용하여 정수들의 집합에 대해 non-decreasing order 로 정렬하여 출력하라.

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>

#define SWAP(x, y, z) ((z) = (x), (x) = (y), (y) = (z))
using namespace std;

vector<int> arr;

void quickSort(int left, int right)
{
    int pivot, i, j, temp;

    if (left < right)
    {
        i = left;
        j = right + 1;
        pivot = arr[left];
        do
        {
            do
                i++;
            while (arr[i] < pivot);
            do
                j--;
            while (arr[j] > pivot);
            if (i < j)
                SWAP(arr[i], arr[j], temp);
        } while (i < j);
        SWAP(arr[left], arr[j], temp);
        quickSort(left, j - 1);
        quickSort(j + 1, right);
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

    while (!feof(f))
    {
        fscanf(f, "%d", &n);
        arr.push_back(n);
    }

    fclose(f);
    quickSort(0, arr.size() - 1);

    for (int i = 0; i < arr.size(); i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}

// in.txt : 5 3 1 2 -1 0 -7 7 5 , Output : -7 -1 0 1 2 3 5 5 7
