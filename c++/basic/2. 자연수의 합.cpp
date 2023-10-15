//자연수의 합
//a,b가 주어지면 a부터 b까지의 합을 수식과 함께 출력

#include <iostream>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;
    int sum =0;
    for (int i = a; i <b; i++){
        cout << i << " + ";
        sum += i;
    }
    cout << b << " = ";
    cout << sum+b;
    return 0;
}