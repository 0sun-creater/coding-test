//자연수 N이 입력되면 1부터 N까지의 소수의 개수를 출력하는 프로그램을 작성하세요.
//만약 20이 입력되면 1부터 20까지의 소수는 2, 3, 5, 7, 11, 13, 17, 19로 총 8개입니다. 
//제한시간은 1초입니다.

#include <iostream>
using namespace std;

int main(){
    int n ; 
    cin >> n;

    bool *isPrime = new bool[n+1];

    //초기화
    for (int i = 0; i<= n; i++){
        isPrime[i] = true;
    }

    int cnt = 0;
    for (int i =2; i<=n;i++){
        //해당 수가 소수라면,
        if (isPrime[i]){
            cnt +=1;
            //해당 수를 제외한 배수들은 모두 제외
            for (int j = i * 2; j<=n; j += i){
                isPrime[j] = false;
            }
        }
    }
    cout << cnt;

}