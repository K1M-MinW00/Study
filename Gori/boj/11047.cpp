#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,K;
    cin >> N >> K;
    vector<int> A(N,0);

    for(int i=0;i<N;i++)
        cin >> A[i];

    int cnt=0;
    
    for(int i = N-1;i>=0;i--)
    {
        if(A[i] <=K)
        {
            cnt += (K/A[i]);
            K %= A[i];
        }
    }

    cout << cnt;
}
