//숫자의 총 개수(small)
//자연수 N이 입력되면 1부터 N까지의 자연수를 종이에 적을 때 각 숫자는 몇 개 쓰였을까요? 
//예를 들어 1부터 15까지는 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5으로 총 21개가 쓰였음을 알 수 있습니다.
//자연수 N이 입력되면 1부터 N까지 각 숫자는 몇 개가 사용되었는지를 구하는 프로그램을 작성하세요.
//제한시간(1초)

#include <iostream>
using namespace std;

int main(){
    int number;
    cin >> number;
    int sum=0, c=1, digit=9, res = 0;
    while(sum+digit < number){ //자릿수 마지막에 포함되는지 확인 9, 99, 999 ...
        res += (c*digit); 
        sum += digit;
        c++; //다음자리숫자의 자릿수
        digit *=10; //다음자리 숫자의 갯수
    }
    res = res + ((number - sum) * c);

    cout << res;
}