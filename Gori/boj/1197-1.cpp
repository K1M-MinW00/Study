// 문제 : https://www.acmicpc.net/problem/1197

#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> edge;

static vector<edge> g[10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E;
    cin >> V >> E;

    for (int i = 0; i < E; ++i)
    {
        int A, B, C;
        cin >> A >> B >> C;
        g[A].push_back({B, C});
        g[B].push_back({A, C});
    }

    int count = 0; // 최소 신장 트리의 엣지 개수는 N - 1 개
    int result = 0;

    vector<bool> visited(10001, false);

    priority_queue<edge> pq; // 내림차순 우선순위 큐
    pq.push({0, 1});

    while (!pq.empty())
    {
        edge cur = pq.top();
        int node = cur.second;
        int weight = -cur.first; // -를 통해 내림차순을 오름차순으로 계산하기

        pq.pop();

        if (visited[node])
            continue;

        result += weight;
        visited[node] = true;
        for (edge e : g[node])
        {
            int next_node = e.first;
            int next_weight = e.second;
            pq.push({-next_weight, next_node});
        }
    }
    
    cout << result;

    return 0;
}
