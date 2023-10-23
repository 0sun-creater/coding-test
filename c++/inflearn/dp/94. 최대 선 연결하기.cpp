/*
왼쪽의 번호와 오른쪽의 번호가 있는 그림에서 같은 번호끼리 선으로 연결하려고 합니다. 
왼쪽번호는 무조건 위에서부터 차례로 1부터 N까지 오름차순으로 나열되어 있습니다. 
오른쪽의 번호 정보가 위부터 아래 순서로 주어지만 서로 선이 겹치지 않고 최대 몇 개의 선 을 연결할 수 있는 지 구하는 프로그램을 작성하세요.
위의 그림은 오른쪽 번호 정보가 4 1 2 3 9 7 5 6 10 8 로 입력되었을 때 선이 서로 겹치지 않고 연결할 수 있는 최대 선을 개수 6을 구한 경우입니다.
*/

#include <iostream>

using namespace std;

int main(){
    int n, tmp;
    cin >> n;
    int *right = new int[n+1];
    int *dp = new int[n+1];
    memset(dp, 0, sizeof(dp));
    for(int i=1; i <= n; i++){
        cin >> tmp;
        right[i] = tmp; 
    }
    dp[1] = 1;
    int maxi =-1;
    for(int i =2; i<=n; i++){
        for(int j= i-1; j>0; j--){
            if(right[i] > right[j] && dp[j] > maxi){
                maxi = dp[i];
            }
        }
    }

}