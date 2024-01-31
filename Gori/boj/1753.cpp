// 문제 : https://www.acmicpc.net/problem/1753

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> edge;
static int V, E, K;

static vector<vector<edge>> A;
static vector<int> D;
static vector<bool> visited;
static priority_queue<edge, vector<edge>, greater<edge>> q; // 오름차순 정렬

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> K;
    D.resize(V + 1);
    fill(D.begin(), D.end(), 999);
    visited.resize(V + 1);
    fill(visited.begin(), visited.end(), false);
    A.resize(V + 1);

    for (int i = 0; i < E; ++i) // weighted direct graph 입력
    {
        int u, v, w;
        cin >> u >> v >> w;

        A[u].push_back({v, w});
    }

    q.push({0, K}); // weight , vertex
    D[K] = 0; // 최단거리 배열

    while (!q.empty())
    {
        edge cur = q.top(); // 거리가 최소인 노드의 weight , vertex
        q.pop();

        int cur_v = cur.second;
        if (visited[cur_v]) // 이미 방문한 노드는 큐에 다시 넣지 않음
            continue;

        visited[cur_v] = true;

        for (int i = 0; i < A[cur_v].size(); ++i)
        {
            edge temp = A[cur_v][i]; // vertex , weight
            int next_v = temp.first;
            int next_w = temp.second;

            if (D[next_v] > D[cur_v] + next_w) // next 로 이동하는게 더 가까운 경우, D 배열 업데이트
            {
                D[next_v] = next_w + D[cur_v];
                q.push({D[next_v], next_v});
            }
        }
    }

    for (int i = 1; i <= V; ++i)
    {
        if (visited[i])
            cout << D[i] << '\n';
        else
            cout << "INF" << '\n';
    }

    return 0;
}
