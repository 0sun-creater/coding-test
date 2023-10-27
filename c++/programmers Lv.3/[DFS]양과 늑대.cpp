#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
//못 가면 백트랙킹 해야되니까 dfs로 풀자

int answer =0;
vector<vector<int>> graph; //node
vector<int> infoo;
void dfs(int sheep, int wolf, int cur, queue<int> q){
    if(infoo[cur] == 0) sheep++;
    else wolf++;
    
	if(wolf >=sheep) return;
    else answer = max(answer,sheep);
    
    
    for (int i = 0; i < graph[cur].size(); i++) {
        q.push(graph[cur][i]);
    }
  
	for(int i=0; i< q.size(); i++){
        int next = q.front();
        q.pop();
        dfs(sheep, wolf, next, q);
        q.push(next);
    }
    
}
int solution(vector<int> info, vector<vector<int>> edges) {
    int n = int(info.size());

    graph.assign(n, vector<int>({}));
    infoo.assign(info.begin(), info.end());
    
    for(auto e: edges){
        graph[e[0]].push_back(e[1]);
    }
    queue<int> q;
    dfs(0, 0, 0, q);
    
    return answer;
}