#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> trueP;
vector<vector<int>> party;
int result;

void union_func(int a, int b);
int find_func(int a);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, t;
    cin >> n >> m >> t;

    trueP.resize(t);

    for (int i = 0; i < t; i++)
        cin >> trueP[i];

    party.resize(m);

    for (int i = 0; i < m; i++)
    {
        int party_size;
        cin >> party_size;

        for (int j = 0; j < party_size; j++)
        {
            int temp;
            cin >> temp;
            party[i].push_back(temp);
        }
    }

    parent.resize(n + 1);

    for (int i = 1; i <= n; i++) // 대표 노드를 자기 자신으로 초기화
        parent[i] = i;

    for (int i = 0; i < m; i++)
    {
        int firstPeople = party[i][0];

        for (int j = 1; j < party[i].size(); j++)
            union_func(firstPeople, party[i][j]);
    }

    for (int i = 0; i < m; i++)
    {
        bool isPossible = true;
        int cur = party[i][0];
        int find_cur = find_func(cur);
        for (int j = 0; j < t; j++)
        {
            if (find_cur == find_func(trueP[j]))
            {
                isPossible = false;
                break;
            }
        }
        if (isPossible) // 가능한 경우
            result++;
    }

    cout << result;

    return 0;
}

int find_func(int a)
{
    if (a == parent[a])
        return a;
    else
        return parent[a] = find_func(parent[a]);
}

void union_func(int a, int b)
{
    a = find_func(a);
    b = find_func(b);

    if (a != b)
        parent[b] = a;
}
