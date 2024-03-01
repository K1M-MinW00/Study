// 문제 : https://swexpertacademy.com/main/code/codeBattle/problemDetail.do?contestProbId=AYJXv546ne8DFASv&categoryId=AYzyEMha298DFASg&categoryType=BATTLE&battleMainPageIndex=2

#include <iostream>
#include <vector>

using namespace std;

#define MAX_SIZE 26
#define SPECIAL '?'
#define EMPTY '\0'

struct Trie
{
	Trie *nodes[MAX_SIZE];
	int cnt;
	Trie()
	{
		for (register int i = 0; i < MAX_SIZE; ++i)
			nodes[i] = NULL;
		cnt = 0;
	}
	~Trie()
	{
		for (register int i = 0; i < MAX_SIZE; ++i)
		{
			if (nodes[i] !=  NULL)
			{
				delete nodes[i];
				nodes[i] = NULL;
			}
		}
	}
};

Trie *root;

void init()
{
	delete root;
	root = new Trie();
}

int add(char str[])
{
	Trie *cur = root;

	for (register int i = 0; str[i]; ++i)
	{
		int num = str[i] - 'a';
		if (cur->nodes[num] == NULL)
			cur->nodes[num] = new Trie();

		cur = cur->nodes[num];
	}

	return ++cur->cnt;
}

int remove(char *str)
{
	vector<Trie*> cur;
	cur.push_back(root);

	for (register int i = 0; str[i]; ++i)
	{
		char c = str[i];
		vector<Trie*> next;
		next.reserve(60000);
		if (c == SPECIAL)
		{
			for (Trie* node : cur)
			{
				for (register int j = 0; j < MAX_SIZE; ++j)
				{
					if (node->nodes[j] != NULL)
						next.emplace_back(node->nodes[j]);
				}
			}
		}
		else if(c==EMPTY)
			return 0;
		
		else
		{
			for (Trie* node : cur)
			{
				if (node->nodes[c-'a'] != NULL)
					next.emplace_back(node->nodes[c-'a']);
			}
		}

		cur = next;
	}

	int rm_cnt = 0;
	for (Trie* node : cur)
	{
			rm_cnt += node->cnt;
			node->cnt = 0;
	}

	return rm_cnt;
}

int search(char *str)
{
	vector<Trie*> cur;
	cur.push_back(root);

	for (register int i = 0; str[i]; ++i)
	{
		char c = str[i];
		vector<Trie*> next;
		next.reserve(60000);
		if (c == SPECIAL)
		{
			for (Trie* node : cur)
			{
				for (register int j = 0; j < MAX_SIZE; ++j)
				{
					if (node->nodes[j] != NULL)
						next.emplace_back(node->nodes[j]);
				}
			}
		}
		else if(c == EMPTY)
			return 0;
		else
		{
			for (Trie* node : cur)
			{
				if (node->nodes[c-'a'] != NULL)
					next.emplace_back(node->nodes[c-'a']);
			}
		}

		cur = next;
	}

	int sc_cnt = 0;
	for (Trie* node : cur)
		sc_cnt += node->cnt;

	return sc_cnt;
}
