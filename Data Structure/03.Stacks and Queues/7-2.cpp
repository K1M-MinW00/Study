// Q. 7-1 문제를 다음과 같이 출력하는 코드로 수정하라.
// entrance 와 exit 는 scanf 로 입력 받는다.
// maze 알고리즘을 수행하여 경로에 해당하는 a[i][j] 를 'x' 로 표시하여 maze 와 경로를 함께 출력한다.

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
char maze[MAX_ROW][MAX_COL];
int mark[MAX_ROW][MAX_COL];

element pop()
{
    return stack[top--];
}
void push(element item)
{
    stack[++top]= item;
}

void path(int ENTRANCE_ROW,int ENTRANCE_COL,int EXIT_ROW,int EXIT_COL)
{
    int i,row,col,nextRow,nextCol,dir;
    int found = FALSE;
    element position;

    mark[1][1] = 1; top=0;
    stack[0].row = ENTRANCE_ROW ; stack[0].col = ENTRANCE_COL; stack[0].dir = 0;
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
        for(int i=0; i<=top;i++)
            maze[stack[i].row][stack[i].col]=120; // unicode 120 : 'x'
        maze[row][col]= 120;
        maze[EXIT_ROW][EXIT_COL]=120;    
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

    int In_row,In_col,Out_row,Out_col;
    scanf("%d %d %d %d",&In_row,&In_col,&Out_row,&Out_col);

    path(In_row,In_col,Out_row,Out_col);
    
    for(int i=1;i<=row;i++)
    {
        for(int j=1;j<=col;j++)
        {
            if(maze[i][j] == 1 || maze[i][j] == 0)
                printf("%d ",maze[i][j]);
            else
                printf("%c ", maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}
/*
Input
5 5
1 1 1 1 1
1 0 0 0 0
1 0 0 1 1
1 1 0 0 1
1 1 0 1 1
5 3 2 5

Output

1 1 1 1 1 
1 0 x x x
1 0 x 1 1
1 1 x 0 1
1 1 x 1 1

*/
