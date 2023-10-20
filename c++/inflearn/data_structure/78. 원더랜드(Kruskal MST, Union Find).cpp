/*
원더랜드 - 모든 도시를 서로 연결하면서 최소의 유지비용이 들도록 선택하기

크루수칼 알고리즘
가중치 값으로 오름차순 정렬
작은 순으로 뽑아내면서 cicle이 되는지 안되는지 확인하기 (union-find)
 ㄴ이미 연결된 두 정점을 또 연결할 필요가 없다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge{
    int v1;
    int v2;
    int cost;
    Edge(int a, int b, int c){
        v1 = a;
        v2 = b;
        cost = c;
    }

    bool operator< (const Edge &edg)const{
        return cost < edg.cost;
    }
};

int main(){
    int answer =0;
    vector<Edge> graph;

    int v, e, t1,t2,t3;
    cin >> v >> e;    
    
    for(int i =0; i<e; i++){
        cin >> t1 >> t2 >> t3;
        graph.push_back(Edge(t1,t2,t3));
    }
    sort(graph.begin(), graph.end());

    bool visited[v+1];
    memset(visited, false, sizeof(visited));

    visited[graph[0].v1] = true;
    visited[graph[0].v2] = true;
    answer += graph[0].cost;

    for(int i=1; i<e; i++){
        int v1 = graph[i].v1;
        int v2 = graph[i].v2;
        if(visited[v1] && visited[v2]) continue;
        visited[graph[i].v1] = true;
        visited[graph[i].v2] = true; 
        answer += graph[i].cost;
    }

    cout << answer;
    

}

/*

#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int unf[10001];

struct Edge{
	int s;
	int e;
	int val;
	Edge(int a, int b, int c){
		s=a;
		e=b;
		val=c;
	}
	bool operator<(const Edge &b)const{
		return val<b.val;
	}
};

int Find(int v){
	if(v==unf[v]) return v;
	else return unf[v]=Find(unf[v]);
}

void Union(int a, int b){
	a=Find(a);
	b=Find(b);
	if(a!=b) unf[a]=b;
}

int main(){
	//freopen("input.txt", "rt", stdin);
	vector<Edge> Ed;
	int i, n, m, a, b, c, cnt=0, res=0;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		unf[i]=i;
	}
	for(i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		Ed.push_back(Edge(a, b, c));	
	}
	sort(Ed.begin(), Ed.end());
	for(i=0; i<m; i++){
		int fa=Find(Ed[i].s);
		int fb=Find(Ed[i].e);
		if(fa!=fb){
			res+=Ed[i].val;
			Union(Ed[i].s, Ed[i].e);
		}
	}
	printf("%d\n", res);
	return 0;
}
*/