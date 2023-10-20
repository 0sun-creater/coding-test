#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

/*
조각 뒤집기 불가능, 회전 가능
조각과 보드는 상하좌우 인접해 붙어있는 경우 없음 -> 경로 찾기로 가능

최대한 많은 조각을 채워 넣을 경우 칸 수 출력

보드에서 1은 벽 0은 빈칸  -->0을 찾아야함
조각에서 1은 조각 0은 빈칸 -->1을 찾아야함
*/
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
struct Point{
    int x;
    int y;
};

vector<vector<bool> > check; // 방문 처리
vector<vector<Point> > puzzleList; // 퍼즐을 담는 리스트
vector<vector<Point> > emptyList; // 빈 공간을 담는 리스트



// 90도 한번 돌리기
vector<vector<bool>> rotateOnce(vector<vector<bool> > origin){

    int c = origin.size(); // 행
    int r = origin.size(); // 열

    // 반환할 90도 돌아간 보드판
    vector<vector<bool>> board;
    vector<bool> row(r);

    for(int i = 0; i < c; i++) board.push_back(row);

    // 90도 돌리는 작업
    for(int i = 0; i < origin.size(); i++){
        for(int j = 0; j < origin[i].size(); j++){
            board[origin.size()-j-1][i] = origin[i][j];
        }
    }
    return board;
}

// 다시 방문하지 않도록 빈 공간 메우기
vector<vector<bool>> fillBoard(vector<Point> p, vector<vector<bool> > board){
    for(int i = 0; i < p.size(); i++){
        int x = p[i].x;
        int y = p[i].y;
        board[x][y] = false;
    }
    return board;
}

// 빈공간, 퍼즐 추출하기 
// select를 통해 보드판, 퍼즐판 구분
vector<Point> getPuzzle(int sx,int sy,vector<vector<bool>> select){
    int dx[] = {0,0,-1,1};
    int dy[] = {-1,1,0,0};
    
    queue<Point> q;
    vector<Point> list;
    check[sx][sy] = true;
    Point p = {sx,sy};
    q.push(p);
    list.push_back(p);


    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= select.size() || ny >= select.size() 
            || check[nx][ny] || !select[nx][ny]) continue;
            check[nx][ny] = true;
            Point np = {nx,ny};
            q.push(np);
            list.push_back(np);
        }
    }
    return list;
}

// (0,0)으로 리포지션 시키는 함수
vector<Point> rePos(vector<Point> p){
    int minX = p[0].x;
    int minY = p[0].y;

    for(int i = 1; i < p.size(); i++){
        minX = min(minX,p[i].x);
        minY = min(minY,p[i].y);
    }

    for(int i = 0; i < p.size(); i++){
        p[i].x -= minX;
        p[i].y -= minY;
    }
    return p;

}
// 두 퍼즐이 일치하는지 비교하는 함수
int comparePuzzle(vector<Point> a, vector<Point> b){
    int answer = 0;
    a = rePos(a);
    b = rePos(b);

    int count = 0;
    // 애초에 개수가 일치하지 않으면 틀림
    if(a.size() != b.size()) return 0;

    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            if(a[i].x == b[j].x && a[i].y == b[j].y){
                count++;
                break;
            }
        }
    }
    // 일치하는 좌표의 개수가 같을 때만 맞음
    if(count == a.size()) return a.size();
    else return 0;
}

int solution(vector<vector<int> > game_board, vector<vector<int> > table) {
    vector<vector<bool> > board;
    vector<vector<bool> > puzzles;
    for(int i = 0; i < table.size(); i++){
        vector<bool> v1;
        vector<bool> v2;
        vector<bool> v3;
        for(int j = 0; j < table[i].size(); j++){
            v1.push_back(!game_board[i][j]);
            v2.push_back(table[i][j]);
            v3.push_back(false);
        }
        board.push_back(v1);
        puzzles.push_back(v2);
        check.push_back(v3);
    }

    for(int i = 0; i < puzzles.size(); i++)
        for(int j = 0; j < puzzles[i].size(); j++)
            if(!check[i][j] && puzzles[i][j]) puzzleList.push_back(getPuzzle(i,j,puzzles));

    int count = 4;
    int answer = 0;
    fill(check.begin(),check.end(),vector<bool>(check.size(),false));
    
    while(count--){
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board.size(); j++)
                if(board[i][j] && !check[i][j]) 
                    emptyList.push_back(getPuzzle(i,j,board));

        for(int i = 0; i < puzzleList.size(); i++){
            for(int j = 0; j < emptyList.size(); j++){
                int val = comparePuzzle(puzzleList[i],emptyList[j]);
                if(val != 0) {
                    answer += val;
                    board = fillBoard(emptyList[j],board);
                    puzzleList.erase(puzzleList.begin()+i);
                    emptyList.erase(emptyList.begin()+j);
                    i--;
                    break;
                }
            }
        }
        board = rotateOnce(board);

        fill(check.begin(),check.end(),vector<bool>(check.size(),false));
    }
    return answer;
}


