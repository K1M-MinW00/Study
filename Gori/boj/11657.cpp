// 문제 : https://acmicpc.net/problem/11657

#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>
using namespace std;

typedef tuple<int, int, int> edge;

static int N, M;
static vector<long> D;
static vector<edge> edges;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    D.resize(N + 1, LONG_MAX);

    for (int i = 1; i <= M; ++i)
    {
        int s, e, w;
        cin >> s >> e >> w;
        edges.push_back(make_tuple(s, e, w));
    }

    D[1] = 0; // 출발 노드 1을 제외한 나머지 노드는 무한대로 초기화 상태

    for (int i = 1; i < N; ++i) // 2. 노드 개수 N - 1 번 만큼 반복
    {
        for (int j = 0; j < M; ++j) // 1. 모든 에지를 확인하며 정답 배열 업데이트
        {
            edge cur = edges[j];
            int start = get<0>(cur);
            int end = get<1>(cur);
            int weight = get<2>(cur);

            if (D[start] != LONG_MAX && D[end] > D[start] + weight) // 출발 노드가 무한대가 아님 && 종료 노드 값 < 출발 노드 값 + 가중치
                D[end] = D[start] + weight;                         // 업데이트 수행
        }
    }

    bool HasCycle = false; // 3. 음수 사이클 유무 확인

    for (int i = 0; i < M; ++i) // 모든 에지에 관해 다시 한번 거리 배열 업데이트
    {
        edge cur = edges[i];
        int start = get<0>(cur);
        int end = get<1>(cur);
        int weight = get<2>(cur);

        if (D[start] != LONG_MAX && D[end] > D[start] + weight) // 거리 배열이 한 번이라도 업데이트되면 음수 사이클은 존재
        {
            HasCycle = true;
            break;
        }
    }

    if (!HasCycle)
    {
        for (int i = 2; i <= N; ++i)
        {
            if (D[i] == LONG_MAX)
                cout << -1 << '\n';
            else
                cout << D[i] << '\n';
        }
    }
    else
        cout << -1 << '\n';

    return 0;
}
