#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> A;
vector<bool> visited;
vector<int> answer;
void BFS(int node)
{
    queue<int> queue;
    queue.push(node); // 출발 노드
    visited[node] = true;

    while (!queue.empty())
    {
        int now_node = queue.front();
        queue.pop();
        for (int i : A[now_node])
        {
            if (visited[i] == false)
            {
                answer[i]++;
                visited[i] = true;
                queue.push(i);
            }
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    A.resize(N + 1);
    visited.resize(N + 1, false);
    answer.resize(N + 1);

    for (int i = 0; i < M; i++) // 인접 리스트 A에 그래프 데이터 저장
    {
        int s, e;
        cin >> s >> e;
        A[s].push_back(e);
    }

    for (int i = 1; i <= N; i++) // visited 배열 초기화, 모든 노드에서 BFS 실행
    {
        fill(visited.begin(), visited.end(), false);
        BFS(i);
    }

    int maxVal;
    for (int i = 1; i <= N; i++)
        maxVal = max(maxVal, answer[i]);

    for (int i = 1; i <= N; i++)
    {
        if (answer[i] == maxVal)
            cout << i << ' ';
    }

    return 0;
}
