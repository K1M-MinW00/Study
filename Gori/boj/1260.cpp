#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;
static bool arrive;

void DFS(int node);
void BFS(int node);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M, Start;
    arrive = false;
    cin >> N >> M >> Start;
    A.resize(N+1);

    for(int i=0;i<M;i++)
    {
        int s,e;
        cin >> s >> e;
        A[s].push_back(e);
        A[e].push_back(s);
    }

    for(int i=1;i<=N;i++)
        sort(A[i].begin(),A[i].end()); // 방문할 수 있는 노드가 여러 개일때, 번호가 작은 것부터 방문하기 위해서
    
    visited = vector<bool>(N+1,false);
    DFS(Start);
    cout << endl;
    fill(visited.begin(),visited.end(),false);
    BFS(Start);
    cout << endl;

    return 0;
}

void DFS(int node) // 깊이 우선 탐색
{
    cout << node << " ";
    visited[node] = true;

    for(int i : A[node])
    {
        if(!visited[i])
            DFS(i);
    }
}

void BFS(int node) // 너비 우선 탐색 
{
    queue<int> mq; // 선입선출 queue
    mq.push(node);
    visited[node] = true;

    while(!mq.empty())
    {
        int now_node = mq.front();
        mq.pop();
        cout << now_node << ' ';
        for(int i : A[now_node])
        {
            if(!visited[i])
            {
                visited[i] = true;
                mq.push(i);
            }
        }
    }
}
