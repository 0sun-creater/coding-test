//3등의 성적은?
//N명의 수학성적이 주어지면 그 중 3등을 한 수학성적을 출력하는 프로그램을 작성하세요
//만약 학생의 점수가 100점이 3명, 99점이 2명, 98점이 5명, 97점이 3명 이런식으로 점수가 분포되면
//1등은 3명이며, 2등은 2명이며 3등은 5명이 되어 98점이 3등을 한 점수가 됩니다.

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n,tmp;
    cin >> n;
    vector<int> rank;
    for(int i =0; i<n; i++){
        cin >> tmp;
        rank.push_back(tmp);
    }

    sort(rank.begin(), rank.end());

    int cnt =1, i=0;
    int prev = rank[n-1];
    for(i = n-2; i>=0; i--){
        if (prev == rank[i]){
            continue;
        }
        else{
            cnt +=1;
            prev = rank[i];
            if(cnt ==3) break;
        }

    }
    cout << rank[i];

}