// 문제 : https://swexpertacademy.com/main/code/codeBattle/problemDetail.do?contestProbId=AYkpzrGKP0sDFASe&categoryId=AY06CVdK6wwDFASg&categoryType=BATTLE&battleMainPageIndex=1

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct Result
{
    int top;
    int count;
};

int tree[21 << 1];
int min_tree[21 << 1];
int max_tree[21 << 1];
int col;
long long total;

void init(int C)
{
    total = 0;
    col = C;
    memset(tree, 0, sizeof(tree));
    memset(min_tree, 0, sizeof(min_tree));
    memset(max_tree, 0, sizeof(max_tree));
}

void update(int node, int ts, int te, int bs, int be, int h)
{
    // 트리구간과 블럭구간이 전혀 겹치지 않음
    if (te < bs || be < ts)
        return;

    // 블럭구간이 트리구간에 완전히 포함됨
    if (ts >= bs && be >= te)
    {
        tree[node] += h;
        min_tree[node] += h;
        max_tree[node] += h;
    }
    // 일부 겹침
    else
    {
        int m = (ts + te) / 2;
        update(node * 2, ts, m, bs, be, h);
        update(node * 2 + 1, m + 1, te, bs, be, h);
        min_tree[node] = min(min_tree[node * 2], min_tree[node * 2 + 1]) + tree[node];
        max_tree[node] = max(max_tree[node * 2], max_tree[node * 2 + 1]) + tree[node];
    }
}

Result dropBlocks(int mCol, int mHeight, int mLength)
{
    Result ret;
    total += (mHeight * mLength);

    // int node,int ts,int te,int bs,int be,int h
    update(1, 0, col - 1, mCol, mCol + mLength - 1, mHeight);
    int min_v = min_tree[1];
    int max_v = max_tree[1];

    ret.top = max_v - min_v;
    ret.count = (total - (long long)(min_v) * (long long)(col)) % 1000000;
    return ret;
}
