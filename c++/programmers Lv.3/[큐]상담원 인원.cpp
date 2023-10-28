#include <string>
#include <vector>
#include <queue>
// 조합 문제 
// 상담유형 5개, 상담사 20명, 상담 요청 300 15c5 --> 1초안걸림
//https://novlog.tistory.com/entry/C-%EC%88%9C%EC%97%B4-%EA%B5%AC%ED%95%98%EB%8A%94-%ED%95%A8%EC%88%98-nextpermutation-prev-permutation

//대기시간 어떻게 구해? 우선순위 큐 이용 (큐의 크기는 멘토의 머릿수)
/*1. (멘토의 시간 >= 상담 요청 시각)인 경우
(멘토의 시간 - 상담 요청 시각) 만큼의 대기 시간이 발생한다.
그리고 새로운 큐의 값은 (멘토의 시간 + 상담 시간)이 된다.

2. (멘토의 시간  < 상담 요청 시각)인 경우
이땐 멘토의 시간이 더 여유롭기 때문에 대기시간은 발생하지 않는다.
하지만 멘토가 상담 요청 시각까지 더 기다려야 하기 때문에 새로운 큐의 값은 (상담 요청 시각 + 상담 시간)이 된다.*/

using namespace std;

vector<vector<int>> orders; // 분배가능한 모든 경우의 수

// 모든 경우의 수를 구하는 함수(남은 인원, 유형, 컨테이너)
void backtracking(int remain, int idx, vector<int> order){
    // 모든 인원을 담았으면 orders에 추가
    if(remain <= 0){
        orders.push_back(order);
        return;
    }
    
    for(int i = idx; i < order.size(); i++){
        order[i]++; 
        backtracking(remain-1,i,order);
        order[i]--;
    }
}

//k : 상담 유형, n : 멘토의 수 
int solution(int k, int n, vector<vector<int>> reqs) {
    
    int answer = 99999999;
    int time[301];
    fill(&time[0],&time[301],0);
    
    //한 유형에 적어도 한명의 멘토를 필요로 함 : n-k
    //나머지를 조합으로 만듬
    vector<int> kind(k+1,1);
    backtracking(n-k,1,kind);
   
    
    for(auto order :orders){
    	// 오름차순으로 뽑히는 우선순위큐를 유형의 수만큼 만듦
        priority_queue<int,vector<int>,greater<int>> pq[order.size()];
        int result =0; // 대기 시간의 합

        for(int i = 1; i < order.size(); i++){
            // 유형 갯수 대로 push 첫 시작은 0
            for(int j = 0; j < order[i]; j++) pq[i].push(0);
        }

        for(auto req : reqs){
            int arrive = req[0]; // 요청 시각
            int time = req[1]; // 상담 시각
            int idx = req[2]; // 상담 유형

            // 해당 유형의 우선순위 큐에서 하나 뽑는다.
            int picked = pq[idx].top();
            pq[idx].pop();

            // 멘토의 시간 > 요청 시각
            if(picked > arrive){
                result += picked-arrive; //대기시간 쌓임
                pq[idx].push(picked+time); //그다음시간은 picked+상담시간
            }

            // 멘토의 시간 <= 요청 시각
            else if(picked <= arrive) pq[idx].push(arrive+time);
			//바로 넣을 수 있음 그 다음 시간은 요청시각+상담시간;
            
        }
		//한 번에 조합에 대해서 result에 대기시간이 쌓임
        //그 중 최소값이 정답
        answer = min(answer, result); 
    }
    return answer;
}