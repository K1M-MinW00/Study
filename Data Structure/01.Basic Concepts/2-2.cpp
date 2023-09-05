// Q. data2.txt 와 data3.txt 는 각각 오름차순으로 정렬된 n1개의 정수와 n2개의 정수를 포함한다.
// data2.txt 와 data3.txt 에 포함된 정수들의 교집합을 오름차순으로 화면에 출력하라.
// 각각 입력 파일은 오름차순으로 정렬된, 중복되지 않는 정수들이 space 로 구분되어 저장되어 있다.
// 파일의 정수 데이터는 동적 배열에 저장한다. (malloc 함수 사용)

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

    int n1 = 0, n2 = 0, tmp;

    while (!feof(fp1))
    {
        fscanf(fp1, "%d", &tmp);
        n1++;
    }

    while (!feof(fp2))
    {
        fscanf(fp2, "%d", &tmp);
        n2++;
    }

    fseek(fp1, 0, SEEK_SET); // file stream 의 커서를 SEEK_SET, 즉 제일 처음으로부터 0 떨어진 지점으로 지정
    fseek(fp2, 0, SEEK_SET);

    int *arr1 = (int *)malloc(sizeof(int) * n1);
    int *arr2 = (int *)malloc(sizeof(int) * n2);

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

// Ex) File Data2.txt : 1 2 3 4 5 , File Data3.txt : 3 4 5 6 7 , Output : 3 4 5
