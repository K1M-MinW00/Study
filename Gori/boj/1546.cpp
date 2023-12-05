#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    int n,x;
    cin >> n;

    vector<int> num;
    int max;
    for(int i=0;i<n;i++)
    {
        cin >> x;
        if(max < x)
            max = x;
        num.push_back(x); 
    }

    double sum = 0;
    for(int i=0;i<n;i++)
    {
        double score = double(num[i]) / double(max) * 100;
        sum += score;
    }

    double avg = sum / n;

    cout << avg;
    return 0;
}
