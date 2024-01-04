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

    priority_queue<int> positivePq;                            // 내림차순 , 제일 큰 양수끼리 묶음
    priority_queue<int, vector<int>, greater<int>> negativePq; // 오름차순 , 제일 작은 음수끼리 묶음
    int one = 0, zero = 0;

    int data;
    for (int i = 0; i < N; i++)
    {
        cin >> data;
        if (data == 0)
            zero++;
        else if (data == 1)
            one++;
        else if (data > 1)
            positivePq.push(data);
        else if (data < 0)
            negativePq.push(data);
    }

    int data1, data2;
    int sum = 0;

    // 제일 큰 2개 양수끼리 묶어서 처리
    while (positivePq.size() > 1)
    {
        data1 = positivePq.top();
        positivePq.pop();
        data2 = positivePq.top();
        positivePq.pop();
        sum += (data1 * data2);
    }

    // (제일 작은) 남은 양수 처리
    if (positivePq.size() != 0)
    {
        sum += positivePq.top();
        positivePq.pop();
    }

    // 제일 작은 음수끼리 묶어서 처리
    while (negativePq.size() > 1)
    {
        data1 = negativePq.top();
        negativePq.pop();
        data2 = negativePq.top();
        negativePq.pop();
        sum += (data1 * data2);
    }

    // (제일 큰) 남은 음수 처리
    if (negativePq.size() != 0)
    {
        if (zero == 0) // 0이 없다면 그냥 더하기
        {
            sum += negativePq.top();
            negativePq.pop();
        }
        // 있으면 0과 곱해서 삭제
    }

    sum += one; // 1은 곱하는 것보다 더하는 것이 결과값이 커짐

    cout << sum;
    return 0;
}
