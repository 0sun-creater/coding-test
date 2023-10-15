// 온도의 최대값
//매일 아침 9시에 학교에서 측정한 온도가 어떤 정수의 수열로 주어졌을 때, 
//연속적인 며칠 동안의 온도의 합이 가장 큰 값을 알아보고자 한다.
//매일 측정한 온도가 정수의 수열로 주어졌을 때, 연속적인 며칠 동안의 온도의 합이 가장 큰 값을 계산하는 프로그램을 작성하시오.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k,tmp;
    cin >> n >> k;

    vector<int> temp;
    for(int i = 0; i < n; i++){
        cin >> tmp;
        temp.push_back(tmp);
    }

    int sum =0;
    int max =-2147000000;
    for(int i =0; i < n-k; i++){
        sum =0;
        for(int j=0; j < k; j++){
            sum += temp[i+j];
        }
        if(sum > max){
            max = sum;
        }
    }

    cout << max;
    

}