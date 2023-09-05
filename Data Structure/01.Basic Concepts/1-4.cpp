// Q. 1-3 문제를 file 입력처리로 수정하라.

#include <iostream>
using namespace std;

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int main()
{
    FILE *fp;
    char fname[50];
    cin >> fname;

    fp = fopen(fname, "r");
    if (fp == NULL)
    {
        fprintf(stderr, "file open fail\n");
        exit(1);
    }

    int n, min, tmp;

    fscanf(fp, "%d", &n);
    int *arr = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++)
    {
        fscanf(fp, "%d", &arr[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min]) // i번째 이후 원소 중 가장 작은 원소를 찾기 위해
            {
                min = j;
            }
        }
        SWAP(arr[i], arr[min], tmp); // i번째 원소 보다 뒤에 있는 원소 중 제일 작은 원소와 교체
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    
    fclose(fp);
    free(arr); // 동적 할당 해제 !!
    return 0;
}

// Ex) Input : (File name), File Data : 5 1 -1 0 3 100 , Output : -1 0 1 3 100
