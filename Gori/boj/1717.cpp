#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

int find_func(int a);
void union_func(int a, int b);
bool check_same(int a, int b);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    parent.resize(n + 1);

    for (int i = 0; i < n + 1; i++) // 대표 노드를 자기 자신으로 초기화
        parent[i] = i;

    int op, a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> op >> a >> b;

        if (op == 0) // Union 연산
        {
            union_func(a, b);
        }
        else if (op == 1) // Find 연산
        {
            bool result = check_same(a, b);
            if (result)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

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

bool check_same(int a, int b) // 두 원소가 같은 집합인지 확인
{
    a = find_func(a);
    b = find_func(b);

    if (a == b)
        return true;
    else
        return false;
}
