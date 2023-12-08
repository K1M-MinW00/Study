#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int sum = 1;
    int cnt = 1; // N = N

    int start = 1;
    int end = 1;

    while(end !=n)
    {
        if(sum==n) // 경우의 수
        {
            cnt++;
            end++;
            sum += end;
        }
        else if(sum > n) // 현재 합이 답보다 클 때
        {
            sum -= start;
            start++;
        }
        else // 현재 합이 답보다 작을 때
        {
            end++;
            sum += end;
        }
    }

    cout << cnt;
    return 0;
}
