#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool isPalindrome(int prime) // 팰린드롬 수 : 어떤 수와 그 수의 숫자 순서를 뒤집은 수가 일치하는 수
{
    string num = to_string(prime);

    int s = 0;
    int e = num.length() - 1;

    while (s < e)
    {
        if (num[s] != num[e])
            return false;

        s++;
        e--;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<long> A(10000001);

    for (int i = 2; i < 10000001; i++)
        A[i] = i;

    for (int i = 2; i <= sqrt(10000001); i++) // 에라토스테네스의 체
    {
        if (A[i] == 0)
            continue;

        for (int j = i + i; j < 10000001; j = j + i)
            A[j] = 0;
    }

    int i = N;

    while (1)
    {
        if (A[i]) // N 부터 1씩 증가하면서 소수이면서 팰린드롬 수인 숫자 찾기
        {
            int prime = A[i];
            if (isPalindrome(prime))
            {
                cout << prime;
                break;
            }
        }
        i++;
    }

    return 0;
}
