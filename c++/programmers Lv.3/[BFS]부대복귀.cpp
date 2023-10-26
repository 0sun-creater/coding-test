#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
/*
두 지역 간 걸리는 시간은 1로 동일
최단시간에 부대 복귀
적군의 방해로 인해 되돌아오는 경로가 없어져 복귀가 불가능한 대원도 있음

n: 총지역 수
roads: 왕복할 수 있는 길 정도
soures: 부대원 위치
destination: 도착지
*/

vector<vector<int>> graph(100001);
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
	int dist [100001];
    fill(&dist[0], &dist[100000], -1);
    
    //지도 만들기
    for(int i=0; i<int(roads.size()); i++){
        graph[roads[i][0]].push_back(roads[i][1]);
        graph[roads[i][1]].push_back(roads[i][0]);
    }
    //destination을 시작으로 sources까지의 최단 거리
	queue<pair<int,int>> q; //node,dist
    q.push(make_pair(destination,0));
    dist[destination] = 0;
    
    while(!q.empty()){
        pair<int, int> cur = q.front();
        q.pop();
        for(int i=0; i< int(graph[cur.first].size());i++){
            int next = graph[cur.first][i];
            if(dist[next] == -1){
            	q.push(make_pair(next, cur.second+1));
                dist[next] = cur.second + 1;
            }
        }
        
    }
    
    for(int i=0; i< int(sources.size());i++){
        answer.push_back(dist[sources[i]]);
    }
    
    
    return answer;
}