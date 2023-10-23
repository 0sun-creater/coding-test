/*
N개의 자연수로 이루어진 수열이 주어졌을 때, 그 중에서 가장 길게 증가하는(작은 수에서 큰 수로)
원소들의 집합을 찾는 프로그램을 작성하라. 
예를 들어, 원소가 2, 7, 5, 8, 6, 4, 7, 12, 3 이면 가장 길게 증가하도록 원소들을 차례대로 뽑아내면 
2, 5, 6, 7, 12를 뽑아내어 길 이가 5인 최대 부분 증가수열을 만들 수 있다.

*/

#include <iostream>

using namespace std;

int main(){
    int n, tmp;
    cin >> n;
    int *input = new int[n+1];
    for(int i =1; i<n+1;i++){
        cin >> tmp;
        input[i] = tmp;
    }
    int *dp = new int[n+1];
    memset(dp, 0, sizeof(dp));
    dp[1] = 1;
    for(int i =2; i <=n; i++){
        int maxi = -1;
        for(int j =i-1; j>0; j--){
            if(input[i] > input[j] && dp[j] > maxi){
                maxi = dp[j];
            }
        }
        dp[i] = maxi +1;
    }

    int maxii =-1;
    for(int i=1; i<n+1; i++){
        if(maxii < dp[i]) maxii = dp[i];
    }
    cout << maxii;

}
