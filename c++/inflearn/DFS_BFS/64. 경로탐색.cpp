// 방향 그래프 주어짐
//1에서 n번으로 가는 모든 경로의 가지 수를 출력하는 프로그램 작성

#include <iostream>
using namespace std;

int n,m, cnt=0;
int **mapp;
int *visited;
void dfs(int v){
    if(v == n) {
        cnt++;
    }
    for(int i =1 ; i <= n; i++){
        if (mapp[v][i] ==1 && visited[i] == 0){
            visited[i] = 1;
            dfs(i);
            visited[i] = 0;
        }
    }

}

int main(){
    cin >> n >> m;
    mapp = new int*[n+1];
    for(int i =0; i<=n; i++){
        mapp[i] = new int[n+1];
    }
    visited = new int[n+1];
    int tmp,tmp2;
    for(int i =0 ;i<m; i++){
        cin >> tmp >> tmp2;
        mapp[tmp][tmp2] = 1;
    }

    visited[1] = 1;
    dfs(1);

    cout << cnt;

}