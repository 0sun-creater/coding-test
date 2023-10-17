//연속된 자연수의 합
//입력으로 양의 정수 N이 입력되면 2개 이상의 연속된 자연수의 합으로 정수 N을 표현하는 방법의 가짓수를 출력하는 프로그램을 작성하세요.

//풀이. n이 연속된 k개로 분리된다면, n에서 1+2+..+k 를 뺀값이 k로 나누어 떨어진다.

#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int k =2;
    int sum =0, cnt = 0;
    while(1){
        sum =0;
        for(int i =1; i<=k;i++){
            sum += i;
        }
        if((n-sum) % k ==0){
            cnt += 1;
            cout << 1 + (n-sum)/k;
            for(int i =2; i<=k; i++){
                cout << " + " << i + (n-sum)/k;
            }
            cout << " = 15" << endl; 
        }
        k++;
        if (n-sum <= 0) break;
    }

    cout << cnt;

}


/*
print 없애고 for 문으로 변경 -- 백준 2018번 문제
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int sum =1, cnt = 1;
    for(int k =2; n-sum >0; k++){
        sum += k;
        if((n-sum) % k ==0){
            cnt+=1;
        }
    }

    cout << cnt;
    
    return 0;

}


*/