//뒤집은 소수
//N개의 자연수가 입력되면 각 자연수를 뒤집은 후 그 뒤집은 수가 소수이면 그 수를 출력하는 프로그램을 작성하세요.
//예를 들어 32를 뒤집으면 23이고, 23은 소수이다. 그러면 23을 출력 한다.
//단 910를 뒤집으면 19로 숫자화 해야 한다. 첫 자리부터의 연속된 0은 무시한다.
//뒤집는 함수인 int reverse(int x) 와 소수인지를 확인하는 함수 bool isPrime(int x)를 반드시 작성하여 프로그래밍 한다.

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isPrime(int x){
    for (int i =2; i<= sqrt(x); i++){
        if (x%i == 0){
            return false;
        }
    }
    //2~n-1 약수가 없다면 소수
    return true;
}

int reverse(int x){
    string re;
    int temp = 0;
    while(x>0){
        temp = x%10;
        re += to_string(temp);
        x = x/10;
    }
    return std::stoi(re);
}

int main(){
    int n, num;
    cin >> n;
    for (int i =0;i<n; i++){
        cin >> num;
        int re_num = reverse(num);
        if (isPrime(re_num)){
            cout << re_num << " ";
        }
    }
}