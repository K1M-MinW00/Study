// Q. n개의 데이터를 입력받아 array에 저장하고 저장된 데이터를 오름차순으로 selection sorting 을 수행하고 그 결과를 출력하라.

#include <iostream>
using namespace std;

#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))
int main()
{
    int n,min,tmp;
    cin >> n;

    int *arr = (int*)malloc(sizeof(int)*n);

    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    for(int i=0;i<n-1;i++)
    {
        min = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j] < arr[min]) // i번째 이후 원소 중 가장 작은 원소를 찾기 위해
            {
                min = j;
            }
        }
        SWAP(arr[i],arr[min],tmp); // i번째 원소 보다 뒤에 있는 원소 중 제일 작은 원소와 교체
    }

    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }

    free(arr); // 동적 할당 해제 !!
    return 0;
}

// Ex) Input : 5 1 -1 0 3 100 , Output : -1 0 1 3 100
