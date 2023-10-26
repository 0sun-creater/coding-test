#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
e 가 주어짐
e 이하의 임의의 수 s를 여러개 얘기함 (starts)
각 s에 대해서 s보다 크거나 같고 e보다 작거나 같은 수 중에서 (s~e) 억억단에서 가장 많이 등장한 수
 만약 가장 많이 등장한 수가 여러 개라면 그 중 가장 작은 수
e <= 5,000,000
*/

//s~e까지 소인수가 가장 많은 수
//숫자가 같으면 가장 작은 수 


vector<int> solution(int e, vector<int> starts)
{
    vector<int> answer, v(e+1, 1), dp(e+1, 0);
    //starts의 원소중 가장 작은값
    int s = *min_element(starts.begin(), starts.end());
    
    // v[i]는 i의 약수의 개수 이다.
    for(int i=2;i<=e;i++){
        for(int j=i;j<=e;j+=i){
       		v[j]++;
        }
    }
    dp[e] = e;
    //중복되는 약수 최대값이면 값이 작은것으로 갱신해줘야해서 거꾸로 간다.
    for(int i=e-1;i>=s;i--)
    {
        // i의 약수개수가 이전까지의 범위에서의 최대 약수의 개수보다 크거나 같다면 갱신
        // 아니라면 이전값 그대로 전달
        if (v[i] >= v[dp[i+1]]) dp[i] = i;
        else dp[i] = dp[i+1];
    }
    
    for(auto s : starts) answer.push_back(dp[s]);
    return answer;
}
/* 시간 초과
vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;
    int cnt = 0;
    int max = -1, idx=0;
    int dp[5000001];
    sort(starts.begin(), starts.end(), )
    for(auto s : starts){
        
        for(int num = s; num <=e; num++){
           cnt =0;
           for (int i=1; i <= num / 2; i++) {
                if (num % i == 0) cnt ++;
           }
           if(max < cnt) {
               max = cnt;
               idx = num;
           }
        }
        answer.push_back(idx);
        dp[s] = idx;
    }
    return answer;
}
*/