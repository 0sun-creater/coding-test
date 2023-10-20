/*
가중치 방향그래프에서 1번 정점에서 모든 정점으로의 최소 거리비용 출력
경로 없으면 impossible

! 모든 cost가 양수여야만 사용할 수 있음 !
dist 배열을 만들어 놓고 전부 max로 초기화
출발 정점은 dist 0 (자기 자신)
1. min(dist)는 check! 걘 이제 업데이트 될일 없음
2. 걔를 기준으로 +cost 해서 업데이트 
3. cur + cost > dist[new] 면 업데이트
반복

최소를 찾을 때 우선순위 큐를 이용하면 빨라진다.
*/

#include<vector>
#include<algorithm>
#include<queue>
#include <iostream>

using namespace std;

struct Edge{
    int v;
    int dist;
    Edge(int a, int b){
        v =a;
        dist= b;
    }
    bool operator<(const Edge &b)const{
        return dist > b.dist; //내림차순
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    priority_queue<Edge> q; //최소 힙으로 만들어진다.

    int t1,t2,t3;
    vector<int> dist(n+1, 2147000000);
    vector<pair<int,int> > graph[30];
    for(int i=1; i<=m; i++){
        cin >> t1 >> t2 >> t3;
        graph[t1].push_back(make_pair(t2, t3));
    }

    q.push(Edge(1,0));
    dist[1] = 0;

    while(!q.empty()){
        int cur = q.top().v;
        int cost = q.top().dist;
        q.pop();

        if(cost > dist[cur]) continue;
        for(int i=0; i< int( graph[cur].size()); i++){
            int next = graph[cur][i].first;
            int nextDis = cost + graph[cur][i].second;
            if(dist[next] > nextDis){
                dist[next] = nextDis;
                q.push(Edge(next, nextDis));
            }
        }
    }
    for(int i=2; i<=n; i++){
        if(dist[i] != 2147000000) cout << i << " : " << dist[i] <<endl;
        else cout << i << " : impossible" <<endl;
    }
    return 0;
}







/*

int ch[30], dist[30];
vector<pair<int, int> > map[30];
int main(){
	int n, m, i, j, a, b, c, min;
	scanf("%d %d", &n, &m);
	for(i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		map[a].push_back(make_pair(b, c));
	}
	for(i=0; i<=n; i++) dist[i]=2147000000;
	dist[1]=0;
	for(i=1; i<=n; i++){
		min=0;
		for(j=1; j<=n; j++){
			if(ch[j]==0 && dist[j]<dist[min])
				min=j;
		}
		ch[min]=1;
		for(j=0; j<map[min].size(); j++){
			int v=map[min][j].x;
			int cost=map[min][j].y;
			if(dist[v]>dist[min]+cost){
				dist[v]=dist[min]+cost;
			}
		}
	}
	for(i=2; i<=n; i++){
		if(dist[i]!=2147000000) printf("%d : %d\n", i, dist[i]);
		else printf("%d : impossible\n", i);
	}
	return 0;
}
*/
