/*
미로탐색(DFS)
7*7 격자판 미로를 탈출하는 경로의 가지수를 출력하는 프로그램을 작성하세요.
출발점은 격 자의 (1, 1) 좌표이고, 탈출 도착점은 (7, 7)좌표이다. 
격자판의 1은 벽이고, 0은 통로이다. 격 자판의 움직임은 상하좌우로만 움직인다.
*/
#include <iostream>
using namespace std;

int cnt = 0;
int mapp[8][8];

int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};

void dfs(int x, int y){
    cout << x << " " << y << endl;
    if(x==7 && y ==7) cnt ++;
    else{
        for(int i =0; i<4; i++){
            int next_x = x + dx[i];
            int next_y = y + dy[i];
            if(mapp[next_x][next_y] == 0 && next_x >0 && next_x < 8 && next_y <8 && next_y >0){
                mapp[next_x][next_y] = 2;
                dfs(next_x, next_y);
                mapp[next_x][next_y] = 0;
            }
        }
    }
}

int main(){
    int tmp;
    for(int i=1; i<=7; i++){
        for(int j =1; j <=7; j++){
            cin >> tmp;
            mapp[i][j] = tmp;
        }
    }

    mapp[1][1] = 2;
    dfs(1,1);

    cout << cnt;

}



