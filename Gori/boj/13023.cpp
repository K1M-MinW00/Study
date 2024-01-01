#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> A;
static vector<bool> visited;
static bool arrive;
void DFS(int now,int depth);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M;
    arrive = false;
    cin >> N >> M;

    A.resize(N);
    visited=vector<bool>(N,false);

    for(int i=0;i<M;i++)
    {
        int u,v;
        cin >> u >> v;

        A[u].push_back(v);
        A[v].push_back(u);
    }

    for(int i=0;i<N;i++) // 노드마다 DFS 실행
    {
        DFS(i,1); 
        if(arrive)
            break;
    }

    if(arrive)
        cout << 1;
    else
        cout << 0;

    return 0;
}

void DFS(int now,int depth)
{
    if(depth==5 || arrive) // 깊이가 5가 되면 종료
    {
        arrive = true;
        return;
    }
    visited[now] = true;

    for(int i : A[now])
    {
        if(!visited[i]) // 재귀 호출 시 depth를 1씩 증가하여 호출
            DFS(i,depth+1);
    }

    visited[now] = false;
}
