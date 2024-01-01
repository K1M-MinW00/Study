#include <iostream>
#include <vector>

using namespace std;

void DFS(int number,int digit);
bool isPrime(int number);
static int N;
vector<int> specialPrime;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    DFS(2,1);
    DFS(3,1);
    DFS(5,1);
    DFS(7,1);


    for(int i=0;i<specialPrime.size();i++)
        cout << specialPrime[i] << endl;
    return 0;
}

void DFS(int number,int digit)
{
    if(digit == N)
    {
        if(isPrime(number))
            specialPrime.push_back(number); // 1자리부터 N자리 숫자 중 모든 숫자가 소수인 경우
        return;
    }

    for(int i=1;i<10;i++)
    {
        if(i%2==0) // 짝수는 2의 약수이므로 확인할 필요 X
            continue;
        
        if(isPrime(number*10+i)) // 소수이면 다음 확인 단계로
            DFS(number*10+i,digit+1);
    }
}

bool isPrime(int num // 소수 판별 함수
{
    for(int i=2;i<=num/2;i++)
    {
        if(num%i==0)
            return false;
    }
    return true;
}
