#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

int dir[4][2] ={{1,0},{-1,0},{0,1},{0,-1}};
vector<vector<int>> A(100,vector<int>(100,0));
vector<vector<int>> dp(100,vector<int>(100,0));
vector<vector<bool>> visited(100,vector<bool>(100,false));

int N;

int bfs();

int main()
{
    int test_case;
    int T;
    cin >> T;

    for(test_case = 1; test_case <=T; test_case++)
    {
        fill(A.begin(),A.end(),vector<int>(100,0));
        fill(dp.begin(),dp.end(),vector<int>(100,0));
        fill(visited.begin(),visited.end(),vector<bool>(100,false)); // 초기화
        
        cin >> N;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                int tmp;
                scanf("%1d",&tmp);
                A[i][j] = tmp;
            }
        }

        cout << "#" << test_case << " " << bfs() << endl;
    }
    return 0;
}

int bfs()
{
    queue<pair<int,int>> q;
    visited[0][0] = true;
    dp[0][0]= 0;

    q.push(make_pair(0,0)); // 출발 정점

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int k=0;k<4;k++)
        {
            int nx = x + dir[k][0];
            int ny = y + dir[k][1];

            if(nx >=0 && nx < N && ny >=0 && ny < N) // 범위 안인지 확인
            {
                if(!visited[nx][ny] || dp[nx][ny] > dp[x][y]+A[nx][ny]) // 아직 방문하지 않았거나
                // 현재 위치의 중첩 값과 갈 곳의 위치 값의 합이 갈 곳의 중첩 값보다 작을 때 갱신
                {
                    visited[nx][ny] = true;
                    dp[nx][ny] = dp[x][y] + A[nx][ny];
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
    return dp[N-1][N-1];
}
