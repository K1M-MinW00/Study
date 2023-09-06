// Q. Fibonacci 수열은 F[0] = 1, F[1] = 1 이고, i > 1 인 경우 F[i] = F[i-1] + F[i-2] 이다.
// 표준 입력으로 양의 정수 N 값을 입력 받아 F[N] 계산에 걸린 시간을 출력하라.
// 단계 1. 양의 정수 N 값을 scanf 로 입력 받아라.
// 단계 2. Iteration 을 이용 (iFibo 함수 구현) 하여 Fibonacci 수열을 구현하고 F(N) 값을 계산하여 출력하라.
// 단계 3. 단계2를 수행하는 데 걸린 계산 시간을 출력하라.
// 단계 4. Recursive function (rFibo 함수 구현) 으로 Fibonacci 수열을 구현하고 F(N) 값을 계산하여 출력하라.
// 단계 5. 단계4를 수행하는 데 걸린 계산 시간을 출력하라.
// 단계 6. 실험을 통해 프로그램이 수행될 수 있는 N의 최대값을 찾아 comment 문으로 프로그램 첫부분에 작성하여 써라.

#include <iostream>
#include <ctime>

using namespace std;

int iFibo(int n)
{
    int *arr = (int *)malloc(sizeof(int) * (n + 1));

    arr[0] = 1;
    arr[1] = 1;

    if (n <= 1)
        return arr[n];

    for (int i = 0; i <= n - 2; i++)
    {
        arr[i + 2] = arr[i + 1] + arr[i];
    }
    return arr[n];
}

int rFibo(int n)
{
    if (n <= 1)
        return 1;
    else
        return rFibo(n - 1) + rFibo(n - 2);
}
int main()
{
    int N;
    scanf("%d", &N);

    double Itime, Rtime;

    long rep = 0;
    clock_t start = clock();

    do
    {
        rep++;
        for (int i = 0; i < 1000; i++)
        {
            iFibo(N);
        }
    } while (clock() - start < 1000);

    Itime = ((double)(clock() - start)) / CLOCKS_PER_SEC;
    Itime /= rep;

    printf("Iterative F(%d) = %d\n", N, iFibo(N));
    printf("F(%d) Iterative Time = %f\n", N, Itime);

    do
    {
        rep++;
        for (int i = 0; i < 1000; i++)
        {
            rFibo(N);
        }
    } while (clock() - start < 1000);

    Rtime = ((double)(clock() - start)) / CLOCKS_PER_SEC;
    Rtime /= rep;
    printf("Recursive F(%d) = %d\n", N, rFibo(N));
    printf("F(%d) Recursive Time = %f\n", N, Rtime);
    return 0;
}
