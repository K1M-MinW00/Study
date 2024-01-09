#include <string>
#include <vector>

using namespace std;

vector<bool> visited;
void DFS(int current, int n, vector<vector<int>> computers);

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    visited.resize(n);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            DFS(i, n, computers);
            answer++;
        }
    }
    return answer;
}

void DFS(int current, int n, vector<vector<int>> computers)
{
    visited[current] = 1;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0 && computers[current][i] == 1)
            DFS(i, n, computers);
    }
}
