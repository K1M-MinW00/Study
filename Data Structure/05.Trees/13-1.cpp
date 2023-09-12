// Q. 다음과 같은 binary tree 를 linked representation 으로 구성한 뒤, preorder traversal 결과를 화면에 출력하라
//      4
//   3     6
//  2 5      8

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

typedef struct node *treePointer;
typedef struct node
{
    int data;
    treePointer leftChild, rightChild;
};

treePointer makeP(int n)
{
    treePointer node;
    node = (treePointer)malloc(sizeof(*node));
    node->data = n;
    node->leftChild = NULL;
    node->rightChild = NULL;

    return node;
}

void preorder(treePointer ptr)
{
    if (ptr)
    {
        printf("%d ", ptr->data);
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
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

    preorder(r1);
    return 0;
}
// Output : 4 3 2 5 6 8
