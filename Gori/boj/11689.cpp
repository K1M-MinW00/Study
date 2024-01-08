#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long n;
    cin >> n;

    long result = n;

    for (long p = 2; p <= sqrt(n); p++)
    {
        if (n % p == 0) // p 가 소인수인지 확인
        {
            result = result - (result / p);
            while (n % p == 0) // 소인수가 2^7 * 11 * 13 이면, 현재 p 가 2일 때 n을 11 * 13 으로 변경
                n /= p;
        }
    }

    if (n > 1)                        // 아직 소인수 구성이 남아있는 경우
        result = result - result / n; // 반복문에서 제곱근까지만 탐색했기 때문에 1개의 소인수가 누락되는 케이스

    cout << result;

    return 0;
}
