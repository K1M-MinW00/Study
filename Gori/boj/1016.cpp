#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long min, max;
    cin >> min >> max;

    vector<bool> check(max - min + 1);

    for (long i = 2; i * i <= max; i++)
    {
        long pow = i * i; // 제곱수
        long start_index = min / pow;

        if (min % pow != 0)
            start_index++;

        for (long j = start_index; j * pow <= max; j++)
            check[(int)(j * pow) - min] = true; // 제곱수를 true 로 변경
    }

    int cnt = 0;

    for (int i = 0; i <= max - min; i++)
        if (!check[i]) // 제곱이 아닌 수 count 증가
            cnt++;

    cout << cnt;

    return 0;
}
