/*

철수는 계단을 오를 때 한 번에 한 계단 또는 두 계단씩 올라간다. 만약 총 4계단을 오른다면 그 방법의 수는
1+1+1+1, 1+1+2, 1+2+1, 2+1+1, 2+2 로 5가지이다.
그렇다면 총 N계단일 때 철수가 올라갈 수 있는 방법의 수는 몇 가지인가?
*/

#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int dp[50];
    dp[1] =1;
    dp[2] =2;
    for(int i=3; i<= n; i++){
        dp[i] = dp[i-2] + dp[i-1];
    }

    cout << dp[n];

}