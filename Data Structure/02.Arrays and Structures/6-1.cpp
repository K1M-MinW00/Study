// Q. Sparse matrix (A) 에 대한 Transpose matrix (B) 를 구하는 함수를 구현하고 그 실행 결과를 보여라.
// matrix A 와 B 는 구조체 배열로 표현한다.
// void fastTranspose(term a[], term b[]) 함수와 matrix 출력 함수를 구현한다.
// A 와 B 를 화면에 출력한다.

#include <iostream>
#include <cstdio>
#define COMPARE(x, y) (((x) < (y)) ? -1 : ((x) == (y) ? 0 : 1))
#define MAX_COL 101
using namespace std;

typedef struct
{
    int col;
    int row;
    int value;
} term;

term a[MAX_COL], b[MAX_COL];

void fastTranspose(term a[], term b[])
{
    int rowTerms[MAX_COL], startingPos[MAX_COL];
    int i,j,numCol=a[0].col, numTerms=a[0].value;
    b[0].row = numCol; b[0].col = a[0].row; b[0].value = numTerms;

    if(numTerms>0)
    {
        for(i=0;i<numCol;i++) rowTerms[i]=0;
        for(i=1;i<=numTerms;i++) rowTerms[a[i].col]++;
        startingPos[0]=1;
        for(i=1;i<numCol;i++)
            startingPos[i] = startingPos[i-1] + rowTerms[i-1];
        for(i=1;i<=numTerms;i++)
        {
            j = startingPos[a[i].col]++;
            b[j].row = a[i].col; b[j].col = a[i].row ; b[j].value = a[i].value;
        }
    }
}

void printM(term a[])
{
    int **m;
    m = (int **)calloc(a[0].row,sizeof(int*));

    for(int i=0;i<a[0].row;i++)
        m[i]= (int *)calloc(a[0].col,sizeof(int));

    for(int j=1;j<=a[0].value;j++)
        m[a[j].row][a[j].col]= a[j].value;

    for(int i=0;i<a[0].row;i++)
    {
        for(int j=0;j<a[0].col;j++)
        {
            printf("%3d ",m[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    printf("Input Sparse Matrix A\n");
    scanf("%d %d %d",&a[0].row,&a[0].col,&a[0].value);

    for(int i=1;i<=a[0].value;i++)
        scanf("%d %d %d",&a[i].row,&a[i].col,&a[i].value);

    fastTranspose(a,b);

    printf("A\n");
    printM(a);
    printf("\nB\n");
    printM(b);
    return 0;
}
/*
Ex) Input : Sparse Matrix A
6 6 8
0 0 15
0 3 22
0 5 -15
1 1 11
1 2 3
2 3 -6
4 0 91
5 2 28

Output:
A
 15   0   0  22   0 -15
  0  11   3   0   0   0
  0   0   0  -6   0   0
  0   0   0   0   0   0
 91   0   0   0   0   0
  0   0  28   0   0   0

B
 15   0   0   0  91   0
  0  11   0   0   0   0
  0   3   0   0   0  28
 22   0  -6   0   0   0
  0   0   0   0   0   0
-15   0   0   0   0   0
*/
