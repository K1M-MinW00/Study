// https://www.acmicpc.net/problem/1764

#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int cnt = 0;

    vector<string> lname; // 듣도 못한 사람 
    vector<string> sname; // 보도 못한 사람

    string name;
    vector<string> fname; // 듣도 보도 못한 사람

    for (int i = 0; i < n; i++)
    {
        cin >> name;
        lname.push_back(name);
    }
    for (int j = 0; j < m; j++)
    {
        cin>>name;
        sname.push_back(name);
    }

    sort(lname.begin(),lname.end()); // 이름 순으로 정렬
    sort(sname.begin(),sname.end());

   set_intersection(lname.begin(),lname.end(),sname.begin(),sname.end(),back_inserter(fname));

    printf("%d\n",fname.size());
    for (string n : fname)
       cout << n << endl;
    return 0;
}

// EX)
/*
Input :
3 4
ohhenrie
charlie
baesangwook
obama
baesangwook
ohhenrie
clinton

Output :
2
baesangwook
ohhenrie
*/

/*
set_intersection : algorithm 헤더에 포함된 메소드 , 두 벡터 사이의 교집합을 찾기 위해 사용

#include <algorithm> //std::sort
#include <iostream> //std::cout
#include <string> //std::string
#include <vector> //std::vector

std::vector<std::string> intersection(std::vector<std::string> v1,
                                      std::vector<std::string> v2){
    std::vector<std::string> v3;

    std::sort(v1.begin(), v1.end());
    std::sort(v2.begin(), v2.end());

    std::set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),back_inserter(v3));
    return v3;
}

int main(){
    std::vector<std::string> v1 {"a","b","c"};
    std::vector<std::string> v2 {"b","c"};

    auto v3 = intersection(v1, v2);

    for(std::string n : v3)
        std::cout << n << ' ';
}
*/
