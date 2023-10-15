//나이 차이
//n명의 나이가 입력된다. n명의 사람 중 가장 나이차이가 많이 나는 경우는? 최대 나이 차이 출력

#include <iostream>
using namespace std;

int main(){
    int n, age =0;
    cin >> n;
    int max = -2147000000;
    int min = 2147000000;
    for (int i =0 ; i<n; i++){
        cin >> age;
        if (age > max){
            max = age;
        }
        if (age < min){
            min = age;
        }
    }
    cout << max-min;
}