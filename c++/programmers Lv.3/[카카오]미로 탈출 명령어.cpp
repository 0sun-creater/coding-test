#include <string>
#include <vector>
#include <cmath>
using namespace std;

//격자크기 n,m
//출발 (x,y)
//도착 (r,c)
//이동거리는 무조건 k, 같은 격자 두번 이상 가능
//경로를 문자열 > 문자열이 사전 순으로 가장 빠른 경로로 탈출
//경로 존재안하면 impossible
int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};
string ds[4] = {"d","l","r","u"}; //사전 순으로 돌기

int n, m, r, c, k;
bool flag = false; //처음으로 조건이 충족하는 경우가 답
string answer = "";
string stack ="";

//재방문 가능 visited x
void DFS(int x, int y, int cur_k){
    if (flag) return;
    
	int dist =  abs(x-r) + abs(y-c);
    if(k - cur_k < dist || (k - cur_k - dist) % 2 == 1 ) {
        return;
    }
    
    if (cur_k == k ){
        if(x == r && y == c){
            answer = stack;
            flag = true;
        }
        return;
    }
    
    for(int i =0; i< 4; i++){
    	int new_x = x + dx[i];
    	int new_y = y + dy[i];
        //cout << new_x << " " <<new_y <<endl;
        if(new_x <= n && new_x > 0 && new_y <= m && new_y >0){
        	stack += ds[i];
            DFS(new_x, new_y,cur_k+1);
        	stack.pop_back();
        } 
    }

    
}
string solution(int _n, int _m, int _x, int _y, int _r, int _c, int _k) {
	n = _n, m = _m, r = _r, c = _c, k = _k;

    
    //도착지까지의 최소 이동 횟수
    int min_move = abs(r-_x) + abs(c-_y);
	//홀수면 도착못함
    if(min_move > k || (k-min_move) % 2 == 1){
        return "impossible";
    }
    DFS(_x,_y,0);
    
    
    return answer;
}