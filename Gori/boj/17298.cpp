#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n,0);
    vector<int> ans(n,0);
    for(int i=0;i<n;i++)
        cin >> a[i];
    
    stack<int> st;
    st.push(0);

    for(int i=1;i<n;i++)
    {
        while(!st.empty() && a[st.top()] < a[i]) // st의 top 위치의 값이 a[i] 보다 작으면, 오큰수 (ex : a[0] < a[1])
        {
            ans[st.top()] = a[i]; // (ex : ans[0] = a[1];)
            st.pop(); // (ex : st에서 0 삭제)
        }
        st.push(i); // (ex : st에 새로운 값 1 추가)
    }

    while(!st.empty()) // st에 값이 남았을 경우
    {
        ans[st.top()] = -1;
        st.pop();
    }

    for(int i=0;i<n;i++)
        cout << ans[i] << ' ';

}
