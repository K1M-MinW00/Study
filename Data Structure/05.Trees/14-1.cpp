// Q. 주어진 입력에 따라 max heap 을 구성한 뒤, heap 에서 deletion 을 수행한 후의 heap 을 level order traversal 한 결과를 출력하라.
// 입력은 n C_0 C_1 ... C_n-1 m 으로 주어진다.
// C_i 는 양수 , 음수를 포함하는 정수이다.
// m 은 heap 에서 삭제될 원소의 개수이다.

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAX_ELEMENTS 200
#define HeAP_FULL(n) (n==MAX_ELEMENTS-1)
#define HEAP_EMPTY(n) (!n)

typedef struct{
    int key;
}element;

element heap[MAX_ELEMENTS];
int n;

void push(element item,int *n)
{
    int i= ++(*n);
    while((i!=1) && (item.key > heap[i/2].key))
    {
        heap[i]=heap[i/2];
        i/=2;
    }
    heap[i]=item;
}

element pop(int*n)
{
    int parent,child;
    element item, temp;
    item= heap[1];
    temp= heap[(*n)--];
    parent =1 ;
    child=2;

    while(child <=*n)
    {
        if((child < *n) && (heap[child].key < heap[child+1].key)) child++;
        if(temp.key >= heap[child].key) break;
        heap[parent]= heap[child];
        parent=child;
        child*=2;
    }
    heap[parent]=temp;
    return item;
}

int main()
{
    int num1,num2;
    scanf("%d",&num1);
    
    element item;
    for(int i=0;i<num1;i++)
    {
        scanf("%d",&item.key);
        push(item,&n);
    }

    scanf("%d",&num2);
    for(int i=0;i<num2;i++)
        pop(&n);

    for(int i=1;i<=n;i++)
        printf("%d ",heap[i].key);
    
    
       return 0;
}
// Input : 7 5 4 1 6 3 9 8 , 1 , Output : 8 5 6 4 3 1 
// Input : 6 1 3 5 2 4 6 , 3 , Output : 3 2 1
