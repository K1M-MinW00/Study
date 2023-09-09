// Q. 파일에서 양의 정수 데이터를 읽어서 오름차순으로 정렬된 singly linked list 를 구성하고 아래 단계들을 반복하는 코드를 작성하라.
// scanf 로 x 값을 입력받음 ( x 가 -1 이면 프로그램 종료 )
// x 를 list 에 추가 (오름차순 유지) : list 에 같은 값을 갖는 기존에 node 가 존재하는 경우 그 뒤에 삽입
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
}listNode;

listPointer first = NULL;

void insert(int num)
{
    listPointer x, temp;
    temp = (listPointer)malloc(sizeof(*temp));
    temp -> data = num;
    temp -> link = NULL;

    if(first)
    {
        if(first->data > temp->data)
        {
            temp->link = first;
            first= temp;
            return;
        }
        for(x=first;x->link;x= x->link)
        {
            if(x->data <= temp->data && x->link->data > temp->data)
            {
                temp->link = x->link;
                x->link = temp;
                return;
            }
        }
        x->link= temp;
    }
    else
    {
        first = temp;
    }
}

void printList()
{
    listPointer x;
    for(x=first;x;x=x->link)
    {
        printf("%3d",x->data);
    }
    printf("\n");
}
int main()
{
    FILE *fp = fopen("in.txt","r");
    if( fp == NULL)
    {
        printf("File Open fail\n");
        exit(1);
    }

    int data,i = 0;

    while(!feof(fp))
    {
        fscanf(fp,"%d",&data);
        insert(data);
    }

    printList();

    while(1)
    {
        scanf("%d",&data);
        if(data== -1)
            break;
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
  5 10 20 20 35
-1

Ex2)
Input / Output
15
 10 15 20 35
40
 10 15 20 35 40
50
 10 15 20 35 40 50
-1
*/
