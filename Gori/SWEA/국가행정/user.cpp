// 문제 : https://swexpertacademy.com/main/code/codeBattle/problemDetail.do?contestProbId=AY0Khw26JrQDFASg&categoryId=AY06CVdK6wwDFASg&categoryType=BATTLE&battleMainPageIndex=1

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

int base;
int tree[1 << 15];
int road[10000];
int *p;

struct compare
{
    bool operator()(const pair<int, int> &a, const pair<int, int> &b)
    {
        if (a.second == b.second)
            return a.first > b.first;
        return a.second < b.second;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

void init(int N, int mPopulation[])
{
    p = mPopulation;
    pq = priority_queue<pair<int, int>, vector<pair<int, int>>, compare>();

    base = 1;
    fill_n(road, 10000, 1);
    while (base < N - 1)
        base *= 2;

    for (int i = 0; i < N - 1; ++i)
    {
        int weight = mPopulation[i] + mPopulation[i + 1];
        pq.push({i, weight});
        tree[base + i] = weight;
    }

    for (int i = base - 1; i > 0; --i)
        tree[i] = tree[2 * i] + tree[2 * i + 1];

    return;
}

void update(int idx, int weight)
{
    int node = idx + base;
    tree[node] = weight;

    while (node >>= 1)
        tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int expand(int M)
{
    int weight;

    for (int i = 0; i < M; ++i)
    {
        int cur_idx = pq.top().first;
        int cur_weight = pq.top().second;
        pq.pop();

        road[cur_idx]++;
        weight = (p[cur_idx] + p[cur_idx + 1]) / road[cur_idx];
        pq.push({cur_idx, weight});
        update(cur_idx, weight);
    }

    return weight;
}

int calculate(int mFrom, int mTo)
{
    int sum = 0;

    if (mTo < mFrom)
        swap(mTo, mFrom);
    mFrom += base;
    mTo += base - 1;

    while (mFrom <= mTo)
    {
        if (mFrom % 2 == 1)
            sum += tree[mFrom++];
        if (mTo % 2 == 0)
            sum += tree[mTo--];

        mFrom >>= 1;
        mTo >>= 1;
    }

    return sum;
}

int divide(int mFrom, int mTo, int K)
{
    int left = 1, right = INT_MAX;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        int cnt = 0, idx = mFrom;

        for (cnt; cnt <= K; ++cnt)
        {
            if (idx > mTo)
                break;

            int person = 0;
            int p_idx = idx;
            while (p_idx <= mTo && person + p[p_idx] <= mid)
                person += p[p_idx++];

            idx = p_idx;
        }

        if (cnt <= K)
            right = mid;
        else
            left = mid + 1;
    }

    return right;
}
