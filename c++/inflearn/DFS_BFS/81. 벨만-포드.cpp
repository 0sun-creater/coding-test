/*
최소비용으로 start ->end 가는 방법 찾기

벨만포드 ; 음의 사이클이 없다는 가정
정점 갯수 -1 이 가장 긴 경로임 (정점 갯수이상의 경로는 음의 사이클이 있는 그래프)
*/

#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
struct Edge{
    int s;
    int e;
    int val;
    Edge(int a, int b, int c){
        s =a;
        e = b;
        val = c;
    }
};

int main(){
    vector<Edge> ed;
    int i,n,m,a,b,c,j,s,e;
    scanf("%d %d", &n, &m);

    for(i=1; i<=m; i++){
        scanf("%d %d %d", &a, &b, &c);
        ed.push_back(Edge(a,b,c));
    }
    scanf("%d %d", &s, &e);
    int dist[n+1];
    for(i=1; i<=n; i++){
        dist[i] = 2147000000;
    }

    dist[s] =0;
    //i=1 1번만에 갈 수 있는 경로들
    //i=2 2번만에 갈 수 있는 경로들 ..
    for(i=1; i<n;i++){
        for(j=0; j<ed.size(); j++ ){
            int u = ed[j].s;
            int v = ed[j].e;
            int w = ed[j].val;
            if(dist[u] != 2147000000 && dist[u] +w <dist[v]){
                dist[v]=dist[u] +w;
            }
        }
    }
    //있으면 음의 사이클이 있다는 뜻.
    for(j=0; j<ed.size(); j++){
            int u = ed[j].s;
            int v = ed[j].e;
            int w = ed[j].val;
            if(dist[u] != 2147000000 && dist[u] +w <dist[v]){
                printf("-1\n");
                exit(0);
            }
    }
    printf("%d\n", dist[e]);
    return 0;



}
