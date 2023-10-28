#include <string>
#include <vector>
#include <queue>

using namespace std;
//0 빈칸 1 벽
//(0,0) 출발, (n-1,n-1)도착
//중간에 끊기지 않게 경주로 건설
//상하좌우 인접 두빈칸 연결하여 건설 가능 - 벽 불가능 
//경주로를 건설하는 데 필요한 최소 비용 계산

//edge 하나에 도로 1
//코너  : row증가에서 column증가로 변환
//		 column증가에서 row증가로 변환
//이전 도로가 어떻게 생겼는지 기억해야된다는 말
//그냥 (0,0 에서 n-1,n-1까지 최단거리가 최단이지 않나?) 아니네ㅋ
//직선 100원 코너 500원
struct node{
    int x;
    int y;
    int c;
    int prev; //1이면 row 2면 column
    node(int a, int b, int c, int d):x(a), y(b), c(c), prev(d){}
};
struct cmp{
    bool operator() (node &a, node&b){
        return a.c > b.c; //pq에서는 오름차순
    }
};
const int INF = 987654321;
int cost[26][26][4]; //3번째는 방향
int solution(vector<vector<int>> board) {
    int answer = INF;
    int n = int(board.size());

    for(int i = 0; i < 26; i++)
        for(int j = 0; j < 26; j++)
            for(int k = 0; k < 4; k++)
                cost[i][j][k] = INF;
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,-1,0,1};
    
    priority_queue<node, vector<node>, cmp> q;
    q.push(node(0,0,0,0));
    q.push(node(0,0,0,1));
    q.push(node(0,0,0,2));
    q.push(node(0,0,0,3));
	cost[0][0][0] = 0;
    cost[0][0][1] = 0;
    cost[0][0][2] = 0;
    cost[0][0][3] = 0;

    while(!q.empty()){
        node cur = q.top();
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(abs(cur.prev - i) == 2) continue; //이전 칸으로 돌아가는 경우
            if(nx<0 || ny<0 || nx>=n || ny>=n || board[nx][ny]==1) continue;
            int _cost = 0;
            if(cur.prev == i) _cost = 100; //직진코스
            else _cost = 600; //500원이 추가로 드는거임
            
            int nextCost = cur.c + _cost;
            if(cost[nx][ny][i] > nextCost){
                cost[nx][ny][i] = nextCost;
                q.push(node(nx,ny,nextCost, i));
            }
                
        }
    }
    for(int i=0; i<4; i++){
    	answer = min(answer,cost[n-1][n-1][i]);
    }

    return answer;
}