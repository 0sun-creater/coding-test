/*

현수는 네트워크 선을 1m, 2m의 길이를 갖는 선으로 자르려고 합니다. 예를 들어 4m의 네트워크 선이 주어진다면
1) 1m+1m+1m+1m 2) 2m+1m+1m
3) 1m+2m+1m
4) 1m+1m+2m
5) 2m+2m
의 5가지 방법을 생각할 수 있습니다. (2)와 (3)과 (4)의 경우 왼쪽을 기준으로 자르는 위치가 다르면 다른 경우로 생각한다.
그렇다면 네트워크 선의 길이가 Nm라면 몇 가지의 자르는 방법을 생각할 수 있나요?
*/

#include <iostream>
using namespace std;


int dp(int n){
    int res[50];

    res[1] = 1;
    res[2] = 2;
    for(int i =3; i< n; i++){
        res[i] = res[i-2] + res[i-1];
    }
    return res[n];
}

int dfs_res[101];이
int dfs(int n){
    if(dfs_res[n] > 0) return dfs_res[n]; //안하면 오래걸림 (이미 구해진것 - 메모제이션)
    if (n == 1 || n == 2) return n;
    else return dfs_res[n] = dfs(n-1) + dfs(n-2);
}


int main(){
    //입출력 속도 빠르게 하기 위함
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int _n;

    cout << dp(_n);    
    //cout << dfs(_n);
}