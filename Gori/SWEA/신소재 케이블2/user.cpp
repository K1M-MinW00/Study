// 문제 : https://swexpertacademy.com/main/code/codeBattle/problemDetail.do?contestProbId=AY063aRq97oDFASg&categoryId=AY06CVdK6wwDFASg&categoryType=BATTLE&battleMainPageIndex=1

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <tuple>

using namespace std;

struct info
{
    int id;
    int score;
};

bool operator<(const info &a, const info &b)
{
    if (a.score == b.score) // 점수가 같을 땐
        return a.id < b.id; // id 순으로 오름차순

    return a.score < b.score; // 점수 순으로 오름차순
}

set<info> st[3][2]; // mGrade , mGender
unordered_map<int, tuple<int, int, int>> student;

void init()
{
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 2; ++j)
            st[i][j].clear();

    student.clear();
    return;
}

int add(int mId, int mGrade, char mGender[7], int mScore) // 가장 높은 점수, 점수가 같다면 가장 큰 Id를 반환해야 하므로 begin이 아닌 end
{
    if (mGrade == 1)
    {
        if (mGender[0] == 'm')
        {
            st[0][0].insert({mId, mScore});
            student[mId] = {mGrade, 0, mScore};
            return st[0][0].rbegin()->id;
        }
        else
        {
            st[0][1].insert({mId, mScore});
            student[mId] = {mGrade, 1, mScore};
            return st[0][1].rbegin()->id;
        }
    }
    else if (mGrade == 2)
    {
        if (mGender[0] == 'm')
        {
            st[1][0].insert({mId, mScore});
            student[mId] = {mGrade, 0, mScore};
            return st[1][0].rbegin()->id;
        }
        else
        {
            st[1][1].insert({mId, mScore});
            student[mId] = {mGrade, 1, mScore};
            return st[1][1].rbegin()->id;
        }
    }
    else
    {
        if (mGender[0] == 'm')
        {
            st[2][0].insert({mId, mScore});
            student[mId] = {mGrade, 0, mScore};
            return st[2][0].rbegin()->id;
        }
        else
        {
            st[2][1].insert({mId, mScore});
            student[mId] = {mGrade, 1, mScore};
            return st[2][1].rbegin()->id;
        }
    }
}

int remove(int mId) // 삭제 후, 해당 student[]에서 가장 낮은 점수, 점수가 같다면 Id가 가장 작은 값 반환
{
    if (student.count(mId) == 0) // 학년과 성별 동일한 학생이 없을 때
        return 0;

    auto element = student[mId];
    int grade = get<0>(element);
    int gender = get<1>(element);
    int score = get<2>(element);

    st[grade - 1][gender].erase({mId, score}); // st 의 grade 는 0,1,2 로 표현, student 에 입력할 땐 1,2,3 으로 입력해서 차이 발생
    student.erase(mId);
    if (st[grade - 1][gender].empty()) // 학년과 성별 동일한 학생이 없을 때
        return 0;

    else
        return st[grade - 1][gender].begin()->id;
}

int query(int mGradeCnt, int mGrade[], int mGenderCnt, char mGender[][7], int mScore)
{
    info ret({0, 300001}); // 초기값을 score의 최대값인 300000 보다 크게, mScore 이상인 학생이 없으면 0 을 반환해야 하므로 id = 0

    for (int i = 0; i < mGradeCnt; ++i)
    {
        for (int j = 0; j < mGenderCnt; ++j)
        {
            if (mGender[j][0] == 'm')
            {
                auto it = st[mGrade[i] - 1][0].lower_bound({0, mScore});
                if (it != st[mGrade[i] - 1][0].end())
                {
                    if (*it < ret)
                        ret = *it;
                }
            }
            else // mGender[j][0]=='f'
            {
                auto it = st[mGrade[i] - 1][1].lower_bound({0, mScore});
                if (it != st[mGrade[i] - 1][1].end())
                {
                    if (*it < ret)
                        ret = *it;
                }
            }
        }
    }
    return ret.id; // 점수가 mScore 이상인 학생이 없을 때는 초기 값인 {0,300001} 의 id 인 0 이 반환
}
