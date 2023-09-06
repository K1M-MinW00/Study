// Q. 2차원 동적배열을 이용하여 행렬 덧셈을 테스트하는 코드를 작성하라.
// 행과 열의 크기를 scanf 로 입력 받는다.
// 2차원 동적배열 생성, 초기화, 출력, 메모리 해제는 각각 함수로 작성한다.

#include <iostream>
#include <cstdio>

using namespace std;

int** make2dArray(int rows,int cols)
{
    int **x;
    x = (int**)malloc(rows*sizeof(*x));

    for(int i=0;i<rows;i++)
    {
        x[i]=(int*)malloc(cols*sizeof(**x));
    }

    return x;
}

void init2dArray(int** arr,int rows,int cols)
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
}

void print2dArray(int** arr,int rows,int cols)
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}

void add(int** arr1,int** arr2,int** arr3,int rows,int cols)
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            arr3[i][j]= arr1[i][j]+arr2[i][j];
        }
    }
}
int main()
{
    int rows,cols;
    printf("Enter row size and column size (ex : 3 4) : ");
    scanf("%d %d",&rows,&cols);

    int **arr1, **arr2, **arr3;
    arr1 = make2dArray(rows,cols);
    arr2 = make2dArray(rows,cols);
    arr3= make2dArray(rows,cols);

    printf("Matrix A\n");
    init2dArray(arr1,rows,cols);
    
    printf("\nMatrix B\n");
    init2dArray(arr2,rows,cols);
    
    printf("\nMatrix C\n");
    add(arr1,arr2,arr3,rows,cols);
    print2dArray(arr3,rows,cols);


    for(int i=0;i<cols;i++)
    {
        free(arr1[i]);
        free(arr2[i]);
        free(arr3[i]);
    }

    free(arr1);
    free(arr2);
    free(arr3);

    return 0;
}
