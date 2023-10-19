
#include<vector>
#include<queue>
#include<iostream>
using namespace std;

int answer = 2147000000;

int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};

int n, m;
bool visited[101][101] = {false, };
vector<vector<int> > map;

struct pos{
    int x;
    int y;
    int dis;
};

int BFS(){
    queue<pos> q;
    q.push({0,0,1});
    visited[0][0] = true;
    
    while(!q.empty()){
        pos cur = q.front();
        q.pop();
        if(cur.x == n && cur.y == m){
            cout << cur.dis <<endl;
            return cur.dis;
        }
        for(int i =0; i<4;i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx<0 || ny <0 || nx > n || ny > m) continue;
            if(visited[nx][ny]==0 && map[nx][ny] ==1){
                q.push({nx,ny,cur.dis+1});
                visited[nx][ny] =true;
            }
        }
    }
    
    
    
    return -1;
}

int solution(vector<vector<int> > maps)
{   
    n = maps.size()-1;
    m = maps[0].size()-1;
    
    
    map = maps;
    answer = BFS();
  
    
    
    
    return answer;
}

/*
최단거리는 BFS로 푸는게 정신건강에 좋다.
map을 매번 업데이트하면서 시간 초과.

#include<vector>
#include<iostream>
using namespace std;

int answer = 2147000000;

int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};

void dfs(int x, int y, int end_x, int end_y, int dist, vector<vector<int> > visit){
    if(x==end_x && y == end_y){
        if(answer > dist) answer = dist;
        return;
    }
    for(int i =0; i<4;i ++){
        int new_x = x + dx[i];
        int new_y = y + dy[i];
        if(new_x >= 0 && new_x < end_x+1 && new_y >=0 && new_y < end_y+1){
            if(visit[new_x][new_y] == 1){
                visit[new_x][new_y] = 0;
                dfs(new_x,new_y, end_x, end_y, dist+1, visit);
                visit[new_x][new_y] = 1;
            }
        }
    }
}

int solution(vector<vector<int> > maps)
{
    //(0,0) -> (n-1,m-1)
    int n = maps.size() -1;
    int m = maps[0].size() -1;
    if(maps[n-1][m] == 0 && maps[n][m-1] == 0){
        return -1;
    }
    
    dfs(0,0,n,m,1,maps);
    
    
    return answer;
}

*/