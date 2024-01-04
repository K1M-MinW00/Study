#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> A(N);

    for (int i = 0; i < N; i++)
    {
        cin >> A[i].second; // 회의 시작 시간
        cin >> A[i].first;  // 회의 종료 시간
    }

    sort(A.begin(), A.end()); // 종료 시간을 우선으로 정렬, 종료 시간이 같다면 시작 시간을 기준으로 정렬

    int cnt = 0;
    int end = 0;

    for (int i = 0; i < N; i++)
    {
        if (A[i].second >= end) // 다음 회의 시작시간과 현재 종료 시간이 겹치지 않는 회의가 있을 때
        {
            end = A[i].first; // 종료 시간 업데이트
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}
