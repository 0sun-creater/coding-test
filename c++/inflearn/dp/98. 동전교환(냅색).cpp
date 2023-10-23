/*
 여러 단위의 동전들이 주어져 있을때 거스름돈을 가장 적은 수의 동전으로 교환 해주려면 어떻게 주면 되는가? 
 각 단위의 동전은 무한정 쓸 수 있다.
 출력 : 거슬러 줄 동전의 최소 개수
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int &a, int &b){
    return a > b;
}
int main(){
    int n,tmp; //동전 종류 개수
    cin >> n;
    //동전의 종류
    vector<int> coin;
    for(int i=0; i<n; i++){
        cin >> tmp;
        coin.push_back(tmp);
    }
    //거슬러 줄 금액 <=500
    int m;
    cin >> m;

    sort(coin.begin(), coin.end(), compare);

    vector<int> dp(m+1, 1001);
    dp[0]=0;
    for(int i=0; i<n; i++){
        //cout << coin[i] << endl;
        for(int j =coin[i]; j<m+1; j++){
            if ( dp[j] > dp[j-coin[i]] + 1){
                dp[j] = dp[j-coin[i]] +1;
            }
        }
        /*
        for(int k=0; k<=m;k++){
            cout << dp[k] << " ";
        }
        cout <<endl;
        */
    }
    
    cout << dp[m];
}