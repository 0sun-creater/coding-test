/* 53. K진수 출력
10진수 N이 입력되면 K진수로 변환하여 출력하는 프로그램을 작성하세요. 스택 자료구조를 사
용하시기 바랍니다.
*/

#include <stack>
#include <iostream>

using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    stack<int> s;
    char str[20] ="0123456789ABCDEF";
    while(n>0){
        s.push(n%k);
        n = n/k;
    }
    while(!s.empty()){
        cout << str[s.top()];
        s.pop();
    }

}