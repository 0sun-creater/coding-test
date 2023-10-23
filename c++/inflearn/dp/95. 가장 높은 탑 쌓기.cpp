/*
밑면이 정사각형인 직육면체 벽돌들을 사용하여 탑을 쌓고자 한다. 탑은 벽돌을 한 개씩 아래 에서 위로 쌓으면서 만들어 간다.
아래의 조건을 만족하면서 가장 높은 탑을 쌓을 수 있는 프로그램을 작성하시오.
(조건1) 벽돌은 회전시킬 수 없다. 즉, 옆면을 밑면으로 사용할 수 없다.
(조건2) 밑면의 넓이가 같은 벽돌은 없으며, 또한 무게가 같은 벽돌도 없다.
(조건3) 벽돌들의 높이는 같을 수도 있다.
(조건4) 탑을 쌓을 때 밑면이 좁은 벽돌 위에 밑면이 넓은 벽돌은 놓을 수 없다.
(조건5) 무게가 무거운 벽돌을 무게가 가벼운 벽돌 위에 놓을 수 없다.

입력 : 벽돌수 <=100
한개의 벽돌에 관한 정보: 밑면 넓이, 벽돌 높이, 무게 (양의 정수)

출력 : 가장 높이 쌓을 수 있는 탑의 높이 출력
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Top{
    int size;
    int hight;
    int weight;
    
    Top(int a, int b, int c){
        size = a;
        hight = b;
        weight = c;
    }

    bool operator<(const Top &b)const{
        return size < b.size;
    }
};

int main(){
    int n,tmp1,tmp2,tmp3;
    cin >> n;
    vector<Top> list;
    
    for(int i =0; i<n; i++){
        cin >>tmp1 >> tmp2 >> tmp3;
        list.push_back(Top(tmp1,tmp2,tmp3));
    }
    sort(list.begin(), list.end());

    int dp[101];
    for(int i=0; i<n;i++){
        dp[i] = list[i].hight;
    }

    int result = 0;
    for(int i =1; i <n;i++){
        int maxi= 0;
        for(int j=0; j<i; j++){
            if(list[i].weight > list[j].weight){
               maxi = dp[i] + dp[j];
            }
        }
        dp[i] = maxi;
        if(dp[i]>result) result = dp[i];
    }

    cout << result;


}

