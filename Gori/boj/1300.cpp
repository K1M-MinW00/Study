#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long N, K;
    cin >> N >> K;

    long start = 1, end = K;
    long ans = 0;

    while (start <= end)
    {
        long mid = (start + end) / 2;
        long cnt = 0;

        for (int i = 1; i <= N; i++)
        {
            cnt += min(mid / i, N); // 중앙값보다 작은 수 몇 개인지 계산
        }

        if (cnt < K) // 현재 중간값보다 작은 수의 개수가 K 보다 작음
            start = mid + 1;
        else // 현재 중간값보다 작은 수의 개수가 K 보다 크거나 같음
        {
            ans = mid;
            end = mid - 1;
        }
    }
    cout << ans;
}
