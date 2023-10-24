#include <string>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
using namespace std;
struct Edge{
    int v;
    int dist;
    Edge(int a, int b){
        v =a;
        dist= b;
    }
};
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int> > graph(n+1, vector<int > (n+1, 0));
   
    for(auto e: edge){
        graph[e[0]][e[1]] = 1;
        graph[e[1]][e[0]] = 1;
    }

    int visit[n+1];
    fill(visit, visit+n+1, -1);
    queue<Edge> q;
    q.push(Edge(1,0));
    visit[1] = 0;
    while(!q.empty()){
        Edge cur = q.front();
        q.pop();
        if(answer < cur.dist) answer = cur.dist;
        for(int i =1; i<int(graph[cur.v].size());i++){
            if(graph[cur.v][i]==0) continue;
			if(visit[i] == -1){
                visit[i] = cur.dist + 1;
            	q.push(Edge(i, cur.dist + 1));
            }
        }
    }
    
    int cnt =0;
    for(auto v: visit){
        if(v == answer) cnt ++;
    }
    
    return cnt;
}