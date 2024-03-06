// 문제 : https://swexpertacademy.com/main/code/codeBattle/problemDetail.do?contestProbId=AY0KzZRaK14DFASg&categoryId=AY06CVdK6wwDFASg&categoryType=BATTLE&battleMainPageIndex=1

#include <iostream>
#include <vector>
#include <unordered_map>

#define MAX_SIZE 9005
using namespace std;

struct node
{
    int parent, left, right;
    int total, cnt;

    node()
    {
        parent = left = right = -1;
        total = cnt = 0;
    }

    node(int num, int pid)
    {
        parent = pid;
        total = cnt = num;
        left = right = -1;
    }
};

unordered_map<int, int> um; // mId - index
int idx;
int m, k, group;

node tree[MAX_SIZE];

void init(int mId, int mNum)
{
    for (int i = 0; i < MAX_SIZE; ++i)
        tree[i] = node(0, -1);

    um.clear();

    idx = 1;
    um[mId] = idx;
    tree[idx] = node(mNum, -1);
    tree[idx].total = mNum;

    return;
}

void update_add(int pid, int num)
{
    while (pid != -1)
    {
        tree[pid].total += num;
        pid = tree[pid].parent;
    }
}

int add(int mId, int mNum, int mParent)
{
    int cid = um[mId] = ++idx;
    int pid = um[mParent];

    if (tree[pid].left != -1 && tree[pid].right != -1)
        return -1;

    if (tree[pid].left == -1)
        tree[pid].left = cid;
    else
        tree[pid].right = cid;

    tree[cid] = node(mNum, pid);

    update_add(pid, mNum);

    int result = tree[pid].total;

    return result;
}

void update_remove(int pid, int num)
{
    while (pid != -1)
    {
        tree[pid].total -= num;
        pid = tree[pid].parent;
    }
}

void update_remove2(int cid)
{
    int left = tree[cid].left;
    int right = tree[cid].right;

    if (left != -1)
    {
        tree[cid].left = -1;
        tree[left].parent = -1;
        update_remove2(left);
    }
    if (right != -1)
    {
        tree[cid].right = -1;
        tree[right].parent = -1;
        update_remove2(right);
    }
}

int remove(int mId)
{
    int cid = um[mId];
    int pid = tree[cid].parent;

    if (pid == -1)
        return -1;

    int result = tree[cid].total;
    update_remove(pid, result);

    if (tree[pid].left == cid)
        tree[pid].left = -1;
    else if (tree[pid].right == cid)
        tree[pid].right = -1;

    tree[cid].parent = -1;
    update_remove2(cid);

    return result;
}

int solve(int id)
{
    if (group > m)
    {
        group = m + 1;
        return 0;
    }

    if (tree[id].cnt > k)
    {
        group = m + 1;
        return 0;
    }

    int cnt = tree[id].cnt;
    int left = 0;
    int right = 0;

    if (tree[id].left != -1)
        left = solve(tree[id].left);

    if (tree[id].right != -1)
        right = solve(tree[id].right);

    if (group <= m)
    {
        if (cnt + left > k)
        {
            ++group;
            left = 0;
        }

        if (cnt + right > k)
        {
            ++group;
            right = 0;
        }

        if (cnt + left + right > k)
        {
            ++group;
            if (left > right)
                left = 0;
            else
                right = 0;
        }

        return cnt + left + right;
    }

    return 0;
}

int reorganize(int M, int K)
{
    group = 1;
    m = M, k = K;
    solve(1);

    if (group <= m)
        return 1;
    else
        return 0;
}
