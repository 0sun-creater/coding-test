/*Ugly Numbers
어떤 수를 소인수분해 했을 때 그 소인수가 2 또는 3 또는 5로만 이루어진 수를 Ugly Number라고 부릅니다.
Ugly Number를 차례대로 적어보면
1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, .......입니다.
숫자 1은 Ugly Number의 첫 번째 수로 합 니다.
자연수 N이 주어지면 Ugly Number를 차례로 적을 때 N번째 Ugly Number를 구하는 프로그램을 작성하세요.
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> ugly;
    int p2 =1, p3=1, p5=1;
    ugly.push_back(0);
    ugly.push_back(1);
    int min =2147000000;
    for(int i=2; i<=n; i++){
        if(ugly[p2]*2 < ugly[p3]*3) {
            min = ugly[p2]*2;
        }
        else {
            min = ugly[p3]*3;
        }
        if(ugly[p5]*5 < min) {
            min = ugly[p5]*5;
        }

        if(ugly[p2]*2 == min) p2++;
        if(ugly[p3]*3 == min) p3++;
        if(ugly[p5]*5 == min) p5++;

        ugly.push_back(min);
    }

    cout << ugly[n];
}