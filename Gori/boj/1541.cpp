#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<string> split(string input, char delimiter);
int mySum(string a);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string exp;
    cin >> exp;
    vector<string> str = split(exp, '-');

    int answer = 0;

    for (int i = 0; i < str.size(); i++)
    {
        int temp = mySum(str[i]);
        if (i == 0)
            answer += temp;
        else
            answer -= temp;
    }

    cout << answer;

    return 0;
}

vector<string> split(string input, char delimiter) // delimiter 을 구분자로 잘라 벡터에 저장하여 반환
{
    vector<string> result;
    stringstream mystrea(input);
    string splitdata;

    // 들어온 문자열을 구분자 단위로 저장
    while (getline(mystrea, splitdata, delimiter))
        result.push_back(splitdata);

    return result;
}

int mySum(string a)
{
    int sum = 0;
    vector<string> temp = split(a, '+'); // a 에 있는 수식을 '+' 로 구분

    for (int i = 0; i < temp.size(); i++)
        sum += stoi(temp[i]); // string 값을 int 형으로 반환하여 더하기

    return sum;
}
