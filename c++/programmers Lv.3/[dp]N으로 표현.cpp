#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
int getNs(int N, int idx) { 
    int result = N; 
    for (int i = 2; i <= idx; i++) { 
        result = result * 10 + N; 
    } 
    return result; 
} 

int solution(int N, int number) {
    int answer = 0;
    vector<unordered_set<int> > dp(9);

    if (N == number) return 1;
    
    dp[1].insert(N);
    for(int i=2; i < 9; i++){
		dp[i].insert(getNs(N, i));
        
        for(int j=1; j< i; j++){
            for(auto prev : dp[j]){
                for(auto cur : dp[i-j]){
					dp[i].insert(prev + cur);
                    dp[i].insert(prev - cur);
                    dp[i].insert(prev * cur);
                    
                    if(prev != 0 && cur != 0){
                        dp[i].insert(prev / cur);
                    } 
                }
            }
        }
        if(dp[i].find(number) != dp[i].end()) {
            //해당 값 있음
            return i;
        }
        
    }
    return -1;
}