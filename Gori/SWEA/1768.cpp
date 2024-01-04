#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define N 4
#define MAX_QUERYCOUNT 1000000

static int digits[N];
static int digits_c[10];

static int T;

extern void doUserImplementation(int guess[]);

static int querycount;

// the value of limit_query will be changed in evaluation
static const int limit_query = 2520;

typedef struct
{
    int strike;
    int ball;
} Result;

typedef struct st
{
    int g[4];
    struct st *next;
} NODE;

NODE HEAD;
NODE POOL[10000];
int pcnt;

int visit[10];
int list[4];

static bool isValid(int guess[])
{
    int guess_c[10];

    for (int count = 0; count < 10; ++count)
        guess_c[count] = 0;
    for (int idx = 0; idx < N; ++idx)
    {
        if (guess[idx] < 0 || guess[idx] >= 10 || guess_c[guess[idx]] > 0)
            return false;
        guess_c[guess[idx]]++;
    }
    return true;
}

// API : return a result for comparison with digits[] and guess[]
Result query(int guess[])
{
    Result result;

    if (querycount >= MAX_QUERYCOUNT)
    {
        result.strike = -1;
        result.ball = -1;
        return result;
    }

    querycount++;

    if (!isValid(guess))
    {
        result.strike = -1;
        result.ball = -1;
        return result;
    }

    result.strike = 0;
    result.ball = 0;

    for (int idx = 0; idx < N; ++idx)
        if (guess[idx] == digits[idx])
            result.strike++;
        else if (digits_c[guess[idx]] > 0)
            result.ball++;

    return result;
}
//-------------------------------------------------------------------------------
void DFS(int L) // [0,1,2,3] ~ [9,8,7,6] 배열을 Linked List 로 구현
{
    if (L > 3)
    {
        NODE *nd = &POOL[pcnt++]; // 메모리 풀 방식 (https://bloodstrawberry.tistory.com/29 참고) 

        /* 4개의 숫자를 모두 구했으므로, linked list g[4]에 저장 */
        for (int k = 0; k < 4; k++)
            nd->g[k] = list[k];
        nd->next = HEAD.next;
        HEAD.next = nd;

        return;
    }

    for (int i = 0; i < 10; i++)
    {
        if (visit[i])
            continue;

        list[L] = i; /* 임시 list에 숫자 0 ~ 9 중 하나 저장 */

        visit[i] = 1; /* 저장된 숫자는 다음에 못쓰게 체크 */
        DFS(L + 1);
        visit[i] = 0; /* DFS 종료 후에는 다시 사용할 수 있도록 초기화 */
    }
}

Result query2(int guess[], int nd[]) // 불필요한 후보군을 지우기 위해
{
    Result result;
    int check[10] = {0};

    result.strike = 0;
    result.ball = 0;

    for (int i = 0; i < 4; i++)
        check[guess[i]]++;

    for (int idx = 0; idx < N; ++idx)
        if (guess[idx] == nd[idx]) // 자리와 숫자가 같은 경우
            result.strike++;
        else if (check[nd[idx]] > 0) // 자리는 다르지만 숫자가 포함된 경우
            result.ball++;

    return result;
}

void deleteNode(int stk, int ball, int guess[]) //
{
    NODE *nd = &HEAD;

    while (nd->next)
    {
        Result result;
        int tmpstk, tmpball;

        result = query2(guess, nd->next->g);
        tmpstk = result.strike;
        tmpball = result.ball;

        if (!(tmpstk == stk && tmpball == ball)) // 삭제해야하는 후보군
            nd->next = nd->next->next; // 노드 삭제 (다음 노드를 건너뛰고 그 다음 노드를 가리킴)
        else // 그 다음 노드로 이동
            nd = nd->next;
    }
}
void doUserImplementation(int guess[])
{
    Result result;

    pcnt = 0;
    HEAD.next = 0;
    DFS(0); // 후보군 생성

    while (1)
    {
        int stk, ball;

        for (int i = 0; i < 4; ++i)
            guess[i] = HEAD.next->g[i];

        HEAD.next = HEAD.next->next;

        result = query(guess);
        stk = result.strike;
        ball = result.ball;

        if (stk == 4)
            break;

        deleteNode(stk, ball, guess);
    }
}
//-------------------------------------------------------------------------------
static void initialize()
{
    for (int count = 0; count < 10; ++count)
        digits_c[count] = 0;
    for (int idx = 0; idx < N; ++idx)
    {
        char c;
        do
            scanf("%c", &c);
        while (c < '0' || c > '9');
        digits[idx] = c - '0';
        digits_c[digits[idx]]++;
    }

    querycount = 0;
}

static bool check(int guess[])
{
    for (int idx = 0; idx < N; ++idx)
        if (guess[idx] != digits[idx])
            return false;
    return true;
}

int main()
{
    int total_score = 0;
    int total_querycount = 0;
    ;

    // freopen("sample_input.txt", "r", stdin);
    setbuf(stdout, NULL);

    scanf("%d", &T);
    for (int testcase = 1; testcase <= T; ++testcase)
    {
        initialize();

        int guess[N];
        doUserImplementation(guess);

        if (!check(guess))
            querycount = MAX_QUERYCOUNT;
        if (querycount <= limit_query)
            total_score++;
        printf("#%d %d\n", testcase, querycount);
        total_querycount += querycount;
    }
    if (total_querycount > MAX_QUERYCOUNT)
        total_querycount = MAX_QUERYCOUNT;
    printf("total score = %d\ntotal query = %d\n", total_score * 100 / T, total_querycount);
    return 0;
}
