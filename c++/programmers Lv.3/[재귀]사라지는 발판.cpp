#include <string>
#include <vector>

using namespace std;

//solve(board, y1, x1, y2, x2) = (y1,x1)에 위치한 플레이어의 턴일 때 최선의 플레이 시 승리 여부와 최적의 플레이 시 턴 수

int N,M;
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

bool inRange(int y, int x) {
    return 0<= y && y < N && 0 <= x && x < M;
}

bool isFinished(vector<vector<int>>& board, int y, int x) {
    for(int i=0; i<4; i++) {
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(inRange(ny,nx) && board[ny][nx])
            return false;
    }
    return true;
}
pair<bool, int> solve(vector<vector<int>>& board, int y1, int x1, int y2, int x2) {
	//1.A의 차례일 때 움직일 수 없다면 A가 패배하고
    if(isFinished(board, y1, x1)) return {false, 0};
	//2.움직일 수 있으면서 A와 B가 같은 발판에 있다면 A가 어디로 움직이던 간에 다음 턴에 B가 패배한다. 
	if(y1==y2 && x1==x2) return {true, 1};
    
    //이 이후 모든 경우의 수를 탐색하며 승리할 수 있을 시엔 최소 턴 수를 반환하고, 무조건 패배할 시에는 최대 턴 수와 함께 반환해주면 된다.
    bool canWin = false;
    int minTurn = 1e9, maxTurn = 0;
    
    for(int i=0; i<4; i++) {
        int ny = y1+dy[i];
        int nx = x1+dx[i];
        if(!inRange(ny,nx) || !board[ny][nx]) continue;
        
        board[y1][x1] = 0;
        //다음턴은 상대방이니까 바꿔야돼
        pair<bool, int> res = solve(board, y2, x2, ny, nx);
        board[y1][x1] = 1;
        
        // 이때 res는 상대편에 대한 결과이므로 반대로 생각
        if(!res.first) {
            canWin = true; //내가 이기면 최소값
            minTurn = min(minTurn, res.second + 1);
        }
        else if(!canWin) { //내가 지면 최대값
            maxTurn = max(maxTurn, res.second + 1);
        }
    } //내가 이긴거에 따라서 min이나 max 리턴해주기
	return {canWin, (canWin ? minTurn : maxTurn)};

}

int solution(vector<vector<int>> board, vector<int> aloc, vector<int> bloc) {
    N = board.size(), M = board[0].size();
	//승패는 중요하지 않고 최선의 이동만 print(second)
    return solve(board, aloc[0], aloc[1], bloc[0], bloc[1]).second;
}