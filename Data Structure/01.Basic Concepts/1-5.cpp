// Q. Binary Search 을 수행하고 수행결과를 출력하는 코드를 작성하라.
// - 검색값이 존재하는 경우 S (인덱스) , 존재하지 않는 경우 F (-1) 출력

#include <iostream>
using namespace std;

#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))
#define COMPARE(x, y) (((x) < (y)) ? -1 : ((x) == (y) ? 0 : 1))

int BinarySearch(int arr[], int left, int right, int searchnum)
{
    int mid;

    while (left <= right)
    {
        mid = (left + right) / 2;
        switch (COMPARE(arr[mid], searchnum))
        {
        case -1:
            left = mid + 1;
            break;
        case 0:
            return mid;
        case 1:
            right = mid - 1;
        }
    }
    return -1;
}

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

    int SearchNum, n, min, tmp;

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
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        SWAP(arr[i], arr[min], tmp);
    }

    cin >> SearchNum;
    int result = BinarySearch(arr, 0, n - 1, SearchNum); // Binary Search 하기 전, 배열은 오름차순으로 정렬 되어 있어야 함 !!

    if (result == -1)
    {
        cout << "F " << "(" << -1 << ")";
    }
    else
    {
        cout << "S " << "(" << result << ")";
    }

    fclose(fp);
    free(arr); // 동적 할당 해제 !!
    return 0;
}

// Ex) Input : (File name) 3 , File Data : 5 1 -1 0 3 100 , Output : S (3)
// Ex) Input : (File name) 4 , File Data : 5 1 -1 0 3 100 , Output : F (-1)
