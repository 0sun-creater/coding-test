#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int INF = 1999999999;

// 모든 문제를 풀 필요가 없이, 가장 높은 알고력과 코딩력을 만들면 된다.
int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    int last = problems.size() - 1;
    int min_time;
    int alp_req = -1;
    int cop_req = -1;
    
    for (int i = 0; i <= last; i++) {
        if (alp_req < problems[i][0]) {
            alp_req = problems[i][0];
        }
        if (cop_req < problems[i][1]) {
            cop_req = problems[i][1];
        }
    }
    
    if (alp_req <= alp && cop_req <= cop) {
        return 0;
    }
    
    vector<vector<int>> dp(alp_req + 1, vector<int>(cop_req + 1, INF));
    
    if (alp > alp_req) {
        alp = alp_req;
    }
    if (cop > cop_req) {
        cop = cop_req;
    }
    
    dp[alp][cop] = 0;
    
    
    for (int i = alp; i <= alp_req; i++) {
        for (int j = cop; j <= cop_req; j++) {
            if (j + 1 <= cop_req) {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
            }
            if (i + 1 <= alp_req) {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
            }
            for (int k = 0; k <= last; k++) {
                if (i >= problems[k][0] && j >= problems[k][1]) {
                    // 알고력 요구치(또는 코딩력 요구치)를 넘어서면 최댓값으로 고정
                    dp[min(i + problems[k][2], alp_req)][min(j + problems[k][3], cop_req)] = min(dp[min(i + problems[k][2], alp_req)][min(j + problems[k][3], cop_req)], dp[i][j] + problems[k][4]);
                }
            }
        }
    }
    
    answer = dp[alp_req][cop_req];
    return answer;
}