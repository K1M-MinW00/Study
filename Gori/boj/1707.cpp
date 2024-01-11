#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<vector<int>> A;
vector<bool> visited;
vector<int> check;
bool IsEven;

void DFS(int node)
{
    visited[node] = true;
    for (int i : A[node])
    {
        if (!visited[i])
        {
            check[i] = (check[node] + 1) % 2; // 인접한 노드는 같은 집합이 아니므로 이전 노드와 다른 집합으로 처리
            DFS(i);
        }
        else if (check[node] == check[i]) // 이미 방문한 노드인데 현재 나의 노드와 같은 집합이라면
            IsEven = false;               // 이분 그래프가 아님
    }
}

int main()
{
    int N;
    cin >> N;

    for (int t = 0; t < N; t++)
    {
        int V, E;
        cin >> V >> E;
        A.resize(V + 1);
        visited.resize(V + 1);
        check.resize(V + 1);
        IsEven = true;

        for (int i = 1; i <= E; i++)
        {
            int s, e;
            cin >> s >> e;
            A[s].push_back(e);
            A[e].push_back(s);
        }

        for (int i = 1; i <= V; i++) // 주어진 그래프가 하나로 연결된다는 보장이 없으므로 모든 노드에서 수행
        {
            if (IsEven)
                DFS(i);

            else
                break;
        }

        if (IsEven)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

        for (int i = 0; i <= V; i++) // 초기화
        {
            A[i].clear();
            visited[i] = false;
            check[i] = 0;
        }
    }

    return 0;
}
