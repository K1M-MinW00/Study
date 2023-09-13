// Q. in.txt 의 space 로 구분된 정수들을 차례대로 삽입하여 binary search tree T 를 구성한 뒤,
// T 에 대해 inorder traversal 을 수행한 결과를 화면에 출력하라.

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

treePointer newnode(int n)
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

treePointer insert(treePointer node, int data)
{
    if (node == NULL)
        return newnode(data);
    if (data < node->data)
        node->leftChild = insert(node->leftChild, data);
    else if (data > node->data)
        node->rightChild = insert(node->rightChild, data);
    return node;
}

void inorder(treePointer ptr) // LVR
{
    if (ptr)
    {
        inorder(ptr->leftChild);
        printf("%d ", ptr->data);
        inorder(ptr->rightChild);
    }
}

int main()
{
    FILE *f = fopen("in.txt", "r");
    if (f == NULL)
        exit(1);

    treePointer root= NULL;

    int data;

    while (!feof(f))
    {
        fscanf(f, "%d", &data);
        root = insert(root, data);
    }

    inorder(root);
    fclose(f);

    return 0;
}

// Input : 5 2 3 4 1 , Output : 1 2 3 4 5
// Input : 2 10 6 4 8 12 , Output : 2 4 6 8 10 12
