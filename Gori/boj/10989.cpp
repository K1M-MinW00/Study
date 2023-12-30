#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int cnt[10001] = {0};
    int num = 0;
    for (int i = 1; i <= N; i++)
    {
        cin >> num;
        cnt[num]++;
    }

    for (int i = 0; i <= 10000; i++)
    {
        if (cnt[i] != 0)
        {
            for (int j = 0; j < cnt[i]; j++)
                cout << i << endl;
        }
    }
    return 0;
}
