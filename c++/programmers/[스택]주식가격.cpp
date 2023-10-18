#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

//인덱스를 시간으로 봄
//당시 시간과 현재를 비교후 현재가 커지면 걘 (현재-당시)초만큼 가격이 떨어진것
//스택은 언제까지 가격이 오를지 모르니 처리를 미뤄두기 위함이라고 생각하면 편함
vector<int> solution(vector<int> prices) {
    int size = prices.size();

    vector<int> answer(size);
    stack<int> s;

    for(int i =0; i< size;i++){
        //가격이 줄었다면
        while(!s.empty() && prices[s.top()] > prices[i]) {
            answer[s.top()] = i- s.top(); //현재 시간 - 당시 시간
            s.pop();
        }
        s.push(i);
  
    }
    while(!s.empty()){
        answer[s.top()] = size - s.top() - 1; //종료시간 - 당시시간
        s.pop();
    }
    
    return answer;
}