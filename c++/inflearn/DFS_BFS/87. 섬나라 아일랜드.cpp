#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int mapp[21][21];
bool visited[21][21];

int main(){
    int n, tmp;
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> tmp;
            mapp[i][j] = tmp;
        }
    }

    int answer =0;
    //대각선도 연결
    int dx[8] = {-1,0,0,1,-1,1,-1,1};
    int dy[8] = {0,1,-1,0,-1,1,1,-1};
    queue <pair<int,int> > q;
    for(int i=0; i< n; i++){
        for(int j=0; j<n; j++){
            if(mapp[i][j] == 0) continue;
            if(visited[i][j]) continue;

            visited[i][j] = true;
            answer ++;
            q.push(make_pair(i,j));
            
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for(int i =0; i<8; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx<0 || ny <0 || nx>=n || ny >=n) continue;
                    if(visited[nx][ny] || mapp[nx][ny] ==0) continue;
                    visited[nx][ny] = true;
                    q.push(make_pair(nx,ny));
                }
            }

        }
    }
    cout << answer;

}