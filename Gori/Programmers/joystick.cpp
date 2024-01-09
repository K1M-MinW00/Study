#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    
    int length = name.length();
    int turn = name.length()-1;
    
    for(int L1=0;L1<length;L1++)
    {
        answer +=min(name[L1]-'A','Z'-name[L1]+1); // ↕ 방향
        
        int L2_idx = L1+1;
        while(L2_idx<length) // 다음 A 가 아닌 인덱스 찾기
        {
            if(name[L2_idx]=='A')
                L2_idx++;
            else
                break;
        }
        int L2 = length - L2_idx; // 역방향으로 탐색했을 경우
        turn = min(turn,L1+L2+min(L1,L2)); // min(2*L1+L2, L1+2*L2) : 정방향과 역방향 중 더 작은 횟수 선택
    }
    answer += turn;
    return answer;
}
