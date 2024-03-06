// 문제 : https://swexpertacademy.com/main/code/codeBattle/problemDetail.do?contestProbId=AY0Kg1LKJpEDFASg&categoryId=AY06CVdK6wwDFASg&categoryType=BATTLE&battleMainPageIndex=1

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int number = 0, idx = 0;
vector<int> parent(18001);
vector<int> sub(18001);
vector<int> degree(18001);
vector<bool> deleted(18001, false);

unordered_map<int, int> um; // id - index

void init(int N, int mId[], int mNum[])
{
	fill(deleted.begin(), deleted.end(), false);
	idx = 0, number = N;
	um.clear();

	for (int i = 0; i < N; ++i)
	{
		um[mId[i]] = idx++; // 복잡한 ID 를 인덱스로

		int root = um[mId[i]];

		parent[root] = -1;
		sub[root] = mNum[i];
		degree[root] = 0;
	}

	return;
}

int add(int mId, int mNum, int mParent)
{
	mParent = um[mParent]; // 인덱스로

	if (degree[mParent] == 3) // 이미 하위 부서가 3개 존재
		return -1;

	mId = um[mId] = idx++;
	parent[mId] = mParent;
	degree[mParent]++;

	sub[mId] = 0;
	degree[mId] = 0;

	while (1)
	{
		sub[mId] += mNum;
		mId = parent[mId];
		if (mId == -1) // mId ~ root 까지 진행 (parent[root] == -1 이 될 때 종료)
			break;
	}

	return sub[mParent]; // mParent 부서를 포함하여 그 아래 모든 부서의 인원 수 합 반환
}

int remove(int mId)
{
	if (um.count(mId) == 0) // mId 부서가 존재하지 않을 경우
		return -1;

	mId = um[mId];

	for (int i = mId; i != -1; i = parent[i]) // mId 위로 root 까지 삭제된 적이 있으면, 삭제할 수 없음
	{
		if (deleted[i] == true)
			return -1;
	}

	deleted[mId] = true;

	// degree[parent[mId]] -= (degree[mId] + 1); // mId 부서 아래의 모든 부서 삭제
	degree[parent[mId]]--;

	int below_sum = sub[mId];

	while (1) // 상위 부서에서 mId 아래 누적 합계만큼 빼주기
	{
		sub[mId] -= below_sum;
		mId = parent[mId];
		if (mId == -1) // mId ~ root 까지 진행 (parent[root] == -1 이 될 때 종료),
			break;
	}

	return below_sum; // mId 아래 모든 부서의 인원 수 합 반환
}

int distribute(int K)
{
	int max_v = 0;

	for (int i = 0; i < number; ++i)
		max_v = max(max_v, sub[i]); // 그룹들 중 최대 인원수 찾기

	int left = 0, right = min(max_v, K); // K 와 max_v 중 작은 값 설정
	int mid, sum;

	while (left < right) // left < right 시 무한 루프 발생
	{
		mid = (left + 1 + right) / 2;
		sum = 0;
		for (int i = 0; i < number; ++i)
			sum += min(mid, sub[i]); // mid 보다 인원 수가 작다면, 인원 수만큼

		if (sum < K) // 더 나눠줄 수 있음
			left = mid;

		else if (sum > K) // 덜 나눠줘야 함
			right = mid - 1;

		else
			return mid;
	}

	return left; // left = mid 에서 while(left + 1 < right) 조건을 만족하지 못했을 때, 그전의 mid 값인 left 가 최대값
}
