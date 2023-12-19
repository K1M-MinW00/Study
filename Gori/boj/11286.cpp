#include <iostream>
#include <queue>

using namespace std;

struct compare{
    bool operator()(int a, int b)
    {
        int abs_a = abs(a);
        int abs_b = abs(b);

        if (abs_a == abs_b)
            return a > b; // 절댓값이 같을 때는 음수 먼저
        else
            return abs_a > abs_b; // 오름차순 정렬 , 기본이거나 < 일 때는 내림차순 정렬
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    priority_queue<int, vector<int>, compare> pq; // priority queue 를 정렬하기 위해 비교 클래스로 struct 를 구현

    for (int i = 0; i < N; i++)
    {
        int query;
        cin >> query;

        if(query == 0)
        {
            if(pq.empty())
                cout << "0" << endl;
            else
            {
                cout << pq.top() << endl;
                pq.pop();
            }
        }
        else
        {
            pq.push(query);
        }
    }

    return 0;
}
