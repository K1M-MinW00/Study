// 문제 : https://www.acmicpc.net/problem/1068

#include <iostream>
#include <vector>

using namespace std;

static int N;
static vector<vector<int>> tree;
static int answer = 0;
static int deleteNode = 0;
static vector<bool> visited;
void DFS(int i);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    tree.resize(N + 1);
    visited.resize(N + 1);
    int root = 0;

    for (int i = 0; i < N; ++i)
    {
        int p;
        cin >> p;

        if (p == -1)
            root = i;
        
        else
        {
            tree[i].push_back(p);
            tree[p].push_back(i);
        }
    }

    cin >> deleteNode;
    if (deleteNode == root)
        cout << 0 << '\n';
    else
    {
        DFS(root);
        cout << answer << '\n';
    }

    return 0;
}

void DFS(int i)
{
    visited[i] = true;
    int child = 0;

    for (int node : tree[i])
    {
        if (!visited[node] && node != deleteNode)
        {
            child++;
            DFS(node);
        }
    }

    if (child == 0)
        answer++;
}
