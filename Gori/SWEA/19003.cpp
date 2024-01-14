#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int N, M;
        cin >> N >> M;

        int cnt = 0;
        vector<string> A;
        string str;

        for (int i = 0; i < N; ++i)
        {
            cin >> str;

            if (str != string(str.rbegin(), str.rend()))
                A.push_back(str);
        }

        int size = A.size();
        if (size < N)
            cnt += 1;

        for (int i = 0; i < size; ++i)
        {
            string s = A.back();
            A.pop_back();

            if (find(A.begin(), A.end(), string(s.rbegin(), s.rend())) != A.end())
                cnt += 2;
        }

        cout << "#" << test_case << " " << cnt * M << '\n';
    }
    return 0;
}
