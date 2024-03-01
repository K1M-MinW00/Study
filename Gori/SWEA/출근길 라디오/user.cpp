// 문제 : https://swexpertacademy.com/main/code/codeBattle/problemDetail.do?contestProbId=AYdupcjKAR0DFASR&categoryId=AYzyEMha298DFASg&categoryType=BATTLE&battleMainPageIndex=2

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> type;
vector<int> tree;

int base;

void init(int N, int M, int mType[], int mTime[])
{
	base = 1;
	while (base < N - 1)
		base <<= 1;

	type.clear();
	tree.clear();

	tree.resize(base * 2);
	type.resize(M);

	for (int i = 0; i < N - 1; ++i)
	{
		tree[base + i] = mTime[i];
		type[mType[i]].push_back(i);
	}

	for (int i = base - 1; i > 0; --i)
		tree[i] = tree[2 * i] + tree[2 * i + 1];
}

void destroy()
{
}

void update(int mID, int mNewTime)
{
	int node = base + mID;
	tree[node] = mNewTime;

	while (node >>= 1)
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

int updateByType(int mTypeID, int mRatio256)
{
	int sum = 0;

	for (int i = 0; i < type[mTypeID].size(); ++i)
	{
		int node = type[mTypeID][i];
		int before = tree[base + node];
		int now = floor(before * mRatio256 / 256);
		update(node, now);
		sum += now;
	}

	return sum;
}

int calculate(int mA, int mB)
{
	int sum = 0;

	if (mA > mB)
		swap(mA, mB);
	mA += base;
	mB += base - 1;

	while (mA <= mB)
	{
		if (mA % 2 == 1)
			sum += tree[mA++];
		if (mB % 2 == 0)
			sum += tree[mB--];

		mA >>= 1;
		mB >>= 1;
	}

	return sum;
}
