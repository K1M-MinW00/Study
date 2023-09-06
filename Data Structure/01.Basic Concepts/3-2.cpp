// Q. 두 개의 정수 x, y 를 입력 받아, x 와 y 가 서로소인 지 판별하여 그 결과를 출력하는 코드를 작성하라.
// 다음은 주어진 두 개의 정수 x, y 가 서로소인지 판단하기 위한 recursive equation 이다.
//            { true  ,      if x=1 or y=1 (base case)              }
// prime(x,y)={ false ,      if x!=1, y!=1 and x=y (base case)      }
//            { prime(x,y-x) if x!=1, y!=1 and x<y (recursive case) }
//            { prime(x-y,y) if x!=1, y!=1 and x>y (recursive case) }
// - 위의 식을 이용 하여 x와 y가 서로소인지 판별하여 서로소이면 true, 아니면 false 를 출력한다.

#include <iostream>

using namespace std;

int prime(int x,int y)
{
    if(x==1 || y==1)
        return 1;
    else if(x!=1 && y!=1 && x==y)
       return 0;
    else if(x!=1 && y!=1 && x<y)
        return prime(x,y-x);
    else if(x!=1 && y!=1 && x>y)
        return prime(x-y,y);

    return 0;
}

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    
    printf("%s",prime(a,b) ? "true" : "false");

    return 0;
}

// Ex) Input : 3 12 , Output : false
// Ex) Input : 12 15 , Output : false
// Ex) Input : 17 21 , Output : true
// Ex) Input : 51 100 , Output : true
