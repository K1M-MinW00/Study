#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int N;
    cin >> N;
    
    vector<int> a,b;
    
    int x;
    for(int i=0;i<N;i++)
    {
        cin >> x;
        a.push_back(x);
        b.push_back(x);
    }
    
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end()); // unique() : 중복된 원소를 맨뒤로 옮기고, 중복된 원소가 시작하는 인덱스를 반환 , erase() : unique() 가 반환한 인덱스부터 끝까지 삭제하여 중복된 원소 삭제
    
    for(int i=0;i<N;i++)
    {
        cout << lower_bound(a.begin(),a.end(),b[i])-a.begin() << ' '; // lower_bound(vector.begin(),vector.end(),key) : 찾으려는 key 값보다 같거나 큰 숫자가 배열 몇 번째에서 처음 등장하는지 인덱스를 반환
    }
    return 0;
}
