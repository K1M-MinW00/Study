// 문제 : https://www.acmicpc.net/problem/1197

#include <iostream>
#include <queue>

using namespace std;

typedef struct edge
{
    int s, e, v;
    bool operator>(const edge &temp) const
    {
        return v > temp.v;
    }
} edge;

static vector<int> parent;

int find_f(int a);
void union_f(int a, int b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E;
    cin >> V >> E;

    parent.resize(V + 1);
    priority_queue<edge, vector<edge>, greater<edge>> pq;

    for (int i = 0; i <= V; ++i)
        parent[i] = i;

    for (int i = 0; i < E; ++i)
    {
        int A, B, C;
        cin >> A >> B >> C;

        pq.push({A, B, C});
    }

    int count = 0; // 최소 신장 트리의 엣지 개수는 N - 1 개
    int result = 0;

    while (count < V - 1)
    {
        edge cur = pq.top();
        pq.pop();

        if (find_f(cur.s) != find_f(cur.e))
        {
            union_f(cur.s, cur.e);
            result += cur.v;
            ++count;
        }
    }

    cout << result;

    return 0;
}

int find_f(int a)
{
    if (a == find_f(a))
        return a;

    return parent[a] = find_f(parent[a]);
}

void union_f(int a, int b)
{
    a = find_f(a);
    b = find_f(b);

    if (a != b)
        parent[b] = a;
}
