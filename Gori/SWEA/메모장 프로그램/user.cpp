// 문제 : https://swexpertacademy.com/main/code/codeBattle/problemDetail.do?contestProbId=AX4uQEB6N6wDFAQm&categoryId=AY06CVdK6wwDFASg&categoryType=BATTLE&battleMainPageIndex=1


#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

deque<char> dq[301];
int cnt[301][26];
pair<int, int> cursor;
int h, w, s;

void init(int H, int W, char mStr[])
{
    h = H;
    w = W;
    s = 0;
    cursor = {0, 0};

    for (int i = 0; i < 301; ++i) // 초기화
        dq[i].clear();
    memset(cnt,0,sizeof(cnt)); // 초기화
  
    for (int row = 0; row < h; ++row)
    {
        for (int col = 0; col < w; ++col)
        {
            if (mStr[s]!='\0')
            {
                cnt[row][mStr[s] - 'a']++; // 해당 row 의 알파벳 a~z (0~26) 까지 개수 저장
                dq[row].push_back(mStr[s++]); // 한 row 마다 최대 w개만큼 문자 삽입
            }
            else
                break;
        }
    }
}

void insert(char mChar)
{
    int cx = cursor.first;
    int cy = cursor.second;

    dq[cx].insert(dq[cx].begin() + cy, mChar);
    cnt[cx][mChar - 'a']++; 

    s++; // 전체 문자열 하나 증가
    if (cy + 1 == w) // 한 row 에 w 개 이상 일 때
        cursor = {cx + 1, 0}; // 다음 row + 1 로 이동하고 0 번째를 가리킴
    else
        cursor = {cx,cy+1};
  
    while (dq[cx].size() > w) // 뒤로 밀려난 경우 처리
    {
        char last_c = dq[cx].back();
        cnt[cx][last_c - 'a']--;
        dq[cx].pop_back();

        cnt[cx + 1][last_c - 'a']++;
        dq[cx + 1].push_front(last_c);
        ++cx;
    }
}

char moveCursor(int mRow, int mCol)
{
    int idx = (mRow - 1) * w + mCol - 1;

    if (s <= idx) // (mRow, mCol) 이 비어있는 경우, 다음 문자가 없는 경우
    {
        int row = s / w;
        int col = s % w;
        cursor = {row, col};
        return '$';
    }

    cursor = {mRow - 1, mCol - 1};
    return dq[mRow - 1][mCol - 1];
}

int countCharacter(char mChar)
{
    int row = cursor.first, col = cursor.second;
    int count = 0;
    int c_idx = mChar - 'a'; // a~z -> (0~26)
    if (col > 0) // row 가 0번째부터 시작하지 않는 경우, 따로 count
    {
        for (int i = col; i < dq[row].size(); ++i)
            if (dq[row][i] == mChar)
                ++count;
        ++row; // row 줄을 count 했으니 다음 row + 1 부터 확인
    }

    for (int i = row; i < h; ++i) // 미리 세아려둔 cnt 배열을 활용하여
        count += cnt[i][c_idx];

    return count;
}
