
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
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
    priority_queue<Edge, vector<Edge>, greater<Edge> > q;

    int v, e, t1,t2,t3;
    cin >> v >> e;    
    
    for(int i =0; i<e; i++){
        cin >> t1 >> t2 >> t3;
        q.push(Edge(t1,t2,t3));
    }

    while(!q.empty()){
        Edge cur = q.front();
        q.pop();


    }
}