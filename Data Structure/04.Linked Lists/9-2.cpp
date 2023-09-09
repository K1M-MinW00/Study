// Q. 다음 지시사항에 따라 1번 코드를 수정하라.
// scanf 로 x 값을 입력받음 ( x 가 -1 이면 프로그램 종료 )
// x 가 list 에 존재하는 경우 해당 node 를 삭제하고, 존재하지 않는 경우 x 를 list 에 추가 (오름차순 유지)
// list 의 데이터들을 순차적으로 출력

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct listNode *listPointer;
typedef struct listNode
{
    int data;
    listPointer link;
} listNode;

listPointer first = NULL;

void insert(int num)
{
    listPointer x, temp;
    temp = (listPointer)malloc(sizeof(*temp));
    temp->data = num;
    temp->link = NULL;

    if (first)
    {
        if (first->data > temp->data)
        {
            temp->link = first;
            first = temp;
            return;
        }
        for (x = first; x->link; x = x->link)
        {
            if (x->data <= temp->data && x->link->data > temp->data)
            {
                temp->link = x->link;
                x->link = temp;
                return;
            }
        }
        x->link = temp;
    }
    else
    {
        first = temp;
    }
}

void Delete(int num)
{
    listPointer x, trail;
    trail = first;
    x = trail;

    if (first->data == num) // 가장 앞의 노드와 같을 때 삭제
    {
        first = x->link;
        x->link = NULL;
        free(x);
        return;
    }
    for (; x; x = x->link) // for 문을 돌면서 같은 값을 찾음
    {
        if (x->data == num) // 같은 값을 찾았을 때 삭제
        {
            trail->link = x->link;
            x->link = NULL;
            free(x);
            return;
        }
        trail = x; // 같은 값을 못 찾았을 때
    }
    return;
}

int search_list(int num)
{
    listPointer x;
    for (x = first; x; x = x->link)
    {
        if (x->data == num)
            return 1;
    }
    return -1;
}
void printList()
{
    listPointer x;
    for (x = first; x; x = x->link)
    {
        printf("%3d", x->data);
    }
    printf("\n");
}
int main()
{
    FILE *fp = fopen("in.txt", "r");
    if (fp == NULL)
    {
        printf("File Open fail\n");
        exit(1);
    }

    int data, i = 0;

    while (!feof(fp))
    {
        fscanf(fp, "%d", &data);
        if (search_list(data) == 1)
            Delete(data);
        else
            insert(data);
    }

    printList();

    while (1)
    {
        scanf("%d", &data);
        if (data == -1)
            break;

        if (search_list(data) == 1)
            Delete(data);
        else
            insert(data);
        printList();
    }

    fclose(fp);
    return 0;
}
/* in.txt : 10 20 35
Ex1)
Input / Output
5
  5 10 20 35
20
  5 10 35
-1

Ex2)
Input / Output
15
 10 15 20 35
10
 15 20 35
35
 15 20
-1
*/
