// Q. doubly linked circular list를 사용해서 sparse matrix 를 구성하고 출력하는 메뉴기반의 프로그램을 작성하라.
// 각 기능은 함수로 구현한다 : mread , mwrite , merase 함수

#include <iostream>
#include <cstdio>
#include <cstdlib>
#define COMPARE(x, y) (((x) < (y)) ? -1 : ((x) == (y) ? 0 : 1))
using namespace std;
#define MAX_SIZE 50

typedef enum
{
    head,
    entry
} tagfield;
typedef struct matrixNode *matrixPointer;
typedef struct entryNode
{
    int row;
    int col;
    int value;
};

typedef struct matrixNode
{
    matrixPointer down;
    matrixPointer right;
    tagfield tag;
    union
    {
        matrixPointer next;
        entryNode entry;
    } u;
};

matrixPointer hdnode[MAX_SIZE];

matrixPointer newNode()
{
    matrixPointer node;
    node = (matrixPointer)malloc(sizeof(*node));
    node->down = NULL;
    node->right = NULL;
    return node;
}

matrixPointer mread()
{
    int numRows, numCols, numTerms, numHeads, i;
    int row, col, value, currentRow;
    matrixPointer temp, last, node;

    printf("Enter the number of rows,columns, and number of nonzero terms : ");
    scanf("%d %d %d", &numRows, &numCols, &numTerms);

    numHeads = (numCols > numRows) ? numCols : numRows;

    node = newNode();
    node->tag = entry;
    node->u.entry.row = numRows;
    node->u.entry.col = numCols;
    if (!numHeads)
        node->right = node;
    else
    {
        for (i = 0; i < numHeads; i++)
        {
            temp = newNode();
            hdnode[i] = temp;
            hdnode[i]->tag = head;
            hdnode[i]->right = temp;
            hdnode[i]->u.next = temp;
        }

        currentRow = 0;
        last = hdnode[0];
        for (i = 0; i < numTerms; i++)
        {
            printf("Enter row , column and value : ");
            scanf("%d %d %d", &row, &col, &value);

            if (row > currentRow)
            {
                last->right = hdnode[currentRow];
                currentRow = row;
                last = hdnode[row];
            }
            temp = newNode();
            temp->tag = entry;
            temp->u.entry.row = row;
            temp->u.entry.col = col;
            temp->u.entry.value = value;

            last->right = temp;
            last = temp;
            hdnode[col]->u.next->down = temp;
            hdnode[col]->u.next = temp;
        }
        last->right = hdnode[currentRow];

        for (i = 0; i < numCols; i++)
            hdnode[i]->u.next->down = hdnode[i];
        for (i = 0; i < numHeads - 1; i++)
            hdnode[i]->u.next = hdnode[i + 1];

        hdnode[numHeads - 1]->u.next = node;
        node->right = hdnode[0];
    }
    return node;
}

void mwrite(matrixPointer node)
{
    int i;
    matrixPointer temp, head = node->right;
    printf("\n numRows = %d, numCols = %d\n", node->u.entry.row, node->u.entry.col);

    printf("The matrix by row, column and value : \n\n");

    for (i = 0; i < node->u.entry.row; i++)
    {
        for (temp = head->right; temp != head; temp = temp->right)
            printf("%5d%5d%5d\n", temp->u.entry.row, temp->u.entry.col, temp->u.entry.value);
        head = head->u.next;
    }
}

void merase(matrixPointer *node)
{
    matrixPointer x, y, head = (*node)->right;
    int i;
    for (i = 0; i < (*node)->u.entry.row; i++)
    {
        y = head->right;
        while (y != head)
        {
            x = y;
            y = y->right;
            free(x);
        }
        x = head;
        head = head->u.next;
        free(x);
    }

    y = head;
    while (y != *node)
    {
        x = y;
        y = y->u.next;
        free(x);
    }
    free(*node);
    *node = NULL;
}
int main()
{
    matrixPointer s = NULL;
    int op;

    do
    {
        printf("Choose matrix operation (1. Input 2. Print 3. Erase 4. Exit) :");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            s = mread();
            break;
        case 2:
            mwrite(s);
            break;
        case 3:
            merase(&s);
            break;
        case4:
            exit(1);
        }
    } while (1);

    return 0;
}
// EX)
/*Choose matrix operation (1. Input 2. Print 3. Erase 4. Exit) :1
Enter the number of rows,columns, and number of nonzero terms : 5 4 6
Enter row , column and value : 0 0 2
Enter row , column and value : 1 0 4
Enter row , column and value : 1 3 3
Enter row , column and value : 3 0 8
Enter row , column and value : 3 3 1
Enter row , column and value : 4 2 6

Choose matrix operation (1. Input 2. Print 3. Erase 4. Exit) :2

 numRows = 5, numCols = 4
The matrix by row, column and value :

    0    0    2
    1    0    4
    1    3    3
    3    0    8
    3    3    1
    4    2    6
*/
