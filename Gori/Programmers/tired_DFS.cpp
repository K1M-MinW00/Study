// 문제 : https://school.programmers.co.kr/learn/courses/30/lessons/87946?language=cpp

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<bool> visited;
int answer = 0;

int dfs(int k, vector<vector<int>> dungeons, int cnt)
{
    answer = max(answer, cnt);
    for (int i = 0; i < dungeons.size(); i++)
    {
        if (visited[i] || dungeons[i][0] > k)
            continue;   // 방문했거나 남은 피로도 보다 높으면 Pass
        visited[i] = 1; // 방문
        dfs(k - dungeons[i][1], dungeons, cnt + 1);
        visited[i] = 0; // 초기화
    }

    return answer;
}

int solution(int k, vector<vector<int>> dungeons)
{
    visited.resize(dungeons.size()), false;

    answer = dfs(k, dungeons, 0);
    return answer;
}
