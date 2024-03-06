// 문제 : https://swexpertacademy.com/main/code/codeBattle/problemDetail.do?contestProbId=AY0K0SoqK8QDFASg&categoryId=AY06CVdK6wwDFASg&categoryType=BATTLE&battleMainPageIndex=1

#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

unordered_map<int, vector<pair<int, int>>> um;
map<int, int> range;

int total, n;
void init(int N)
{
	n = N;

	um.clear();
	range.clear();
	range.insert({-1, -1});
	range.insert({n, n});

	total = 0;
	um.reserve(12000);
}

int add(int mId, int mSize)
{
	if (total + mSize > n)
		return -1;

	total += mSize;

	int start = range.begin()->second + 1;

	for (auto f = range.begin(), s = next(range.begin()); s != range.end();)
	{
		int f_end = f->second + 1;
		int s_start = s->first - 1;

		if (s_start <= f_end + mSize - 1)
		{
			f->second = s->second;
			s = range.erase(s); // check
			mSize -= (s_start - f_end + 1);
			um[mId].push_back({f_end, s_start});
		}
		else
		{
			f->second = f_end + mSize - 1;
			um[mId].push_back({f_end, f_end + mSize - 1});
			break;
		}

		if (mSize == 0)
			break;
	}

	return start + 1;
}

int remove(int mId)
{
	int cnt = um[mId].size();

	for (pair<int, int> p : um[mId])
	{
		total -= p.second - p.first + 1;
		auto iter = --range.upper_bound(p.first);
		if (p.second < iter->second)
			range.insert({p.second + 1, iter->second});

		if (iter->first < p.first)
			iter->second = p.first - 1;

		else
			range.erase(iter);
	}

	um.erase(mId);
	return cnt;
}

int count(int mStart, int mEnd)
{
	--mStart, --mEnd;

	int cnt = 0;
	for (auto it = um.begin(); it != um.end(); ++it)
	{
		vector<pair<int, int>> &v = it->second;

		int left = 0, right = v.size();
		while (left < right)
		{
			int mid = left + (right - left) / 2;

			if (v[mid].first <= mStart)
				left = mid + 1;
			else
				right = mid;
		}

		if (right != 0 && v[right - 1].second >= mStart)
			cnt++;
		else if (right != v.size() && v[right].first <= mEnd)
			cnt++;
	}
	return cnt;
}
