#include <string>
#include <vector>
#include <iostream>
#include <deque>
using namespace std;

int n, m;

//효율성 1개 세그먼테이션 오류 2개
void Rotate3(vector<vector<int>> &rc){
    deque<int> up, down, right, left;
    for(int i=1; i<m; i++) {
        up.push_back(rc[0][i]);
        down.push_front(rc[n][i]);
    }
    for(int i=0; i<=n; i++) {
        right.push_back(rc[i][m]);
        left.push_front(rc[i][0]);
    }
    
    right.push_front(up.back());
    up.pop_back();
    down.push_front(right.back());
    right.pop_back();
    left.push_front(down.back());
    down.pop_back();
    up.push_front(left.back());
    left.pop_back();
    
    for(int i=1; i<m; i++) {
        rc[0][i] = up.front();
        rc[n][i] = down.back();
        up.pop_front();
        down.pop_back();
    }
    for(int i=0; i<=n; i++) {
        rc[i][m] = right.front();
        rc[i][0] = left.back();
        right.pop_front();
        left.pop_back();
    }
}

//효율성 테스트 전체 통과 x
void ShiftRow2(vector<vector<int>>&rc){
    vector<int> rc_copy = rc[n];
    for(int i =n; i >0; i--){
       rc[i] = rc[i-1];
    }
    rc[0] = rc_copy;
}

//효율성 테스트 9개 중 1개통과
void Rotate2(vector<vector<int>> &rc){
    vector<vector<int>> rc_copy = rc;
    //상
    for( int i = 1; i <= m; i++){
        rc[0][i] = rc_copy[0][i-1];
	}
    //우
    for(int i =1; i<= n; i++){
        rc[i][m] = rc_copy[i-1][m];
    }
    //하
    for(int i=1; i <= m; i++){
        rc[n][i-1] = rc_copy[n][i];
    }
    //좌
    for(int i=1; i<= n; i++){
        rc[i-1][0] = rc_copy[i][0];
    }
    
}


//모든 행이 아래쪽으로 한칸씩 밀려나는 함수 
//효율성 테스트 9개 중 1개 통과
void ShiftRow(vector<vector<int>> &rc){
    vector<int> tmp = rc[n];
    rc.pop_back();
    rc.insert(rc.begin(), tmp);
}

//행렬의 바깥쪽에 있는 원소들을 시계 방향으로 한칸 회전시키는
//함수 효율성 테스트 9개 중 1개 통과
void Rotate(vector<vector<int>> &rc){
    vector<vector<int>> rc_copy = rc;
    int i=0, j=1;
	rc[0][0] = rc[1][0];
    while(i!=0 || j!=0){
        if(i==0) {
            rc[i][j] = rc_copy[i][j-1];
            if(j==m){
                i++;
                continue;
            }
        	j++;
            continue;
        }
        if(j==m){
            rc[i][j] = rc_copy[i-1][j];
            if(i==n){
                j--;
                continue;
            }
            i++;
            continue;
        }
        if(i==n){
            rc[i][j] = rc_copy[i][j+1];
            if(j==0){
                i--;
                continue;
            }
            j--;
            continue;
        }
        if(j==0){
            rc[i][j] = rc_copy[i+1][j];
            i--;
            continue;
        }
        
        
    }
}

//rc : 행렬의 초기상태 <=50,000 x 50,000
//operations : 시행 연산
//연산을 차례대로 시행한 후의 행렬 상태 리턴
vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    vector<vector<int>> answer;
    n = int(rc.size())-1;
    m = int(rc[0].size())-1;
    
    for(auto oper : operations){
        if(oper == "Rotate"){
            Rotate3(rc);
        }
        else{
            ShiftRow(rc);
        }
        
    }
    answer = rc;
    return answer;
}
/*
deque를 이용한 정답 코드
vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    int r = rc.size();
    int c = rc[0].size();
    //처음에 저장한번 한 걸로 shiftrow와 rotate를 전부 다 할 수 있음
    deque<int> col1, col2;
    for(int i = 0; i < r; i++){
        col1.push_back(rc[i][0]);
        col2.push_back(rc[i][c-1]);
    }

    deque<int> rows[r];
    for(int i = 0; i < r; i++)
        for(int j = 1; j <= c-2; j++)
            rows[i].push_back(rc[i][j]);
    
    int idx = 0;
    for(auto op : operations){
        if(op == "ShiftRow"){
            col1.push_front(col1.back());
            col1.pop_back();
            col2.push_front(col2.back());
            col2.pop_back();
            idx--;
            if(idx == -1) idx = r-1;
        }
        else{ // Rotate
            rows[idx].push_front(col1.front());
            col1.pop_front();
            
            col2.push_front(rows[idx].back());
            rows[idx].pop_back();
            
            rows[(idx+r-1)%r].push_back(col2.back());
            col2.pop_back();
            
            col1.push_back(rows[(idx+r-1)%r].front());
            rows[(idx+r-1)%r].pop_front();
        }
    }
    
    
    vector<vector<int>> ret(r, vector<int>(c));
    for(int i = 0; i < r; i++){
        ret[i][0] = col1[i];
        for(int j = 1; j <= c-2; j++)
            ret[i][j] = rows[(i + idx) % r][j-1];
        ret[i][c-1] = col2[i];
    }
    return ret;
}
*/