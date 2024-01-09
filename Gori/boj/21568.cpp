#include <iostream>
#include <vector>

using namespace std;

long gcd(long a, long b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
vector<long> execute(long a, long b) // 확장 유클리드 호제법
{
    vector<long> ret(2);

    if (b == 0)
    {
        ret[0] = 1;
        ret[1] = 0;
        return ret;
    }
    else
    {
        long q = a / b;
        vector<long> v = execute(b, a % b);
        ret[0] = v[1];
        ret[1] = v[0] - v[1] * q;
        return ret;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long A, B, C;
    cin >> A >> B >> C;

    long AB_gcd = gcd(A, B);

    if (C % AB_gcd != 0)
    {
        cout << -1 << endl;
        return 0;
    }

    else
    {
        int mok = (int)(C / AB_gcd);
        vector<long> ret = execute(A, B);
        cout << ret[0] * mok << ' ' << ret[1] * mok;
    }
}
