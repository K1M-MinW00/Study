// 문제 : https://www.acmicpc.net/problem/1854

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> edge;

static int N,M,K;
static int A[1001][1001];
static priority_queue<int> D[1001];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;
 
    for (int i = 0; i < M; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        A[u][v] = w;
    }

    priority_queue<edge, vector<edge>, greater<edge>> pq; // K 번째로 최단거리를 찾으므로 내림차순, Max 값보다 작다면 pop 하고 새로 추가


    pq.push({0, 1}); // 거리 , 정점
    D[1].push(0);

    while (!pq.empty())
    {
        edge now = pq.top();
        pq.pop();

        for (int adj = 1; adj <= N; ++adj)
        {
            // 연결된 모든 노드에 대하여 검색하기
            if (A[now.second][adj] != 0)
            {
                // 저장된 경로가 K개가 안 될 경우 그냥 추가
                if (D[adj].size() < K)
                {
                    D[adj].push(now.first + A[now.second][adj]);
                    pq.push({now.first + A[now.second][adj], adj}); // 거리 , 정점
                }
                else if (D[adj].top() > now.first + A[now.second][adj]) // 저장된 경로가 K개, 현재 가장 큰 값보다 작을 때만 추가
                {
                    D[adj].pop(); // 기존 큐에서 Max 값 먼저 삭제
                    D[adj].push(now.first + A[now.second][adj]);
                    pq.push({now.first + A[now.second][adj], adj});
                }
            }
        }
    }

    for (int i = 1; i <= N; ++i)
    {
        if (D[i].size() == K)
            cout << D[i].top() << '\n';
        else
            cout << -1 << '\n';
    }

    return 0;
}
