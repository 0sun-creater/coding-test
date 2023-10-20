
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int ch[30];
struct Edge{
    int e;
    int val;
    Edge(int b, int c){
        e = b;
        val = c;
    }

    bool operator< (const Edge &edg)const{
        return val < edg.val;
    }
};

int main(){
	priority_queue<Edge> Q;
	vector<pair<int, int> > map[30];
	int i, n, m, a, b, c, res=0;
	scanf("%d %d", &n, &m);
	for(i=1; i<=m; i++){
		scanf("%d %d %d", &a, &b, &c);
		map[a].push_back(make_pair(b, c));	
		map[b].push_back(make_pair(a, c));
	}
	Q.push(Edge(1, 0));
	while(!Q.empty()){
		Edge tmp=Q.top();
		Q.pop();
		int v=tmp.e;
		int cost=tmp.val;
		if(ch[v]==0){
			res+=cost;
			ch[v]=1;
			for(i=0; i<map[v].size(); i++){
				if(ch[map[v][i].first]==0){
					Q.push(Edge(map[v][i].first, map[v][i].second));
				}
			}
		}
		
	}
	printf("%d\n", res);
	return 0;
}