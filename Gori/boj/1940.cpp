#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int m;
    cin >> n >> m;
    vector<int> arr(n,0);

    for(int i=0;i<n;i++)
        cin >> arr[i];

    sort(arr.begin(),arr.end());

    int cnt = 0;
    int s = 0; // start
    int e = n-1; // end

    while(s<e)
    {
        if(arr[s]+arr[e]<m)
            s++;
        else if(arr[s]+arr[e]==m)
        {
            cnt++;
            s++;
            e--;
        }
        else // arr[s] + arr[e] > m
        {
            e--;
        }
    }

    cout << cnt << endl;
    return 0;
}
