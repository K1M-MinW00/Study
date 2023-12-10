#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr.begin(), arr.end());

    int cnt = 0;
    for (int k = 0; k < n; k++)
    {
        int find = arr[k];
        int s = 0;
        int e = n - 1;

        while (s < e)
        {
            if (arr[s] + arr[e] == find)
            {
                if (s != k && e != k) // 서로 다른 두수의 합인지 확인
                {
                    cnt++;
                    break;
                }
                else if (s == k)
                {
                    s++;
                }
                else if (e == k)
                {
                    e--;
                }
            }
            else if (arr[s] + arr[e] < find)
            {
                s++;
            }
            else // arr[s]+arr[e] > find
            {
                e--;
            }
        }
    }
    cout << cnt;

    return 0;
}
