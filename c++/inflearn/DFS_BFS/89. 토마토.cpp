/*
격자 모양 상자의 칸에 하나씩 넣어서 보관한다.
보관 후 하루가 지나면 익은 토마노 인접에 있는 안익은 토마토들이 익는다.
혼자 저절로 익는 경우는 없음

창고에 보관된 토마토들이 며칠이 지나면 다 익게 되는지, 최소 일수가 알고 싶음

단, 상자의 일부 칸에는 토마토가 들어있지 않을 수 있다.

1은 익은 토마토, 정수 0 은 익은 토마토 -1은 들어있지 않은 칸
모든 토마토가 익어있으면 0출력
토마토가 모두 익지 못하는 상황이면 -1
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int mapp[1010][1010];
int dist[1010][1010];

struct Pos{
    int x;
    int y;
    Pos(int a, int b){
        x = a;
        y = b;
    }
};

int main(){
    int n,m,tmp;
    cin >> n >> m;
    queue<Pos > q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> tmp;
            mapp[i][j] = tmp;
            if(tmp == 1){
                q.push(Pos(i,j));
            }
        }
    }


    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,1,-1,0};
    
    while(!q.empty()){
        Pos cur = q.front();
        q.pop();
        
        for(int i =0; i< 4; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx <0||ny<0|| nx>=n ||ny >=m) continue;
            if(mapp[nx][ny]!=0) continue;
            q.push(Pos(nx,ny));
            mapp[nx][ny] = 1;
            dist[nx][ny] = dist[cur.x][cur.y] + 1;
        }
    }

    bool flag = false;
    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            if(mapp[i][j] ==0) flag =true;
        }
    }
    if(flag) cout << "-1";
    else{
        int res = -2147000000;
        for(int i =0; i< n; i++){
            for(int j =0; j<n; j++){
                if (res < dist[i][j]) res = dist[i][j];
            }
        }
        cout << res ;
    }
}