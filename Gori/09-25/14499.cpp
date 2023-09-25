#include <iostream>
#include <vector>

using namespace std;

int n, m, x, y, k;
int map[21][21];
int order[1001];
vector<int> dice(7);

int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, -1, 1};

void roll(int order)
{
    switch (order)
    {
    case 1:
        dice = {0, dice[4], dice[2], dice[1], dice[6], dice[5], dice[3]};
        break;
    case 2:
        dice = {0, dice[3], dice[2], dice[6], dice[1], dice[5], dice[4]};
        break;
    case 3:
        dice = {0, dice[5], dice[1], dice[3], dice[4], dice[6], dice[2]};
        break;
    case 4:
        dice = {0, dice[2], dice[6], dice[3], dice[4], dice[1], dice[5]};
        break;
    default:
        break;
    }
}

int main()
{

    cin >> n >> m >> y >> x >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }

    for (int i = 0; i < k; i++)
        cin >> order[i];

    for (int i = 0; i < k; i++)
    {
        int mx = dx[order[i]];
        int my = dy[order[i]];

        if (y + my >= n || y + my < 0 || x + mx >= m | x + mx < 0)
            continue; // 주사위가 map 영역 밖일 때

        x += mx;
        y += my;

        roll(order[i]);
        cout << dice[1] << '\n';

        if (map[y][x] == 0)
            map[y][x] = dice[6]; // 주사위 아랫면 숫자를 위치한 칸에 복사
        else
        {
            dice[6] = map[y][x];
            map[y][x] = 0;
        }
    }

    return 0;
}
