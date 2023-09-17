// Q. 아래 graph 를 linked adjacency list 를 구성한 뒤, breath-first-search rufrhkfmf ghkausdp cnffurgkfk.
// 주어진 undirected graph 에 대한 linked adjacency list 구성은 adjacency matrix 를 linked adjacency list 로 변환한다.
// dynamically linked queue 사용
//  0 -> 1 -> 2
//  1 -> 0 -> 3 -> 4
//  2 -> 0 -> 5 -> 6
//  3 -> 1 -> 7
//  4 -> 1 -> 7
//  5 -> 2 -> 7
//  6 -> 2 -> 7
//  7 -> 3 -> 4 -> 5 -> 6

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define FALSE 0
#define TRUE 1
#define MAX_VERTICES 10

typedef struct node *nodePointer;
typedef struct node
{
    int vertex;
    nodePointer link;
} node;

nodePointer *graph;
nodePointer front, rear;
short int visited[MAX_VERTICES];
int m[8][8] = {{0, 1, 1, 0, 0, 0, 0, 0}, {1, 0, 0, 1, 1, 0, 0, 0}, {1, 0, 0, 0, 0, 1, 1, 0}, {0, 1, 0, 0, 0, 0, 0, 1}, {0, 1, 0, 0, 0, 0, 0, 1}, {0, 0, 1, 0, 0, 0, 0, 1}, {0, 0, 1, 0, 0, 0, 0, 1}, {0, 0, 0, 1, 1, 1, 1, 0}};

int cnt = 0;

nodePointer newnode(int n)
{
    nodePointer node;
    node = (nodePointer)malloc(sizeof(*node));
    node->vertex = n;
    node->link = NULL;
    return node;
}

void insert(nodePointer first, nodePointer x)
{
    nodePointer temp = first;
    while (1)
    {
        if (temp->link == NULL)
        {
            temp->link = x;
            break;
        }
        temp = temp->link;
    }
}

void addq(int n)
{
    nodePointer temp;
    temp = (nodePointer)malloc(sizeof((*temp)));
    temp->vertex = n;
    temp->link = NULL;

    if (front)
        rear->link = temp;
    else
        front = temp;
    rear = temp;
}

int deleteq()
{
    nodePointer temp = front;
    int v;
    v = temp->vertex;
    front = temp->link;
    free(temp);
    return v;
}

void bfs(int v)
{
    nodePointer w;
    front = rear = NULL;
    printf("%2d", v);
    visited[v] = TRUE;
    addq(v);
    while (front)
    {
        v = deleteq();
        for (w = graph[v]->link; w; w = w->link)
            if (!visited[w->vertex])
            {
                printf("%2d", w->vertex);
                addq(w->vertex);
                visited[w->vertex] = TRUE;
            }
    }
}

int main()
{
    int n = 8, i, j, num;

    graph = (nodePointer *)malloc(n * sizeof(*graph));

    for (i = 0; i < n; i++)
    {
        graph[i] = (nodePointer)malloc(sizeof(*graph));
        graph[i]->link = NULL;
    }

    nodePointer x;

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (m[i][j] == 1 || m[j][i] == 1) // data 가 1 일 때, 노드 생성 후 삽입
            {
                x = newnode(j);
                insert(graph[i], x);
            }
        }
    }

    scanf("%d", &num);
    bfs(num);

    return 0;
}

// Input : 0 , Output : 0 1 2 3 4 5 6 7
// Input : 7 , Output : 7 3 4 5 6 1 2 0
