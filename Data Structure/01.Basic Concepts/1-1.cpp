// Q. n개의 정수 데이터를 입력 받고 입력된 데이터에서 min 값을 찾아서 출력하는 코드를 작성하라 (array 사용 X)

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int min = 999, num;
    for(int i=0;i<n;i++)
    {
        cin >> num;
        if(num < min)
        {
            min = num;
        }
    }

    cout << min ;
    return 0;
}

// Ex) Input : 5 1 -1 0 3 100 , Output : -1
