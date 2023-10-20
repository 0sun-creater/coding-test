#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int mapp[7][7];
bool visited[7][7];

struct Pos{
    int x;
    int y;
    int dist;
    Pos(int a, int b, int c){
        x = a;
        y = b;
        dist =c;
    }
};

int main(){
    int n=6,tmp;
    
    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            cin >> tmp;
            mapp[i][j] = tmp;
        }
    }


    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,1,-1,0};
    queue<Pos > q;
    Pos cur = Pos(0,0,0);
    visited[0][0] = true;
    q.push(cur);
    while(!q.empty()){
        cur = q.front();
        q.pop();
        if(cur.x == n && cur.y == n) break;

        for(int i=0; i <4; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx <0 || ny <0 || nx> 6|| ny >6) continue;
            if(visited[nx][ny] || mapp[nx][ny]==1) continue;
            visited[nx][ny] = true;
            q.push(Pos(nx,ny,cur.dist+1));
        }
    }
    cout << cur.dist;

}