#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
int n;

int main()
{
    ios:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    queue<int> q;
    for(int i=1;i<=n;i++)
        q.push(i);

    while(q.size()>1) // 카드 1장 남을 때까지
    {
        q.pop(); // 가장 위에 있는 카드 버리기
        q.push(q.front()); // 가장 위에 있는 카드를 가장 아래로 옮기기
        q.pop(); // 기존 가장 위에 있던 카드를 아래로 옮겼으니 삭제
    }

    cout << q.front();
    return 0;
}
