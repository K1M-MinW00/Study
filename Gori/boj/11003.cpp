#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, L;
    cin >> N >> L;

    deque<pair<int,int>> dq; // (숫자, 인덱스) 형태의 윈도우 슬라이드

    for (int i = 0; i < N; i++)
    {
        int now;
        cin >> now;

        while(dq.size() && dq.back().first > now) // dq 안에 값이 있고, 맨 앞의 숫자가 방금 입력받은 숫자보다 작다면 삭제
        {
            dq.pop_back();
        }

        dq.push_back(make_pair(now,i)); // 방금 입력받은 (숫자, 인덱스) 삽입 (슬라이드를 오른쪽으로 이동했으므로 맨 뒤에 삽입)

        if(dq.front().second <= i - L) // 덱의 첫 번쨰 위치에서부터 L의 범위를 벗어난 값을 덱에서 제거
            dq.pop_front();

        cout << dq.front().first << ' ';
    }

    return 0;
}

// deque 덱 : 앞/뒤 둘다 노드를 삽입할 수 있음. push_front(), push_back(), pop_front(), pop_back() - 시간복잡도 O(1)
