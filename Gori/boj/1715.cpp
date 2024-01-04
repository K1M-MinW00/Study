#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    // priority_queue<자료형,Container,비교함수> : 선언한 자료형 변수들을 비교함수에 따라 정렬
    // priority_queue<자료형> : 선언한 자료형 변수들을 내림차순으로 정렬
    priority_queue<int, vector<int>, greater<int>> pq;
    int data;

    for (int i = 0; i < N; i++)
    {
        cin >> data;
        pq.push(data);
    }

    int data1 = 0, data2 = 0, sum = 0;

    while (pq.size() != 1)
    {
        data1 = pq.top();
        pq.pop();
        data2 = pq.top();
        pq.pop();

        sum += data1 + data2;
        pq.push(data1 + data2);
    }

    cout << sum;
    return 0;
}
