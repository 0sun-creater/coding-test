//Special Sort(구글 인터뷰)
//N개의 정수가 입력되면 당신은 입력된 값을 정렬해야 한다.
//음의 정수는 앞쪽에 양의정수는 뒷쪽에 있어야 한다. 또한 양의정수와 음의정수의 순서에는 변함이 없어야 한다.
// 입력 : 1 2 3 -3 -2 5 6 -6
// 출력 : -3 -2 -6 1 2 3 5 6

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(int a, int b){
    if (a<0 && b<0) return a==b;
    else{
        return a<b;
    }

}

int main(){
    int n,tmp;
    cin >> n;
    vector<int> rank;
    for(int i =0; i<n; i++){
        cin >> tmp;
        rank.push_back(tmp);
    }

    sort(rank.begin(), rank.end(), compare);

    for(int i =0; i<n; i++){
        cout << rank[i] << " ";
    }

}