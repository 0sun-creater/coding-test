#include <string>
#include <vector>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;
    int n = int(money.size());
    int dp[1000001];
    dp[0] = money[0];
    dp[1] = dp[0];
    for(int i=2; i<n-1;i++){
        dp[i] = max(dp[i-2]+money[i], dp[i-1]);
    }
    
    int dp2[1000001];
    dp2[0] = 0;
    dp2[1] = money[1];
    for(int i=2; i<n;i++){
        dp2[i] = max(dp2[i-2]+money[i],dp2[i-1]);
    }
    
    answer = max(dp[n-2],dp2[n-1]);
    return answer;
}