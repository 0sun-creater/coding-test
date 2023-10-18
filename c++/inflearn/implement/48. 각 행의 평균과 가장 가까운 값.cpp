/*
각 행의 평균과 가장 가까운 값
<그림 1>과 같이 9×9 격자판에 쓰여진 81개의 자연수가 주어질 때, 각 행의 평균을 구하고, 
그 평균과 가장 가까운 값을 출력하는 프로그램을 작성하세요. 
평균은 소수점 첫 째 자리에서 반 올림합니다. 평균과 가까운 값이 두 개이면 그 중 큰 값을 출력하세요.
*/
#include <iostream>
#include <vector>

using namespace std;



int main(){
    int tmp, result;
    long long dis=2147000000, sum;
    long long avg, calu;
    
    for(int i =0; i<9; i++){
        sum = 0, avg = 0;
        vector<int> x;
        for(int j =0; j<9; j++){
            cin >> tmp;
            sum += tmp;
            
            x.push_back(tmp);
        }

        avg = (sum / 9.0) + 0.5;
        for(int k =0; k<9; k++){
            calu = abs(x[k] - avg);

            if (dis > calu){
                dis = calu;
                result = x[k];
            }
        }
        cout << avg <<" " << result;
    }

}