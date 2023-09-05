// Q. 2-2 문제를 다음과 같이 수정한다.
// 각각 입력 파일은 오름차순으로 정렬된, 중복되지 않는 정수들이 space 로 구분되어 저장되어 있다. (데이터의 개수는 주어지지 않음 : feof 함수 사용)
// malloc을 사용해서 정수 10개를 저장할 수 있는 memory 공간을 할당 받은 뒤, 이후 읽어들이는 정수의 개수가 10개가 넘으면 realloc 함수를 이용하여
// 정수 10개의 저장공간 단위로 배열 크기를 확장한다.

#include <iostream>
#include <cstdio>

using namespace std;

void Intersection(int *arr1, int *arr2, int n1, int n2)
{
    int arr3[100];
    int idx = 0;
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (arr1[i] == arr2[j])
            {
                arr3[idx++] = arr1[i];
                break;
            }
        }
    }

    for (int i = 0; i < idx; i++)
    {
        printf("%d ", arr3[i]);
    }
}

int main()
{
    FILE *fp1, *fp2;
    char fname1[10], fname2[10];
    cin >> fname1 >> fname2;

    fp1 = fopen(fname1, "r");
    if (fp1 == NULL)
    {
        fprintf(stderr, "file 1 open fail\n");
        exit(1);
    }

    fp2 = fopen(fname2, "r");
    if (fp2 == NULL)
    {
        fprintf(stderr, "file 2 open fail\n");
        exit(1);
    }

    int n1 = 0, n2 = 0, n = 1, tmp;

    int *arr1 = (int *)malloc(sizeof(int) * 10);
    int *arr2 = (int *)malloc(sizeof(int) * 10);

    while (!feof(fp1))
    {
        fscanf(fp1, "%d", &tmp);
        n1++;
        if (n1 > 10 * n)
        {
            n++;
            arr1 = (int *)realloc(arr1, 10 * n * sizeof(int));
        }
    }
    n = 0;

    while (!feof(fp2))
    {
        fscanf(fp2, "%d", &tmp);
        n2++;
        if (n2 > 10 * n)
        {
            n++;
            arr2 = (int *)realloc(arr2, 10 * n * sizeof(int));
        }
    }

    fseek(fp1, 0, SEEK_SET);
    fseek(fp2, 0, SEEK_SET);

    for (int i = 0; i < n1; i++)
    {
        fscanf(fp1, "%d", &arr1[i]);
    }

    for (int i = 0; i < n2; i++)
    {
        fscanf(fp2, "%d", &arr2[i]);
    }

    Intersection(arr1, arr2, n1, n2);

    fclose(fp1);
    fclose(fp2);
    free(arr1);
    free(arr2);

    return 0;
}

// Ex) File Data4.txt : 1 2 3 4 5 6 7 8 9 10 11, File Data5.txt : 3 4 5 6 7 8 11 12 13 14 15 16 , Output : 3 4 5 6 7 8 11
