// Q. 동적 배열을 사용해서 데이터를 입력 받고 최소값을 찾아 출력하는 코드를 작성하라.
// 데이터의 개수 n 과 n 개의 정수 데이터를 표준 입력으로 받는다.
// 1차원 동적 배열 생성, 데이터 입력 및 최소값 찾기는 다음과 같이 함수로 구현한다.
// int * makeArray(int size); void initArray(int* arr, int size); int findMin(int* arr,int size);

#include <iostream>
#include <cstdio>

using namespace std;

int *makeArray(int size)
{
    int *x;
    x = (int *)malloc(size * sizeof(*x));

    return x;
}

void initArray(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
}

int findMin(int *arr, int size)
{
    int min = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
        }
    }

    return min;
}

int main()
{
    int n;
    scanf("%d", &n);

    int *arr = makeArray(n);
    initArray(arr, n);

    int min_value = findMin(arr, n);

    printf("%d", min_value);

    return 0;
}
// Ex) Input : 10 -100 99 0 1 991 363 -123 45 8 51 , Output : -123
// Ex) Input : 5 16 2 -41 89 61 , Output : -41
