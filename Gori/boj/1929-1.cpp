#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M,N;
    cin >> M >> N;

    vector<int>A(N+1);

    for(int i=2;i<=N;i++)
    {
        A[i] = i;
    }
    
    for(int i=2;i<=sqrt(N);i++) // 에라토스테네스의 체
    {
        if(A[i]==0) // 해당 수가 소수가 아닐 때
            continue;
        for(int j=i+i;j<=N;j=j+i) // 소수의 배수 값을 N까지 반복하여 해당 수가 소수가 아님을 표시
            A[j] = 0;
    }

    for(int i= M;i<=N;i++)
        if(A[i]) // 소수
            cout << A[i] << '\n';

    return 0;
}
