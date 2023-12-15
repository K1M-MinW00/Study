#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> A(n,0);

    for(int i=0;i<n;i++)
        cin >> A[i];

    vector<char> r;
    stack<int> s;

    int num = 1; // 1 부터 오름차순
    bool result = true;

    for(int i=0;i<n;i++)
    {
        int su = A[i]; // 현재 수열의 수
        if(su >= num) // 현재 수열 값이 자연수보다 크거나 같을 때까지 자연수 1씩 증가시키며 스택에 push
        {
            while(su >= num)
            {
                s.push(num++);
                r.push_back('+');
            }
            s.pop(); 
            r.push_back('-');
        }
        else // 현재 수열값 < 자연수
        {
            int n = s.top();
            s.pop();

            if(n > su) // stack 제일 위에 있는 값이 수열 값이 아니라면, 실패
            {
                cout << "NO";
                result = false;
                break;
            }
            else
            {
                r.push_back('-');
            }
        }
    }

    if(result)
    {
        for(int i=0;i<r.size();i++)
            cout << r[i] << ' ';
    }
}
