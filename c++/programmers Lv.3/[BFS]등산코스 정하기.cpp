#include <vector>
#include <queue>
#include <algorithm>

#define ALL(X) X.begin(), X.end()
#define MAX 50001

using namespace std;

//gates 가 출입구 - start end 지점
//summits은 산봉우리
//gates와 summits에 등장하지 않은 지점은 모두 쉼터
//? 그럼 그냥 node-node 사이가 가장 긴게 intensity
//그 intesity들 중에서 max가 되는 거 출력 (봉우리 번호까지 같이)

vector<int> res;
vector<pair<int, int>> adj[MAX];
int intensity[MAX]; //모든 시작지점을 한번에 우선순위 큐에 삽입 후 동시 출발하여 기록
bool isSummit[MAX];

void mountain(vector<int> &gates){
    //pq & pair 기본 : 첫번째 인자 오름차순, 두번째 인자 내림차순
    //pq & pair & greater : 첫번째 인자 오름차순, 두번째 인자 오름차순 
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
    vector<pair<int, int>> temp;
    
    //-1로 초기화
    memset(intensity, -1, sizeof(intensity));
    
    //모든 게이트를 넣어줌
    //첫번째 인자는 전부 0으로 pop 전에는 항상 제일 앞에 나와있게 될 것.
    for(auto g: gates){
        pq.push({0, g});
        intensity[g] = 0;
    }
    
    while(!pq.empty()){
        int cost = pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        
        //현재 인텐시티가 저장되어있는 intensity보다 크면 살펴볼 필요가 없다.
        //이거 안해줘도 시간초과는 안난다.
        //if(cost > intensity[cur]) continue;
        
        //도착지점이면 temp에 cost와 산봉우리 저장
        if(isSummit[cur]){ 
            temp.push_back({cost, cur});
            continue;
        }
        
        //현재 노드와 연결되어있는 곳을 탐색
        for(auto p: adj[cur]){
            int weight = p.first;
            int next = p.second;
            
            //아직 intensity가 업데이트 되어있지 않거나
            //cur.cost와 next.weight 중 큰것 보다 intensity에 저장되어 있는 게 크다면
            if(intensity[next] == -1 || max(cost, weight) < intensity[next]){
                intensity[next] = max(cost, weight); //작은 걸로 업데이트
                pq.push({intensity[next], next}); 
            }
        }
        
    }
    
    sort(ALL(temp)); //도착지점에 도착해서 넣어둔 경로들 오름차순 정렬 (cost순)
    res.push_back(temp[0].second); //cost가 가장 작은 넘 산봉우리
    res.push_back(temp[0].first); //cost 
    
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits){
    for(auto e: paths){ //vector<pair<int, int>> [i] 는 {이어진 노드, 거리} 를 저장함
        adj[e[0]].push_back({e[2], e[1]});
        adj[e[1]].push_back({e[2], e[0]});
    }
    
    for(auto s: summits){ //도착지 저장
        isSummit[s] = true;
    }
    
    mountain(gates);
    return res;
}