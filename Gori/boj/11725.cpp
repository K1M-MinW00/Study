// 문제 : https://www.acmicpc.net/problem/11725
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> answer;
vector<bool> visited;
vector<vector<int>> tree;

void DFS(int i)
{
    visited[i] = true;
    for (int node : tree[i])
    {
        if (!visited[node]) // 방문하지 않은 노드
        {
            answer[node] = i; // 방문하기 직전 노드가 부모 노드
            DFS(node);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    visited.resize(N + 1);
    answer.resize(N + 1);
    tree.resize(N + 1);

    for (int i = 1; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    DFS(1);

    for (int i = 2; i <= N; ++i)
        cout << answer[i] << '\n';

    return 0;
}
