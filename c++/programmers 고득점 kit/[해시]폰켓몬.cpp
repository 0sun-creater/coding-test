#include <vector>
#include <set>
using namespace std;

//n마리 중 n/2 가져가
//같은 종류 포켓몬은 같은 번호를 가짐
//최대한 많은 종류의 포켓몬을 포함해서 n/2마리 선택
//선택 방법 중, 가장 많은 종류의 포켓몬을 선택하는 방법을 찾아
//그때의 포켓몬 종류의 번호의 개수를 리턴 (종류 개수의 최댓값)

int solution(vector<int> nums)
{
    int answer = 0;
    int n = int(nums.size()) / 2;
    set<int> s;
    for(int i=0; i < int(nums.size());i++){
        s.insert(nums[i]);
    }
    
    int setSize = int(s.size());
    if(setSize > n) answer =n;
    else answer = setSize;
    
    return answer;
}