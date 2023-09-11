//https://www.acmicpc.net/problem/1152

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string buf;
    getline(cin, buf); // 한 줄 입력 받기
    int cnt = 0;
    if (buf.length() <= 1 && buf[0] == ' ')
        cout << 0; // 공백으로 시작하거나 문자열이 없는 경우, 단어의 개수는 0
    else
    {
        cnt++; // 첫번째 단어
        for (int i = 0; i < buf.length(); i++)
        {
            if (buf[i] == ' ' && (i != 0 && i != buf.length() - 1)) // 공백으로 시작하거나 끝나는 경우를 제외하고, 공백의 개수를 세기
                cnt++;
        }
        cout << cnt;
    }

    return 0;
}

// EX) Input : The Curious Case of Benjamin Button, Output : 6
// EX) Input :  The first character is a blank, Output : 6
// EX) Input : The last character is a blank , Output : 6
