#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

static vector<vector<pair<int, int>>> A;
static vector<bool> visited;
static vector<int> m_distance;
void BFS(int node);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    A.resize(N + 1);

    for (int i = 0; i < N; i++)
    {
        int S;
        cin >> S;
        while (1)
        {
            int E, V; // 노드, 가중치
            cin >> E;
            if (E == -1)
                break;

            cin >> V;
            A[S].push_back(make_pair(E, V));
        }
    }

    m_distance = vector<int>(N + 1, 0);
    visited = vector<bool>(N + 1, false);

    BFS(1);
    int Max = 1; // 지름 : 임의의 노드에서 가장 긴 경로로 연결되 노드

    for (int i = 2; i <= N; i++)
    {
        if (m_distance[Max] < m_distance[i]) // 가장 거리가 먼 노드 Max 를 찾기 위해
            Max = i;
    }

    fill(m_distance.begin(), m_distance.end(), 0);
    fill(visited.begin(), visited.end(), false);
    BFS(Max);                                                   // 가장 거리가 먼 노드 Max 를 시작으로 BFS
    sort(m_distance.begin(), m_distance.end(), greater<int>()); // 내림차순 정렬
    cout << m_distance[0];

    return 0;
}

void BFS(int node)
{
    queue<int> mq;
    mq.push(node);
    visited[node] = true;

    while (!mq.empty())
    {
        int now_node = mq.front();
        mq.pop();

        for (auto i : A[now_node]) // auto 대신 pair<int,int> 가능
        {
            if (!visited[i.first]) // 방문하지 않았다면
            {
                visited[i.first] = true;                               // 방문
                mq.push(i.first);                                      // 큐 삽입
                m_distance[i.first] = m_distance[now_node] + i.second; // 가중치만큼 추가
            }
        }
    }
}
