/*
'알파벳 순' 과 같은 순서가 정해져 있으면 탐색을 그 순으로 하면 첫번째 나온 정답이 무조건 정답이 된다.
dfs로 풀다가 flag를 걸어 정답을 찾았으면 그냥 리턴하면 답이 나온다. ex 미로 탈출 명령어 문제

1. tickets를 알파벳 순으로 정렬
2. dfs(출발지, 사용한 티켓 수) 함수
  - 모든 항공권 다 사용하면 정렬했기 때문에 무조건 정답 
  - 항공권 다 사용하지 못했는데 길이 끊긴 경우에만 백트랙킹이 일어남
    visit = false 말고도 pop 필요
*/

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int n;
vector<vector<string>> tickets;
vector<string> answer;
bool visited[10001];
bool flag =0;
void dfs(string cur, int depth){
	if(flag ==1) return;
    
    answer.push_back(cur);

    if(depth == n) {
	   flag =1;
    } 
    
    for(int i =0; i< n; i++){
		if(visited[i]) continue;
        if(tickets[i][0] == cur){
            visited[i] = true;
            dfs(tickets[i][1], depth+1);
            
            if(flag == 0){
                answer.pop_back();
                visited[i] = false;
            }
        }
        
    }
    
}


vector<string> solution(vector<vector<string>> _tickets) {
    tickets = _tickets;
    sort(tickets.begin(), tickets.end());
	n = tickets.size();
    dfs("ICN", 0);
    return answer;
}