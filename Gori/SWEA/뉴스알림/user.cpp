// 문제 : https://swexpertacademy.com/main/code/codeBattle/problemDetail.do?contestProbId=AYkpx926Py0DFASe&categoryId=AY06CVdK6wwDFASg&categoryType=BATTLE&battleMainPageIndex=1

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

#define N_MAX 30030
#define MAX 505

typedef pair<pair<int, int>, pair<int, bool>> news; // <time - nID> , <cID - deleted>

news arr[N_MAX];				// memory pool
vector<news *> news_vec(N_MAX); // nid -> 해당 뉴스 정보
vector<news *> user_vec[MAX];	// uid -> 유저가 받은 news
vector<int> channel_vec[MAX];	// cid -> 채널 구독하고 있는 uid

unordered_map<int, int> news_map;
unordered_map<int, int> user_map;
unordered_map<int, int> channel_map;

int n, u, c;
struct cmp
{
	bool operator()(const news *a, const news *b)
	{
		if (a->first.first == b->first.first)
			return a->first.second > b->first.second;
		return a->first.first > b->first.first;
	}
};
priority_queue<news *, vector<news *>, cmp> pq;

void init(int N, int K)
{
	news_map.clear();
	user_map.clear();
	channel_map.clear();

	n = u = c = 0;

	news_vec.clear();
	for (int i = 0; i < MAX; ++i)
	{
		user_vec[i].clear();
		channel_vec[i].clear();
	}

	pq = {};
}

void send(int time)
{
	while (!pq.empty() && pq.top()->first.first <= time)
	{
		news *temp = pq.top();
		pq.pop();

		if (temp->second.second == true)
			continue;

		for (int i : channel_vec[temp->second.first])
			user_vec[i].push_back(temp);
	}
}
void registerUser(int mTime, int mUID, int mNum, int mChannelIDs[])
{
	send(mTime);

	int uid = user_map[mUID];
	if (uid == 0)
		uid = user_map[mUID] = ++u;

	for (int i = 0; i < mNum; ++i)
	{
		int cid = channel_map[mChannelIDs[i]];
		if (cid == 0)
			cid = channel_map[mChannelIDs[i]] = ++c;

		channel_vec[cid].push_back(uid);
	}
}

int offerNews(int mTime, int mNewsID, int mDelay, int mChannelID)
{
	int nid = news_map[mNewsID] = ++n;
	int cid = channel_map[mChannelID];

	news *temp = &arr[n];

	temp->first.first = mTime + mDelay;
	temp->first.second = mNewsID;
	temp->second.first = cid;
	temp->second.second = false;

	pq.emplace(temp);
	news_vec[nid] = temp;

	return channel_vec[cid].size();
}

void cancelNews(int mTime, int mNewsID)
{
	send(mTime);
	int nid = news_map[mNewsID];

	news_vec[nid]->second.second = true;
}

int checkUser(int mTime, int mUID, int mRetIDs[])
{
	send(mTime);

	int uid = user_map[mUID];
	vector<news *> *nList = &user_vec[uid];

	int ret = 0;

	for (int i = nList->size(); i > 0; i--)
	{
		news *temp = (*nList)[i - 1];

		if (temp->second.second == true)
			continue;

		if (ret < 3)
			mRetIDs[ret] = temp->first.second;
		ret++;
	}

	nList->clear();

	return ret;
}
