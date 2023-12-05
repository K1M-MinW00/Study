//https://www.acmicpc.net/problem/1929

#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int isprime(int n)
{
    for(int i=2;i<=int(sqrt(n));i++) // 약수는 짝을 이루기 때문에 2 부터 int(sqrt(n)) 까지 나누어 보고, 그 중 나머지가 0 인 경우가 있으면 소수가 아님
    {
        if(n%i==0)
            return 0;
    }
    return 1;
}

int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int cnt=0;
  
    for(int i=m;i<=n;i++)
    {
        if(isprime(i)!=0 && i!=1) // 소수에 1은 포함 X
            printf("%d ",i);
    }

    return 0;
}

// EX) Input : 3 16 , Output : 3 5 7 11 13
