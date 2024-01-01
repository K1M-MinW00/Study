#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;
void DFS(int v);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;
    A.resize(N + 1);
    visited = vector<bool>(N + 1, false);

    int u, v;

    for (int i = 0; i < M; i++)
    {
        cin >> u >> v;
        A[u].push_back(v);
        A[v].push_back(u);
    }

    int cnt = 0;

    for (int i = 1; i <= N; i++)
    {
        if (!visited[i]) // 방문하지 않은 노드가 없을 때까지 반복
        {
            cnt++;
            DFS(i);
        }
    }

    cout << cnt;
    
    return 0;
}

void DFS(int v)
{
    if(visited[v])
        return;
    
    visited[v]=true;

    for(int i : A[v])
    {
        if(visited[i] == false) // 연결 노드 중 방문하지 않은 노드들 탐색
            DFS(i);
    }
}
