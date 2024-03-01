// 문제 : https://swexpertacademy.com/main/code/codeBattle/problemDetail.do?contestProbId=AYzTSUeae9UDFAQ9&categoryId=AYzyEMha298DFASg&categoryType=BATTLE&battleMainPageIndex=2


deque<char> dq;
vector<int> h_cnt(1 << 20);
bool r;

void append_back()
{
	int h = 0;

	for (int i = (int)dq.size() - 1, j = 0; i >= 0 && j < 4; --i, ++j)
	{
		h *= 27;
		h += (dq[i] - 'a' + 1);
		h_cnt[h]++;
	}
}

void append_front()
{
	int h = 0;
	int m = 1;
	for (int i = 0; i < 4 && i < (int)dq.size(); ++i)
	{
		h += m * (dq[i] - 'a' + 1);
		m *= 27;
		h_cnt[h]++;
	}
}

void cut_back()
{
	int h = 0;

	for (int i = (int)dq.size() - 1, j = 0; i >= 0 && j < 4; --i, ++j)
	{
		h *= 27;
		h += (dq[i] - 'a' + 1);
		h_cnt[h]--;
	}
}

void cut_front()
{
	int h = 0;
	int m = 1;
	for (int i = 0; i < 4 && i < (int)dq.size(); ++i)
	{
		h += m * (dq[i] - 'a' + 1);
		m *= 27;
		h_cnt[h]--;
	}
}

void init(char mStr[])
{
	dq.clear();
	fill(h_cnt.begin(), h_cnt.end(), 0);

	r = false;

	for (int i = 0; mStr[i] != '\0'; ++i)
	{
		dq.push_back(mStr[i]);
		append_back();
	}
}

void appendWord(char mWord[])
{
	if (r)
	{
		for (int i = 0; mWord[i] != '\0'; ++i)
		{
			dq.push_front(mWord[i]);
			append_front();
		}
	}
	else
	{
		for (int i = 0; mWord[i] != '\0'; ++i)
		{
			dq.push_back(mWord[i]);
			append_back();
		}
	}
}

void cut(int k)
{
	if (r)
	{
		for (int i = 0; i < k; ++i)
		{
			cut_front();
			dq.pop_front();
		}
	}

	else
	{
		for (int i = 0; i < k; ++i)
		{
			cut_back();
			dq.pop_back();
		}
	}
}

void reverse()
{
	r = !r;
}

int countOccurrence(char mWord[])
{
	int h = 0;

	if (r)
	{
		for (int i = 0; mWord[i] != '\0'; ++i)
		{
			h *= 27;
			h += (mWord[i] - 'a' + 1);
		}
	}
	else
	{
		int m = 1;
		for (int i = 0; mWord[i] != '\0'; ++i)
		{
			h += m * (mWord[i] - 'a' + 1);
			m *= 27;
		}
	}

	int answer = h_cnt[h];

	return answer;
}
