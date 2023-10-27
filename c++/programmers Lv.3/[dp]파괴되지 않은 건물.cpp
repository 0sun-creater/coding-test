#include <string>
#include <vector>
#include <iostream>

using namespace std;

//skill[0] = 1이면 -, 2면 +
//r1c1~r2c2
//skill[5]만큼
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int n = int(board.size());
    int m = int(board[0].size());
    vector<vector<int>> dp(n+10, vector<int> (m+10, 0));
    int i, j,r1,c1,r2,c2, d;
    for(auto s : skill){
        r1 = s[1], c1 = s[2], r2 = s[3], c2 = s[4], d=s[5];
        if(s[0]==1) d = s[5] * -1;
        
        dp[r1][c1] += d;
        dp[r1][c2+1] -= d;
        dp[r2+1][c1] -= d;
        dp[r2+1][c2+1] += d;		
    }
    //dp 누적합으로 만들기
    for(int i=1; i<=n; i++){
        dp[0][i] += dp[0][i-1]; 
        dp[i][0] += dp[i-1][0];
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
        }
    }
    
    for(i=0; i < n; i++){
        for(j=0; j< m; j++){
            board[i][j] += dp[i][j];
            if(board[i][j] > 0) answer ++;
        }
    }
    return answer;
}