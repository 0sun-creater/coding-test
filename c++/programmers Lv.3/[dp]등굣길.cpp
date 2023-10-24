#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    int road[100][100];
    
    // 0. 전체를 -1로 초기화
    for(int i = 0; i < 100; ++i){
        for(int j = 0; j < 100; ++j)
            road[i][j] = -1;
    }
    
    // 1. 시작 지점을 1로 바꿈
    road[0][0] = 1;
    
    // 2. 물에 잠긴 지역 0으로 바꿈
    for(int i = 0; i < puddles.size(); ++i)
        road[puddles[i][0]-1][puddles[i][1]-1] = 0;
    

    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            if(road[i][j] == -1){ //물 지역(0) 무시
                if(i == 0 && j == 0) //시작점 건들지 않기
                    continue;
                else if(i == 0) //가생이
                    road[i][j] = road[i][j-1] % 1000000007;
                else if(j == 0) //가생이
                    road[i][j] = road[i-1][j] % 1000000007;
                else //나머지는 그냥 더해서 넣어주기
                    road[i][j] = (road[i][j-1] + road[i-1][j]) % 1000000007;
            }
        }
    }
    
    answer = road[m-1][n-1];
    return answer;
}


/*
정확성 테스트만 100점 , 효율성 시간초과
BFS로 풀기


#include <string>
#include <vector>
#include <queue>
using namespace std;
//m=j, n=i, house = 1,1 / school = m,n
//움직인 칸수만 세기 (집, 학교 포함 x)
struct Point{
    int x;
    int y;
    long long dist;
    Point(int a, int b, int c){
        x = a;
        y = b;
        dist = c;
    }
};
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0; 
    long mapp[101][101];
    for(auto p : puddles){
        mapp[p[1]][p[0]] = 690285631;
    }
    
    int dx[2] = {0, 1};
    int dy[2] = {1, 0};
    queue<Point> q;
    q.push(Point(1,1,0 % 1000000007));
    int cnt =0, mini =-1;
    while(!q.empty()){
    	Point cur = q.front();
        q.pop();
        
        if(cur.x == n && cur.y == m) {
            if(cnt ==0) {
                mini = cur.dist;
                cnt++;
            }
            else{
                if(mini == cur.dist) cnt++;
            }
        }
        
        for(int i=0; i<2;i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx > n || ny > m || mapp[nx][ny] == 690285631) continue;
            
            q.push(Point(nx,ny,(cur.dist + 1)% 1000000007));
            
        }
        
    }
    //최단경로의 개수 % 로 리턴
    
    answer = cnt % 1000000007;
    return answer;
}

*/