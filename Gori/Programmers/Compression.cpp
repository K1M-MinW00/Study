// 문제 : https://school.programmers.co.kr/learn/courses/30/lessons/17684

#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(string msg)
{
    vector<int> answer;
    unordered_map<string, int> d; // dictionary (key : 단어 , value : 색인 번호)

    for (int i = 0; i < 26; i++) // 초기 d 설정
    {
        char a = 'A' + i;
        string s;
        s += a;
        d.insert(make_pair(s, i + 1));
    }

    string w, wc;
    char c;
    int i = 0, j = 0;
    int value = 27; // 색인 번호는 Z : 26 이후로 추가

    while (i < msg.length())
    {
        w = "";
        c = msg[i];
        w += c;
        wc = w;
        j = i + 1;
        do // w , wc 를 찾는 코드
        {
            c = msg[j++]; // 다음 문자
            w = wc;
            wc += c;
            auto it = d.find(wc); // wc 가 d 안에 존재하는지 판별

            if (it == d.end()) // wc 가 d 에 존재하지 않으면, w 출력, wc 새로 추가
            {
                d.insert(make_pair(wc, value++));
                it = d.find(w); // wc 이전 단어인 w 는 d 안에 존재하므로 그 색인 번호를 출력
                answer.push_back(it->second);
                break;
            }
            // 존재하면 다음 문자를 추가한 단어도 있는지 계속 확인
        } while (1);

        i = j - 1; // wc 이전인 w 까지 출력했으므로 c 가 다음 단어의 첫 문자가 됨
    }

    return answer;
}