/*

시간 초과 코드
struct Position{
    int x;
    int y;
};

vector<vector<Position>> pieces;
vector<int> pieces_size;

bool visited[51][51];
bool piece_visited[51];
vector<vector<int>> table;
vector<vector<int>> game_board;

//좌표 (x,y) 90도 회전 -> (-y,x)
vector<Position> rotate(vector<Position> vr){
    vector<Position> result;
	Position pos;
    for(int i=0; i< vr.size(); i++){
        pos.x = -vr[i].y;
        pos.y = vr[i].x;
        result.push_back(pos);
    }
    
    return result; 
}

int dx[4] = {1,0,0,-1};
int dy[4] = {0,-1,1,0};

//mode =0 보드
//mode =1 조각
vector<Position> search(int x, int y, vector<vector<int>> board,int mode){
	vector<Position> result;
    queue<Position> q;
    
    visited[x][y] = true;
    Position pos = {x,y};
    q.push(pos);
    
    //0,0을 기준으로 만든다.
    //result의 음수가 있으면 다른 모든 조각에 +해준다
    int sum_x =0, sum_y = 0;
    result.push_back({0,0});
    
    while(!q.empty()){
        int cur_x = q.front().x;
        int cur_y = q.front().y;
        q.pop();
        
        for(int i =0; i<4; i++){
            int nx = cur_x+ dx[i];
            int ny = cur_y+ dy[i];
            
            if(nx < 0 || ny < 0 || nx > board.size() || ny > board.size() || visited[nx][ny] || board[nx][ny] == mode){
                continue;
            }
            visited[nx][ny] = true;
            Position np = {nx, ny};
            q.push(np);
            if (nx-x < 0) sum_x += abs(nx-x);
            if (ny-y < 0) sum_y += abs(ny-y);
            result.push_back({nx-x, ny-y});
        }
    }
    
    for(int i =0 ;i <result.size();i++){
        result[i].x += sum_x;
        result[i].y += sum_y;
    }
    
    return result;
}

bool possible(vector<Position> _piece, vector<Position> _empty,int size){
	for(int i =0; i < size; i++){
        if(_piece[i].x != _empty[i].x) return false;
        if(_piece[i].y != _empty[i].y) return false;
    }	
    
    return true;
}

int check(){
    int piece_len = pieces.size();
    int board_len = game_board.size();
    
	memset(piece_visited, false, sizeof(piece_visited));
    memset(visited, false, sizeof(visited));

    
    int result =0;
    bool flag = true;
    for(int i =0; i < board_len; i++){
        for(int j =0; j<board_len; j++){
            if (visited[i][j] || game_board[i][j] == 1) continue;
            
            vector<Position> empty = search(i,j, game_board, 0);
            int empty_len = empty.size();
            
            for(int k =0; k < piece_len; k++){
                if (piece_visited[k]) continue;
                    
                if (pieces_size[k] != empty_len) continue;
                    
                if (possible(pieces[k], empty, pieces_size[k])){
                    piece_visited[k] = true;
                    result += pieces_size[k];
                    break;
                }
            }
        }
    }
	
    return result;
    
}

int solution(vector<vector<int>> _game_board, vector<vector<int>> _table) {
    table = _table, game_board = _game_board;
    int answer = -1;
    int size = table.size();

    memset(visited, false, sizeof(visited));
    
    //table에서 조각 잘라내서 리스트에 넣기
    //회전 시킨 조각 추가
    for (int i =0; i<size; i++){
        for(int j =0; j<size; j++){
            if (table[i][j] ==1 && visited[i][j] ==false){
                vector<Position> tmp = search(i,j,table,1);
                pieces.push_back(tmp);
                pieces_size.push_back(tmp.size());
                for(int k=0; k<3; i++){
                    tmp = rotate(tmp);
                    pieces.push_back(tmp);
                    pieces_size.push_back(tmp.size());
                }
            }
        }
    }
    
    //보드판에 모든 퍼즐을 한 번씩 끼워서 확인
    answer = check();
    
    
    return answer;
}

*/