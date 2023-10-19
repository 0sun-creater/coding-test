//방향 그래프 주어짐
//1에서 n번으로 가는 모든 경로의 가지 수를 출력하는 프로그램 작성
//인접리스트 방법

#include <iostream>
#include <vector>
using namespace std;

int n,m, cnt=0;
vector<int> mapp[30];
int visited[30];
void dfs(int v){
    if(v == n) {
        cnt++;
    }
    for(int i =0 ; i <mapp[v].size(); i++){
        if (visited[mapp[v][i]]==0){
            visited[mapp[v][i]] = 1;
            dfs(mapp[v][i]);
            visited[mapp[v][i]] = 0;
        }
    }

}

int main(){
    cin >> n >> m;

    int tmp,tmp2;
    for(int i =0 ;i<m; i++){
        cin >> tmp >> tmp2;
        mapp[tmp].push_back(tmp2);
    }

    visited[1] = 1;
    dfs(1);

    cout << cnt;

}