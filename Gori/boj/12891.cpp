#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> check(4, 0); // A C G T 조건 개수
vector<int> myArr(4, 0); // A C G T 지금 나의 배열에 대한 개수
int checkSecret = 0; // 만족한 조건 개수

void Add(char c);
void Remove(char c);

int main()
{
    int S, P;
    int result = 0;

    cin >> S >> P;

    string str;
    cin >> str;

    for (int i = 0; i < 4; i++) // A,C,G,T 에 대한 조건 입력
    {
        cin >> check[i];
        if (check[i] == 0) // 0 이면, 아무 것도 없는 상황에서 이미 만족하므로
            checkSecret++;
    }

    for (int i = 0; i < P; i++) // 첫번째 슬라이드
        Add(str[i]);

    if (checkSecret == 4) // 조건 만족했을 때
        result++;

    for (int i = P; i < S; i++) // 슬라이드를 한칸씩 이동
    {
        int j = i - P; // 맨 앞이었던 배열의 인덱스
        Add(str[i]);    // 다음 문자 추가
        Remove(str[j]); // 첫 문자 삭제

        if (checkSecret == 4)
            result++;
    }

    cout << result;
    return 0;
}

void Add(char c)
{
    switch (c)
    {
    case 'A':
        myArr[0]++;
        if (myArr[0] == check[0])
            checkSecret++;
        break;

    case 'C':
        myArr[1]++;
        if (myArr[1] == check[1])
            checkSecret++;
        break;

    case 'G':
        myArr[2]++;
        if (myArr[2] == check[2])
            checkSecret++;
        break;

    case 'T':
        myArr[3]++;
        if (myArr[3] == check[3])
            checkSecret++;
        break;
    }
}

void Remove(char c)
{
    switch (c)
    {
    case 'A':
        if (myArr[0] == check[0])
            checkSecret--;
        myArr[0]--;
        break;

    case 'C':
        if (myArr[1] == check[1])
            checkSecret++;
        myArr[1]++;
        break;

    case 'G':
        if (myArr[2] == check[2])
            checkSecret++;
        myArr[2]++;
        break;

    case 'T':
        if (myArr[3] == check[3])
            checkSecret++;
        myArr[3]++;
        break;
    }
}
