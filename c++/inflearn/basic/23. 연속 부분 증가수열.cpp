//연속 부분 증가수열
//N개의 숫자가 나열된 수열이 주어집니다. 
//이 수열 중 연속적으로 증가하는 부분 수열을 최대 길이를 구하여 출력하는 프로그램을 작성하세요.

#include <iostream>
using namespace std;

int main(){
    int n,prev,tmp;
    cin >> n;

    int cnt =1, max = -2147000000;
    cin >> prev;
    for (int i =1 ; i<n;i++){
        cin >>tmp;
        if (prev <= tmp) cnt ++;
        else{ cnt = 1; }
        if (max < cnt) max = cnt;
        prev = tmp;
    }
    cout << max;
}