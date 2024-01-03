#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<int> A(N);
    int start = 0;
    int end = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        if (start < A[i])
            start = A[i];

        end += A[i];
    }

    while (start <= end)
    {
        int mid = (start + end) / 2; // 중앙값
        int sum = 0;
        int cnt = 0;

        for (int i = 0; i < N; i++) // 중앙값 크기로 모든 레슨을 저장할 수 있는지 확인
        {
            if (sum + A[i] > mid)
            {
                cnt++;
                sum = 0;
            }
            sum += A[i];
        }
        if (sum != 0) // sum 이 0이 아니면 마지막 블루레이가 필요하므로 cnt 수 올리기
            cnt++;
        if (cnt > M) // 현재 중앙값으로 모든 레슨 저장 불가
            start = mid + 1;
        else // 현재 중앙값으로 모든 레슨 저장 가능
            end = mid - 1;
    }

    cout << start;
}
