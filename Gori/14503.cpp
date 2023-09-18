// https://www.acmicpc.net/problem/14503

#include <iostream>
#include <algorithm>
using namespace std;

int cnt = 0;
int **room;

void move(int r, int c, int d)
{

    while (1) // 칸이 청소되지 않음 : 0 , 청소 : -1 , 벽 : 1
    {
        if (room[r][c] == 0) // 현재 칸이 아직 청소되지 않은 경우
        {
            cnt++;
            room[r][c] = -1; // 현재 칸 청소
        }

        if (room[r - 1][c] != 0 && room[r][c + 1] != 0 && room[r + 1][c] != 0 && room[r][c - 1] != 0) // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우
        {
            if (d == 0 && room[r + 1][c] != 1) // 바라보는 방향을 유지하고, 뒤로 후진할 수 있다면 (뒤가 벽이 아니라면) ?
                r = r + 1;                     // 한 칸 후진하고, 1번으로 돌아가기
            else if (d == 1 && room[r][c - 1] != 1)
                c = c - 1; // 한 칸 후진
            else if (d == 2 && room[r - 1][c] != 1)
                r = r - 1; // 한 칸 후진
            else if (d == 3 && room[r][c + 1] != 1)
                c = c + 1;
            else // 뒤로 후진 할 수 없다면?
                break;
        }
        else // 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우
        {
            d = (d - 1);
            if (d < 0)
                d = d + 4;

            if (d == 0 && room[r - 1][c] == 0) // 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우
                r = r - 1;
            else if (d == 1 && room[r][c + 1] == 0)
                c = c + 1;
            else if (d == 2 && room[r + 1][c] == 0)
                r = r + 1;
            else if (d == 3 && room[r][c - 1] == 0)
                c = c - 1;
            // 한 칸 전진 후, 다시 1번으로 돌아가기
        }
    }

    printf("%d", cnt);
    return;
}

int main()
{
    int n, m, r, c, d;

    scanf("%d %d", &n, &m);
    scanf("%d %d %d", &r, &c, &d);

    room = new int *[n];
    for (int i = 0; i < n; i++)
        room[i] = new int[m];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &room[i][j]);
        }
    }

    move(r, c, d);

    return 0;
}
