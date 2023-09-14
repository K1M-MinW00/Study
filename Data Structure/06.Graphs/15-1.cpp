// Q. 주어진 undirected graph 에 대한 adjacency matrix 를 linked adjacency list 로 변환한 뒤, linked adjacency list 의 내용을 출력하라
// in.txt 로 adjacency matrix 의 upper diagonal 부분만 원소들을 입력 받는다.
// n(<=10) 은 graph 의 vertex 의 개수이며, 각 vertex 는 1부터 n까지의 번호로 표시한다.
// m_(i,j) 는 edge 의 유무를 표시한다. 만약 vertex i 와 vertex j 사이에 edge(i,j) 가 있으면 m_(i,j) = 1 이고, 그렇지 않을 경우 m_(i,j) = 0 이다.
// Adjacency list 의 각 vertex 에 연결된 linked list 를 처음부터 끝까지 방문하여 출력한다.
// (각 vertex 에 대해 연결된 linked list 는 vertex 들의 번호 순서가 임의로 구성될 수 있다.)

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAX_QUEUE_SIZE 100

typedef struct adjlist *listPointer;
typedef struct adjlist
{
    int data;
    listPointer link;
}adjlist;

listPointer newlist(int n)
{
    listPointer node;
    node = (listPointer)malloc(sizeof(*node));
    node->data = n;
    node->link = NULL;
    return node;
}



void insert(listPointer first, listPointer x)
{
   listPointer temp = first;
   while(1)
   {
    if(temp->link == NULL)
    {
        temp->link = x;
        break;
    }
    temp = temp->link;
   }
}

void printList(listPointer first, int n)
{
    listPointer temp;
    printf("Vertex %d :",n);
    for(temp=first->link;temp;temp=temp->link)
        printf("%3d",temp->data);
    printf("\n");
}

int main()
{
    FILE *f = fopen("in.txt", "r");
    if (f == NULL)
        exit(1);

    int n,i,j;
    fscanf(f,"%d",&n);
    int **m;
    listPointer* list;
    m = (int**)malloc(n*sizeof(*m));
    list = (listPointer*)malloc(n*sizeof(*list));

    for(i=0;i<n;i++)
    {
        m[i]= (int*)calloc(n,sizeof(**m)); // adjacency matrix 를 0 으로 초기화
        list[i]=(listPointer)malloc(sizeof(*list));
        list[i]->link=NULL;
    }

    listPointer x;
    
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            fscanf(f,"%d",&m[i][j]);
            m[j][i]=m[i][j]; // adjacency list 에 데이터 삽입
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(m[i][j]==1 || m[j][i] == 1) // data 가 1 일 때, 노드 생성 후 삽입
            {
                x=newlist(j);
                insert(list[i],x);
            }
        }
    }

    for(int i=0;i<n;i++)
        printList(list[i],i);
    fclose(f);

    return 0;
}

// in.txt : 5 1 1 0 1 1 0 1 0 0 1
/* Output
Vertex 0 :  1  2  4
Vertex 1 :  0  2  4
Vertex 2 :  0  1
Vertex 3 :  4
Vertex 4 :  0  1  3
*/
