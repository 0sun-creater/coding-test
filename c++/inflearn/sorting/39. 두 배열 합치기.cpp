//두 배열 합치기
//오름차순으로 정렬이 된 두 배열이 주어지면 두 배열을 오름차순으로 합쳐 출력하는 프로그램을 작성하세요.

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

    arry1.insert(arry1.end(), arry2.begin(), arry2.end());

    sort(arry1.begin(), arry1.end());

    for(const auto& j : arry1){
        cout << j << " ";
    }
}