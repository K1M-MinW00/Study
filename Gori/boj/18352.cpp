#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> visited;
vector<vector<int>> A;
vector<int> answer;

void BFS(int X)
{
    queue<int> queue;
    queue.push(X);

    visited[X] = 0; // 도시 X 가 기준점

    while (!queue.empty())
    {
        int now_node = queue.front();
        queue.pop();
        for (int i : A[now_node])
        {
            if (visited[i] == -1) // 아직 방문하지 않음
            {
                visited[i] = visited[now_node] + 1; // now_node 로 부터 1칸 떨어져 있음
                queue.push(i);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, K, X, s, e;
    cin >> N >> M >> K >> X;

    A.resize(N + 1);
    visited.resize(N + 1, -1);

    for (int i = 0; i < M; i++)
    {
        cin >> s >> e;
        A[s].push_back(e);
    }

    BFS(X);

    for (int i = 0; i <= N; i++)
        if (visited[i] == K)
            answer.push_back(i);

    if (answer.empty())
        cout << -1 << endl;

    else
    {
        sort(answer.begin(), answer.end());

        for (int i : answer)
            cout << i << endl;
    }
}
