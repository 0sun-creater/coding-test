#include <string>
#include <vector>
#include <queue>

using namespace std;
/*
123
456
789
*0#

숫자로만 이루어진 긴 문자열을 누가 가장 빠르게 타이핑하는지 겨루는 대회
4 6 시작
이동 안하면 1
상하좌우 이동하면 2
대각선으로 이동함면 3
같지 않고 인접하지 않은 숫자는 가중치 합이 최소가 되는 경로

같은 숫자 버튼 위에 동시에 두 엄지 손가락을 올려놓을 수 없음 
즉, 어떤 숫자를 눌러야 할 차례에 그 숫자 위에 올려져 있는 손가락이 있다면 반드시 그 손가락으로 눌러야함
최소한의 시간으로 타이핑하는 경우의 가중치의 합 구하기
*/


//DP [A][B][C] = K
//A까지 탐색했고, 현재 왼손이 B번, 오른손이 C번에 있을 때의 최소 비용은 K
/* 왼쪽과 오른쪽과 함께 인덱스 번호까지 포함하여 3차원 배열을 만들어야 한다는 것이다.
왜냐하면 왼쪽과 오른쪽 손의 위치만 가지고 배열을 만들면,
다른 층(인덱스)에 있는 저장된 값과 겹쳐서 값이 다르게 나올 수 있기 때문이다.
*/

// 좌표 구조체
struct Point{
    int x,y;
};

// 숫자판
char map[4][3] = {{'1','2','3'},
                {'4','5','6'},
                {'7','8','9'},
                {'*','0','#'}};
vector<Point> input; // 숫자 입력 순서
int dp[100001][10][10]; // dp 배열

// 두 점 사이의 최소 가중치를 계산하는 함수
int getWeight(Point pos, Point target){
    int sx = pos.x;
    int sy = pos.y;

    int x = target.x;
    int y = target.y;
	
    // 두 점이 동일할 때(정지)
    if(sx == x && sy == y) return 1;
	
    // 상하좌우(일직선) 일 때
    if(sx == x || sy == y) return abs((sx-x)*2 + (sy-y)*2);
	
    // 대각선일때
    if(abs(sx - x) == abs(sy - y)) return abs(sx-x)*3;
	
    // 그 외 일 때
    int nx = abs(sx-x);
    int ny = abs(sy-y);
    int diag = min(nx,ny);
    int line = max(nx,ny);

    return diag *3 + (line-diag)* 2;
}

// 시뮬레이션을 돌림
int startGame(Point left, Point right, int idx){
    if(idx >= input.size()) return 0;// 인덱스를 다 돌았으면 종료

    
    // left와 right의 좌표가 동일하면 안됨
    if(left.x == right.x && left.y == right.y) return 9999999;
    
    int l_num = map[left.x][left.y]-'0'; // 왼손의 현재 번호
    int r_num = map[right.x][right.y]-'0'; // 오른손의 현재 번호 
    
    
    // dp 배열에 저장되어 있는 값이 있으면 바로 반환
    if(dp[idx][l_num][r_num] != 0) return dp[idx][l_num][r_num];
    
    //각 손으로 위치로 갔을 때의 최소 비용
    int l_weight = getWeight(left,input[idx]);
    int r_weight = getWeight(right,input[idx]);
    
    // 해당 위치로 갔을 경우 최소 비용의 합
    int v1 = l_weight + startGame(input[idx],right,idx+1);
    int v2 = r_weight + startGame(left,input[idx],idx+1);
	
    // 더 작은 값을 dp 배열로 저장
    return dp[idx][l_num][r_num] = min(v1,v2);
    
}
int solution(string numbers) {
    int answer = 0;
    for(int k = 0; k < numbers.length(); k++){
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 3; j++)
            	// 입력값의 좌표를 찾아서 input에 저장
                if(map[i][j] == numbers[k]) input.push_back({i,j});
    }
    Point left = {1,0}; // 왼손 초기 위치
    Point right = {1,2}; // 오른손 초기 위치
    answer = startGame(left,right,0);
    return answer;
}