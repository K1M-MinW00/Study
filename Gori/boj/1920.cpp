#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int n, m;
vector<int> a;

bool binary_search(int target)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (target == a[mid])
            return true;

        if (target < a[mid])
        {
            high = mid - 1;
        }

        else if (target > a[mid])
        {
            low = mid + 1;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    a.resize(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int target;
        cin >> target;

        if (binary_search(target))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }

    return 0;
}
