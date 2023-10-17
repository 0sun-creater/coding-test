//교집합(투포인트 알고리즘)
//두 집합 A, B가 주어지면 두 집합의 교집합을 출력하는 프로그램을 작성하세요.
//제한시간 1초

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,m, tmp;
    cin >>n;
    vector<int> arry1;
    for(int i=0; i< n; i++){
        cin >> tmp;
        arry1.push_back(tmp);
    }
    cin >>m;
    vector<int> arry2;
    for(int i=0; i< m; i++){
        cin >> tmp;
        arry2.push_back(tmp);
    }
    vector<int> result;
    sort(arry1.begin(), arry1.end());
    sort(arry2.begin(), arry2.end());

    int p1=0, p2=0;
    while(1){
        if (p1 == n || p2 == m){
            break;
        }

        if(arry1[p1]==arry2[p2]){
            result.push_back(arry1[p1]);
            p1++;
            p2++;
        }
        else if (arry1[p1] > arry2 [p2]){
            p2 ++;
        }
        else{
            p1 ++;
        }

    }

    for (const auto& j : result){
        cout << j << " ";
    }


}