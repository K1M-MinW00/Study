// Q. 파일에 저장된 오름차순의 서루 다른 정수들을 차례대로 입력받아 doubly linked list with header node 를 구성하라.
// List 를 처음부터 끝 노드까지 차례대로 방문하여 내용을 출력한다. (정수들을 오름차순으로 출력)
// List 를 역순으로 방문하여 내용을 출력한다. (정수들을 내림차순으로 출력)

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

int main()
{
    FILE *fp = fopen("in.txt", "r");
    if (fp == NULL)
    {
        printf("File Open fail");
        exit(1);
    }

    int n;
    nodePointer first;
    first = (nodePointer)malloc(sizeof(*first));
    first->llink = first;
    first->rlink = first;

    nodePointer s;

    while (!feof(fp))
    {
        fscanf(fp, "%d", &n);
        s = newNode(n);
        dinsert(first, s);
    }

    for (s = first->llink; s->data != first->data; s = s->llink)
        printf("%d ", s->data);

    printf("\n");

    for (s = first->rlink; s->data != first->data; s = s->rlink)
        printf("%d ", s->data);
    return 0;
}
// EX) in.txt : -1 5 10 , Output : -1 5 10 / 10 5 -1
// EX) in.txt : 1 3 5 7 , Output : 1 3 5 7 / 7 5 3 1
