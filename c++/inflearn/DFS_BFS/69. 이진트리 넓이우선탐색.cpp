/*
이진트리 깊이우선탐색(DFS)
아래 그림과 같은 이진트리를 전위순회와 후위순회를 연습해보세요.
    1
  2   3
4  5 6  7
넓이 우선 탐색 : 1 2 3 4 5 6 7
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    vector <int> graph[8];

    int tmp, tmp2;
    for(int i =1; i <= 6; i++){
        cin >> tmp >> tmp2;
        graph[tmp].push_back(tmp2);
        graph[tmp2].push_back(tmp);
    }
    
    cout << "넓이 우선 탐색 : " ;

    int *visited = new int[8];
    queue<int> q;
    q.push(1);
    visited[1] =1;
    while(!q.empty()){
        int cur = q.front();
        cout << cur << " ";
        q.pop();

        for(int i=0; i < int(graph[cur].size());i++){
            if(visited[graph[cur][i]] ==0 ){
                q.push(graph[cur][i]);
                visited[graph[cur][i]]=1;
            }
        }
    }

    
}