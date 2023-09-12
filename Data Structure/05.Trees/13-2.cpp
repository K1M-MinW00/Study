// Q. 1번 과제에서의 구성된 binary tree 에 대해서 level order traversal 결과를 화면에 출력하라.

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAX_QUEUE_SIZE 100

typedef struct node *treePointer;
typedef struct node
{
    int data;
    treePointer leftChild, rightChild;
};
treePointer queue[MAX_QUEUE_SIZE];
int rear = -1;
int front = -1;

treePointer makeP(int n)
{
    treePointer node;
    node = (treePointer)malloc(sizeof(*node));
    node->data = n;
    node->leftChild = NULL;
    node->rightChild = NULL;

    return node;
}

void queueFULL()
{
    printf("queue is Full.\n");
    exit(1);
}

void addq(treePointer ptr)
{
    if (rear == MAX_QUEUE_SIZE - 1)
        queueFULL();

    queue[++rear] = ptr;
}

treePointer deleteq()
{
    return queue[++front];
}

void leverOrder(treePointer ptr)
{
    int front = 0, rear = 0;
    treePointer queue[MAX_QUEUE_SIZE];
    if (!ptr)
        return;
    addq(ptr);
    for (;;)
    {
        ptr = deleteq();
        if (ptr)
        {
            printf("%d ", ptr->data);
            if (ptr->leftChild)
                addq(ptr->leftChild);
            if (ptr->rightChild)
                addq(ptr->rightChild);
        }
        else
            break;
    }
}

int main()
{
    treePointer r1, r2, r3, r4, r5, r6;

    r1 = makeP(4);
    r2 = makeP(3);
    r3 = makeP(6);
    r4 = makeP(2);
    r5 = makeP(5);
    r6 = makeP(8);

    r1->leftChild = r2;
    r2->leftChild = r4;
    r2->rightChild = r5;
    r1->rightChild = r3;
    r3->rightChild = r6;

    leverOrder(r1);
    return 0;
}
// Output : 4 3 6 2 5 8
