// Q. 16-1 을 이용하여, in.txt 로 주어진 undirected graph 가 몇 개의 connected component 로 구성되었는지 계산하여 화면에 출력하라.

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
short int visited[MAX_VERTICES];

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

void dfs(int v)
{
    nodePointer w;
    visited[v] = TRUE;
    // printf("%3d", v);
    for (w = graph[v]->link; w; w = w->link)
        if (!visited[w->vertex])
            dfs(w->vertex);
}

void connected(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
            cnt++;
        }
    }
}

int main()
{
    FILE *f = fopen("in.txt", "r");
    if (f == NULL)
        exit(1);

    int n, i, j, num;
    fscanf(f, "%d", &n);
    int **m;

    m = (int **)malloc(n * sizeof(*m));
    graph = (nodePointer *)malloc(n * sizeof(*graph));

    for (i = 0; i < n; i++)
    {
        m[i] = (int *)calloc(n, sizeof(**m)); // adjacency matrix 를 0 으로 초기화
        graph[i] = (nodePointer)malloc(sizeof(*graph));
        graph[i]->link = NULL;
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            fscanf(f, "%d", &m[i][j]);
            m[j][i] = m[i][j]; // adjacency list 에 데이터 삽입
        }
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
    fclose(f);

    connected(n);

    printf("%d", cnt);

    return 0;
}

// in.txt : 5 1 1 0 1 1 0 1 0 0 1 , Output : 1
// in.txt : 8 1 1 0 0 0 0 0 0 1 0 0 0 0 1 0 0 0 0 0 0 0 0 1 0 0 1 0 1 , Output : 2
