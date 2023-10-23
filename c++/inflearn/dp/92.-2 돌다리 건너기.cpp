/* top-down방식
철수는 학교에 가는데 개울을 만났습니다. 개울은 N개의 돌로 다리를 만들어 놓았습니다. 
철수는 돌 다리를 건널 때 한 번에 한 칸 또는 두 칸씩 건너뛰면서 돌다리를 건널 수 있습니다.
철수가 개울을 건너는 방법은 몇 가지일까요?
*/

//bottom_up이 보통 dp임
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int dp[50];
    dp[1] =1;
    dp[2] =2;
    for(int i =3; i<= n+1; i++){
        dp[i] = dp[i-2] + dp[i-1];
    }
    
    //n+1 인 이유 : 7번째 돌맹이가 아니라 한번 더뛰어서 도착지점에 가야함
    cout << dp[n+1];

}