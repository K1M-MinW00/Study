// Q. Maze 알고리즘을 구현하라. maze 경로는 화면에 출력한다.
// maze, mark, move, move, stack 변수는 모두 정적할당 사용
// maze 의 entrance 는 left top 으로, exit 는 right bottom 으로 가정 

#include <iostream>
#include <cstdio>
#include <cstdlib>
#define MAX_ROW 10
#define MAX_COL 10
#define FALSE 0
#define TRUE 1

using namespace std;

typedef struct
{
    short int vert;
    short int horiz;
}offsets;
offsets moves[8];

typedef struct
{
    short int row;
    short int col;
    short int dir;
}element;
element stack[MAX_ROW*MAX_COL];

int top;
int maze[MAX_ROW][MAX_COL];
int mark[MAX_ROW][MAX_COL];

element pop()
{
    return stack[top--];
}
void push(element item)
{
    stack[++top]= item;
}

void path(int EXIT_ROW,int EXIT_COL)
{
    int i,row,col,nextRow,nextCol,dir;
    int found = FALSE;
    element position;

    mark[1][1] = 1; top=0;
    stack[0].row =1 ; stack[0].col = 1; stack[0].dir = 1;
    while(top>-1 && !found)
    {
        position=pop();
        row= position.row; col = position.col; dir= position.dir;
        while(dir<8 && !found)
        {
            nextRow=row+moves[dir].vert; nextCol= col+moves[dir].horiz;

            if(nextRow==EXIT_ROW && nextCol == EXIT_COL)
                found = TRUE;
            else if(!maze[nextRow][nextCol] && !mark[nextRow][nextCol])
            {
                mark[nextRow][nextCol]= 1;
                position.row = row; position.col = col; position.dir = ++dir;
                push(position);
                row= nextRow; col = nextCol; dir =0;
            }
            else
                ++dir;
        }
    }

    if(found)
    {
        printf("The path is :\n");
        printf("row col\n");
        for(int i=0; i<=top;i++)
            printf("%2d%5d\n",stack[i].row,stack[i].col);
        printf("%2d%5d\n",row,col);
        printf("%2d%5d\n",EXIT_ROW,EXIT_COL);       
    }
    else
        printf("The maze does not have a path");
}

int main()
{
    moves[0].vert = -1; moves[0].horiz=0;
    moves[1].vert = -1; moves[1].horiz=1;
    moves[2].vert = 0; moves[2].horiz=1;
    moves[3].vert = 1; moves[3].horiz=1;
    moves[4].vert = 1; moves[4].horiz=0;
    moves[5].vert = 1; moves[5].horiz=-1;
    moves[6].vert = 0; moves[6].horiz=-1;
    moves[7].vert = -1 ;moves[7].horiz=-1;

    int row, col;
    scanf("%d %d",&row,&col);

    for(int i=0;i<row+2;i++)
    {
        for(int j=0;j<col+2;j++)
        {
            maze[i][j]=1; // maze 의 주변 테두리를 1로 감싸기 위해서
        }
    }

    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            scanf("%d",&maze[i][j]);
        }
    }

    path(row,col);
    

    return 0;
}
// EX)
/*
Input
4 5
0 0 0 1 1 
1 1 0 0 0
1 0 1 1 1
1 0 1 0 0
Output
The maze does not have a path

Input
5 4
0 1 1 1
0 1 1 0
1 0 0 1
1 1 0 1
1 0 1 0

Output
The path is :
row col
 1    1
 2    1
 3    2
 3    3
 4    3
 5    4
*/
