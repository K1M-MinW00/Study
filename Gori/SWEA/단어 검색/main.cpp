// 문제 : https://swexpertacademy.com/main/code/codeBattle/problemDetail.do?contestProbId=AYJXv546ne8DFASv&categoryId=AYzyEMha298DFASg&categoryType=BATTLE&battleMainPageIndex=2

#include <iostream>
#include <vector>
#include <stdio.h>
#include <time.h>
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

using namespace std;
#include <stdio.h>

extern void init();
extern int add(char str[]);
extern int remove(char str[]);
extern int search(char str[]);

/////////////////////////////////////////////////////////////////////////

#define MAX_LEN 30
#define CMD_INIT 1
#define CMD_ADD 2
#define CMD_REMOVE 3
#define CMD_SEARCH 4

static bool run()
{
	int q;
	scanf("%d", &q);

	char str[MAX_LEN + 1];
	int cmd, ans, ret = 0;
	bool okay = false;

	for (int i = 0; i < q; ++i)
	{
		scanf("%d", &cmd);
		switch (cmd)
		{
		case CMD_INIT:
			init();
			okay = true;
			break;
		case CMD_ADD:
			scanf("%s %d", str, &ans);
			ret = add(str);
			if (ans != ret)
				okay = false;
			break;
		case CMD_REMOVE:
			scanf("%s %d", str, &ans);
			ret = remove(str);
			if (ans != ret)
				okay = false;
			break;
		case CMD_SEARCH:
			scanf("%s %d", str, &ans);
			ret = search(str);
			if (ans != ret)
				okay = false;
			break;
		default:
			okay = false;
			break;
		}
	}
	return okay;
}

int main()
{
	setbuf(stdout, NULL);
	freopen("sample_input.txt", "r", stdin);
	int TIME = 0;
	clock_t start = clock();
	int T, MARK;
	scanf("%d %d", &T, &MARK);

	for (int tc = 1; tc <= T; tc++)
	{
		int score = run() ? MARK : 0;
		printf("#%d %d\n", tc, score);
	}
	TIME += ((int)clock() - start) / (CLOCKS_PER_SEC / 1000);
    
	printf("TIME : %d ms\n", TIME); /* ms 단위로 출력 */
	return 0;
}
