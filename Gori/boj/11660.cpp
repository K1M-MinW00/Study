#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;

    vector<vector<int>> a(n+1,vector<int>(n+1,0)); // 기존 배열
    vector<vector<int>> d(n+1,vector<int>(n+1,0)); // 합 저장할 배열

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin >> a[i][j];
            d[i][j] = d[i][j-1] + d[i-1][j] - d[i-1][j-1] + a[i][j]; // 구간합
        }    
    }
    
    int x1,y1,x2,y2;

    for(int i=0;i<m;i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;

        int result = d[x2][y2] - d[x1-1][y2] - d[x2][y1-1] + d[x1-1][y1-1];
        cout << result << endl ;
    }
    
    return 0;
}
