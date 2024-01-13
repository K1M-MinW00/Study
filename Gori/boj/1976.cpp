#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find_func(int a);
void union_func(int a, int b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m; // 도시 개수 n , 여행 계획에 속한 도시들 수 m
    cin >> n >> m;
    parent.resize(n);

    for (int i = 0; i < n; i++) // 대표 노드를 자기 자신으로 초기화
        parent[i] = i;

    vector<vector<int>> city(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> city[i][j];
        }
    }

    vector<int> route(m);
    int r;
    for (int i = 0; i < m; i++) // 여행 도시 정보 저장
    {
        cin >> r;
        route[i] = r - 1;
    }

    for (int i = 0; i < n; i++) // 도시가 연결되면 Union 실행
    {
        for (int j = 0; j < n; j++)
        {
            if (city[i][j] == 1)
                union_func(i, j);
        }
    }

    int idx = find_func(route[0]); // 여행 계획 도시가 하나의 대표 도시로 연결되는지 확인
    bool result = true;

    for (int i = 1; i < m; i++)
    {
        if (idx != find_func(route[i]))
        {
            result = false;
            break;
        }
    }

    if (result)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}

int find_func(int a) // 대표 노드를 찾아 반환
{
    if (a == parent[a])
        return a;
    else
        return parent[a] = find_func(parent[a]); // 재귀 함수 형태로 구현
}

void union_func(int a, int b) // 대표 노드끼리 연결
{
    a = find_func(a);
    b = find_func(b);

    if (a != b)
        parent[b] = a;
}
