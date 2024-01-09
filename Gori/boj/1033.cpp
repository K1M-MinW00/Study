#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<tuple<int, int, int>> A[10];
long lcm;
bool visited[10];
long D[10];
long gcd(long a, long b);
void DFS(int node);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    lcm = 1;

    for (int i = 0; i < N - 1; i++)
    {
        int a, b, p, q;
        cin >> a >> b >> p >> q;

        A[a].push_back(make_tuple(b, p, q));
        A[b].push_back(make_tuple(a, q, p));

        lcm *= (p * q / gcd(p, q)); // 최소 공배수 업데이트
    }

    D[0] = lcm; // 최소 공배수 저장
    DFS(0); // DFS 를 통해서 모든 노드를 방문하며 각 노드의 값을 이전 노드의 값과 비율 계싼을 통해 계산
    long mgcd = D[0];

    for (int i = 1; i < N; i++)
        mgcd = gcd(mgcd, D[i]); // 모든 노드의 최대 공약수

    for (int i = 0; i < N; i++)
        cout << D[i] / mgcd << ' '; // 각 노드의 값을 모든 노드의 최대 공약수로 나눔

    return 0;
}

long gcd(long a, long b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void DFS(int node)
{
    visited[node] = true;

    for (auto i : A[node])
    {
        int next = get<0>(i);
        if (!visited[next])
        {
            D[next] = D[node] * get<2>(i) / get<1>(i);
            DFS(next);
        }
    }
}
