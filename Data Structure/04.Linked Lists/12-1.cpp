// Q. 파일에 오름차순으로 저장된 정수들을 차례대로 입력받아 doubly linked list with header node 를 구성하고 다음과 같이 실행되도록 코드를 작성하라.
// 각 기능은 함수로 구현한다 : 입력, 추가, 검색 , 삭제, 출력
// 검색 함수는 list 에 노드가 있는 경우 노드의 index , 없는 경우 0을 반환한다.
// 각 메뉴에 대한 작업을 수행한 후에는 list의 데이터를 순차적으로 출력한다.

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct node *nodePointer;
typedef struct node
{
    nodePointer llink;
    int data;
    nodePointer rlink;
};

nodePointer newNode(int n)
{
    nodePointer node;
    node = (nodePointer)malloc(sizeof(*node));
    node->llink = NULL;
    node->data = n;
    node->rlink = NULL;
    return node;
}

void dinsert(nodePointer node, nodePointer newnode)
{
    newnode->llink = node;
    newnode->rlink = node->rlink;
    node->rlink->llink = newnode;
    node->rlink = newnode;
}

int dsearch(nodePointer node, int n)
{
    nodePointer s;
    int idx = 1;
    for (s = node->llink; s->data != node->data; s = s->llink)
    {
        if (s->data == n)
            return idx;
        idx++;
    }
    return 0;
}

void ddelete(nodePointer node, nodePointer deleted)
{
    if (node == deleted)
    {
        printf("Deletion of head node not permitted.\n");
    }
    else
    {
        deleted->llink->rlink = deleted->rlink;
        deleted->rlink->llink = deleted->llink;
        free(deleted);
    }
}

void dprint(nodePointer first)
{
    nodePointer s;
    for (s = first->llink; s->data != first->data; s = s->llink)
    {
        printf("%d ", s->data);
    }
    printf("\n");
}

int main()
{
    int n, op;
    nodePointer first;
    first = (nodePointer)malloc(sizeof(*first));
    first->llink = first;
    first->rlink = first;

    nodePointer s, t;
    while (1)
    {
        printf("Choose operation (1. Input , 2.Insert , 3.Search, 4.Delete, 5.Exit) >> ");
        scanf("%d", &op);

        if (op == 1)
        {
            FILE *fp = fopen("in.txt", "r");
            if (fp == NULL)
            {
                printf("File Open fail");
                exit(1);
            }

            while (!feof(fp))
            {
                fscanf(fp, "%d", &n);
                s = newNode(n);
                dinsert(first, s);
            }
        }
        else if (op == 2)
        {
            printf("Insert num : ");
            scanf("%d", &n);
            s = newNode(n);
            for (t = first->llink; t->data != first->data; t = t->llink)
            {
                if (n < t->data)
                    break;
            }
            dinsert(t, s);
        }
        else if (op == 3)
        {
            printf("Search num : ");
            scanf("%d", &n);
            printf("%d\n", dsearch(first, n));
        }
        else if (op == 4)
        {
            printf("Delete num : ");
            scanf("%d", &n);
            int x = dsearch(first, n);
            if (x == 0)
                printf("Invalid!\n");
            else
            {
                s = first;
                for (int i = 0; i < x; i++)
                    s = s->llink;
                ddelete(first, s);
            }
        }
        else if (op == 5)
            break;
        dprint(first);
    }

    return 0;
}
// EX)
/*
Choose operation (1. Input , 2.Insert , 3.Search, 4.Delete, 5.Exit) >> 1
1 3 5 7
Choose operation (1. Input , 2.Insert , 3.Search, 4.Delete, 5.Exit) >> 2
Insert num : 2
1 2 3 5 7
Choose operation (1. Input , 2.Insert , 3.Search, 4.Delete, 5.Exit) >> 3
Search num : 5
4
1 2 3 5 7
Choose operation (1. Input , 2.Insert , 3.Search, 4.Delete, 5.Exit) >> 3
Search num : -3

C:\Users\kmw66\.vscode\DS>a.exe
Choose operation (1. Input , 2.Insert , 3.Search, 4.Delete, 5.Exit) >> 1
1 3 5 7

C:\Users\kmw66\.vscode\DS>a.exe
Choose operation (1. Input , 2.Insert , 3.Search, 4.Delete, 5.Exit) >> 1
1 3 5 7
Choose operation (1. Input , 2.Insert , 3.Search, 4.Delete, 5.Exit) >> 2
Insert num : 2
1 2 3 5 7
Choose operation (1. Input , 2.Insert , 3.Search, 4.Delete, 5.Exit) >> 3
Search num : 5
4
1 2 3 5 7
Choose operation (1. Input , 2.Insert , 3.Search, 4.Delete, 5.Exit) >> 3
Search num : -3
0
1 2 3 5 7
Choose operation (1. Input , 2.Insert , 3.Search, 4.Delete, 5.Exit) >> 4
Delete num : 3
1 2 5 7
Choose operation (1. Input , 2.Insert , 3.Search, 4.Delete, 5.Exit) >> 4
Delete num : 7
1 2 5
Choose operation (1. Input , 2.Insert , 3.Search, 4.Delete, 5.Exit) >> 4
Delete num : 3
Invalid!
1 2 5
Choose operation (1. Input , 2.Insert , 3.Search, 4.Delete, 5.Exit) >> 5
*/
