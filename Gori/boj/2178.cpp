#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> A; // 미로 저장할 2차원 벡터
vector<vector<bool>> visited; // 방문한지 안한지 방문할 2차원 벡터

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; // R L U D 방향
static int N, M;
void BFS(int i, int j);

int main()
{
    ios ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    A.resize(N + 2);
    A[0].resize(M + 2, 0);
    A[N + 1].resize(M + 2, 0);

    visited.resize(N + 2);
    visited[0].resize(M + 2, false);
    visited[N + 1].resize(M + 2, false);

    for (int i = 1; i <= N; i++)
    {
        string s;
        cin >> s;
        A[i].resize(M + 2, 0); // 2차원 벡터 미로 주변을 0으로 둘러쌈
        visited[i].resize(M + 2, false);
      
        for (int j = 0; j < M; j++)
        {
            A[i][j + 1] = s[j] - '0';
        }
    }

    BFS(1, 1); // 출발

    cout << A[N][M];

    return 0;
}

void BFS(int i, int j)
{
    queue<pair<int, int>> mq;
    mq.push(make_pair(i, j));

    while (!mq.empty())
    {
        int now[2]; // 현재 x,y 위치
        now[0] = mq.front().first;
        now[1] = mq.front().second;
        mq.pop();
        visited[i][j] = true;

        for (int k = 0; k < 4; k++)
        {
            int x = now[0] + dir[k][0];
            int y = now[1] + dir[k][1];

            if (A[x][y] != 0 && !visited[x][y]) // 다음 방향이 벽인지 갈 수 있는 길인지, 방문했는지 안했는지 확인
            {
                visited[x][y] = true;
                A[x][y] = A[now[0]][now[1]] + 1;
                mq.push(make_pair(x, y));
            }
        }
    }
}
