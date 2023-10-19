/*
그래프 최단거리(BFS)
다음 그래프에서 1번 정점에서 각 정점으로 가는 최소 이동 간선수를 출력하세요.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
vector<int> graph[20];

int main(){
    int m, tmp, tmp2;
    cin >> n >> m;
    for(int i =0; i<m; i++){
        cin >> tmp >> tmp2;
        graph[tmp].push_back(tmp2);
    }
    int *visited = new int[n+1];
    int *dist = new int[n+1];
    queue<int> q;
    q.push(1);
    visited[1] =1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i=0; i<int(graph[cur].size());i++){
            if(visited[graph[cur][i]]==0){
               visited[graph[cur][i]] =1;
               q.push(graph[cur][i]);
               dist[graph[cur][i]] = dist[cur] + 1;

            }
        }
    }

}