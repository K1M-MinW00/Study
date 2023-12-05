#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;

    vector<int> num;
    num.push_back(0);

    int x,sum=0;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        sum += x; // 벡터에 구간합 저장
        num.push_back(sum);
    }
    
    int begin, end;

    for(int i=0;i<m;i++)
    {
        cin >> begin >> end;

        int result = num[end]-num[begin-1]; // Ex : A[2 ~ 5] = S[5] - S[1]
        cout << result << endl ;
    }
    
    return 0;
}
