// Q. 주어진 undirected graph 에 대한 adjacency matrix 를 파일(in.txt)로 입력 받은 뒤, scanf 로 입력 받은
// vertex로 부터 depth-first search 결과를 화면에 출력하라.
// in.txt 로 adjacency matrix 의 upper diagonal 부분만 원소들을 입력 받는다.
// n(<=10)은 graph의 vertex의 개수이며, 각 vertex 는 0 부터 n-1 까지의 번호로 표시한다.
// m_(i,j)는 edge 의 유무를 표시한다.

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
    printf("%3d", v);
    for (w = graph[v]->link; w; w = w->link)
        if (!visited[w->vertex])
            dfs(w->vertex);
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

    scanf("%d", &num);
    printf("dfs(%d) : ", num);
    dfs(num);

    return 0;
}

// in.txt : 8 1 1 0 0 0 0 0 0 1 1 0 0 0 0 0 1 1 0 0 0 0 1 0 0 1 0 1 0
// Input : 0 , Output : dfs(0) :   0  1  3  7  4  5  2  6
