#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int answer = 0;
    int n,m,temp;
    cin >> n >> m;

    vector<int> s(n,0); // 합 배열
    vector<int> c(m,0); // 나머지
    
    cin >> s[0];
    for(int i=1;i<n;i++)
    {
        cin >> temp;
        s[i] = s[i-1] + temp;
    }   
    
    for(int i=0;i<n;i++)
    {
        int r = s[i] % m; // 0 부터 i 번째까지 구간합
        if(r==0)
            answer++;
        c[r]++; // 나머지 저장
    }

    for(int i=0;i<m;i++)
    {
        if(c[i]>1)
            answer += c[i]*(c[i]-1)/2; // 나머지가 같은 인덱스 중 2개 선택
    }

    cout << answer ;
}
