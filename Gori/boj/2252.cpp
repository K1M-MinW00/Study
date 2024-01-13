#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> A;
    vector<int> D;

    A.resize(N + 1);
    D.resize(N + 1);

    int s, e;

    for (int i = 0; i < M; i++)
    {
        cin >> s >> e;
        A[s].push_back(e);
        D[e]++;
    }

    queue<int> q;

    for (int i = 1; i <= N; i++)
    {
        if (D[i] == 0) // 진입 차수 배열의 값이 0인 노드를 큐에 삽입
            q.push(i);
    }

    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        cout << now << ' ';
        for (int next : A[now])
        {
            D[next]--;
            if (D[next] == 0)
                q.push(next);
        }
    }

    return 0;
}
