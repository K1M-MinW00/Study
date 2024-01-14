#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<vector<int>> A(N + 1);
    vector<int> D(N + 1); // 진입 차수 배열
    vector<int> B(N + 1);

    for (int i = 1; i <= N; i++)
    {
        cin >> B[i]; // 건축 시간
        while (1)
        {
            int temp;
            cin >> temp;

            if (temp == -1)
                break;
            A[temp].push_back(i);
            D[i]++;
        }
    }

    queue<int> q; // 위상 정렬

    for (int i = 1; i <= N; i++)
    {
        if (D[i] == 0)
            q.push(i);
    }

    vector<int> result(N + 1);

    while (!q.empty())
    {
        int now = q.front();
        q.pop();

        for (int next : A[now])
        {
            D[next]--;
            result[next] = max(result[next], result[now] + B[now]);
            if (D[next] == 0)
                q.push(next);
        }
    }

    for (int i = 1; i <= N; i++)
        cout << result[i] + B[i] << endl;

    return 0;
}
