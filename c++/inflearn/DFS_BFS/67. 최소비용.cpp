/*
가중치 방향그래프가 주어지면 1번 정점에서 N번 정점으로 가는 최소비용을 출력하는 프로그
램을 작성하세요.
*/

#include <vector>
#include <iostream>

using namespace std;

int n;
vector<pair<int, int > > graph[30];
int *visited;
int cost = 2147000000;
void dfs(int v, int sum){
    if (v == n){
        if(sum < cost) cost = sum;
    }
    else{
        for(int i =0; i< int(graph[v].size()); i++){
            pair<int,int> next = graph[v][i];
            if(visited[next.first] ==0){
                visited[next.first] =1;
                dfs(next.first, sum + next.second);
                visited[next.first] =0;
            }
        }
    }
}

int main(){
    int m; 
    cin >> n >> m;
    visited = new int[n+1];
    for(int i =0; i<n+1; i++){
        visited[i] =0; 
    }
    int tmp,tmp2, tmp3;
    for(int i =0; i<m; i++){
        cin >> tmp >> tmp2 >> tmp3;
        graph[tmp].push_back(make_pair(tmp2,tmp3));
    }

    visited[1] =1;
    dfs(1, 0);

    cout << cost;
}