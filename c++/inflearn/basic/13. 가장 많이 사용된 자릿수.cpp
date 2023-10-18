//가장 많이 사용된 자릿수
//N자리의 자연수가 입력되면 입력된 자연수의 자릿수 중 가장 많이 사용된 숫자를 출력하는 프 로그램을 작성하세요.
//예를 들어 1230565625라는 자연수가 입력되면 5가 3번 상용되어 가장 많이 사용된 숫자입니 다. 답이 여러 개일 경우 그 중 가장 큰 수를 출력하세요.
#include <iostream>
#include <string>
using namespace std;

int main(){
    string number;
    cin >> number;
    int cnt[10] ={0,0,0,0,0,0,0,0,0,0};
    for (int i=0; i< number.length(); i++){
        cnt[(number[i]-48)] +=1;
    }
    //array 에서 max_element쓰는법
    //vector면 (v.begin(), v.end()) - v.begin() 하면됨
    //값을 가져오고 싶으면 *max_element()
    int size = sizeof(cnt) / sizeof(*cnt);    
    cout << max_element(cnt, cnt + size) - cnt;

}
