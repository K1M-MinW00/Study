// 문제 : https://school.programmers.co.kr/learn/courses/30/lessons/87946?language=cpp

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int k, vector<vector<int>> dungeons)
{
    int answer = 0;
    sort(dungeons.begin(), dungeons.end());

    do
    {
        int remain = k;
        int cnt = 0;
        for (int i = 0; i < dungeons.size(); i++)
        {
            if (dungeons[i][0] <= remain)
            {
                remain -= dungeons[i][1];
                cnt++;
            }
        }
        answer = max(answer, cnt);
    } while (next_permutation(dungeons.begin(), dungeons.end()));

    return answer;
}
