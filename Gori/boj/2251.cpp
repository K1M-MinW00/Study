#include <iostream>
#include <queue>

using namespace std;

int sender[] = {0, 0, 1, 1, 2, 2};
int receiver[] = {1, 2, 0, 2, 0, 1};

bool visited[201][201];
bool answer[201];
int now[3];

void BFS()
{
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));
    visited[0][0] = true;
    answer[now[2]] = true;

    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        int A = p.first;
        int B = p.second;
        int C = now[2] - A - B;

        for (int k = 0; k < 6; k++) // A->B, A->C, B->A, B->C, C->A, C->B 케이스
        {
            int next[] = {A, B, C};
            next[receiver[k]] += next[sender[k]];
            next[sender[k]] = 0;

            if (next[receiver[k]] > now[receiver[k]]) // 대상 물통의 용량보다 물이 많아 넘칠 때
            {
                next[sender[k]] = next[receiver[k]] - now[receiver[k]]; // 초과하는 만큼 다시 이전 물통에 넣음
                next[receiver[k]] = now[receiver[k]];                   // 대상 물통은 최대로 채움
            }

            if (!visited[next[0]][next[1]]) // A와 B의 물의 양을 통하여 방문 배열 체크
            {
                visited[next[0]][next[1]] = true;
                q.push(make_pair(next[0], next[1]));

                if (next[0] == 0) // A 의 물통이 비어 있을 때, C의 물의 용량을 정답 변수에 저장
                    answer[next[2]] = true;
            }
        }
    }
}

int main()
{
    cin >> now[0] >> now[1] >> now[2];

    BFS();

    for (int i = 0; i < 201; i++)
        if (answer[i])
            cout << i << " ";

    return 0;
}
