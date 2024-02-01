// 문제 : https://www.acmicpc.net/problem/1916

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> edge;

static vector<vector<edge>> A;
static vector<bool> visited;
static vector<int> D;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    A.resize(N + 1);
    visited.resize(N + 1, false);
    D.resize(N + 1, 2147483647);

    for (int i = 0; i < M; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        A[u].push_back({v, w});
    }

    int S, E;
    cin >> S >> E;

    priority_queue<edge, vector<edge>, greater<edge>> pq; // 연결된 노드 중 가장 적은 비용을 지닌 노드를 빠르게 찾기 위해

    pq.push({0, S}); // 거리 , 정점
    D[S] = 0;

    while (!pq.empty())
    {
        edge now = pq.top(); // 거리 , 정점
        pq.pop();

        int now_node = now.second;

        if (!visited[now_node]) // 방문하지 않은 노드
        {
            visited[now_node] = true;

            for (edge e : A[now_node]) // 인접 노드
            {
                if (!visited[e.first] && D[e.first] > D[now_node] + e.second) // 아직 방문하지 않음 && 기존 거리 보다 더 짧은 거리로 업데이트 가능
                {
                    D[e.first] = D[now_node] + e.second; // e : 도착점 - 가중치
                    pq.push({D[e.first], e.first}); // 거리 , 정점
                }
            }
        }
    }

    cout << D[E] << '\n';
    return 0;
}
