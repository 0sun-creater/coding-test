/*
최고 17kg의 무게를 저장할 수 있는 가방이 있다. 
그리고 각각 3kg, 4kg, 7kg, 8kg, 9kg의 무게를 가진 5종류의 보석이 있다.
이 보석들의 가치는 각각 4, 5, 10, 11, 13이다.
이 보석을 가방에 담는데 17kg를 넘지 않으면서 최대의 가치가 되도록 하려면 어떻게 담아야 할까요?
각 종류별 보석의 개수는 무한이 많다. 한 종류의 보석을 여러 번 가방에 담을 수 있 다는 뜻입니다.

//입력 : 종류 개수, 무게한계값
    각 보석의 무게와 가치
출력 : 담을 수 있는 보석의 최대가치
*/

#include <iostream>
#include <vector>
using namespace std;

int napsack[1001];
int main(){
    int n, w, tmp, tmp2;
    vector<pair<int,int> > bag;
    cin >> n >> w;
    for(int i=0; i<n; i++){
        cin >> tmp >> tmp2;
        bag.push_back(make_pair(tmp,tmp2));
    }

    for(int i=0; i<n; i++){
        int cur_w = bag[i].first;
        int cur_v = bag[i].second;
        for(int j=cur_w; j <=w; j++){
            if(napsack[j] < napsack[j-cur_w] + cur_v){
                napsack[j] = napsack[j-cur_w] + cur_v;
            } 
        }
    }

    cout << napsack[w];
}