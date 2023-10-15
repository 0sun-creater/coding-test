//자릿수의 합
//N개의 자연수가 입력되면 각 자연수의 자릿수의 합을 구하고, 그 합이 최대인 자연수를 출력 하는 프로그램을 작성하세요.
//각 자연수의 자릿수의 합을 구하는 함수를 int digit_sum(int x)를 꼭 작성해서 프로그래밍 하세요.

#include <iostream>
using namespace std;

int digit_sum(int x){
    int sum = 0, temp;
    while(x>0){
        temp = x % 10;
        sum += temp;
        x = x/10;
    }
    return sum;
}

int main(){
    int n, number, result, result_sum;
    cin >> n;
    int max = -2147000000;
    for(int i = 0; i<n; i++){
        cin >> number;
        result_sum = digit_sum(number);
        if (result_sum > max){
            max = result_sum;
            result = number;
        }
        else if (result_sum == max){
            if (number > result){
                result = number;
            }
        }
    }

    cout << result;

}