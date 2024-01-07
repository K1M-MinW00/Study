#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long min, max;
    cin >> min >> max;

    vector<long> A(10000001);

    for (int i = 2; i < 10000001; i++)
        A[i] = i;

    for (int i = 2; i <= sqrt(10000001); i++) // 에라토스테네스의 체
    {
        if (A[i] == 0)
            continue;
        for (int j = i + i; j < 10000001; j = j + i) // 배수 지우기
            A[j] = 0;
    }

    int cnt = 0;

    for (int i = 2; i < 10000001; i++)
    {
        if (A[i])
        {
            long tmp = A[i]; // 현재 소수

            while ((double)A[i] <= (double)max / (double)tmp)
            {
                if ((double)A[i] >= (double)min / (double)tmp)
                    cnt++;
                tmp *= A[i];
            }
        }
    }

    cout << cnt;
    return 0;
}
