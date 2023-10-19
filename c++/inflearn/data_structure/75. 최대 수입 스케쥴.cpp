/*
최대 수입 스케쥴(priority_queue 응용문제)
현수는 유명한 강연자이다. N개이 기업에서 강연 요청을 해왔다. 
각 기업은 D일 안에 와서 강연을 해 주면 M만큼의 강연료를 주기로 했다.
각 기업이 요청한 D와 M를 바탕으로 가장 많을 돈을 벌 수 있도록 강연 스케쥴을 짜야 한다.
단 강연의 특성상 현수는 하루에 하나의 기업에서만 강연을 할 수 있다.
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct Data{
    int money;
    int when;
    Data(int m, int d) : money(m), when(d) {}

    bool operator < (const Data &b) const{
        return when > b.when;
    }
};

int main(){
    int n, d, m;
    cin >> n;
    
    vector<Data> T;
    priority_queue<int > q;
    
    //최대 일수 구하기
    int max = -2147000000;
    for(int i =0; i< n;i++){
        cin >> m >> d;
        T.push_back(Data(m,d));
        if(d > max){
            max = d;
        }
    }
    
    sort(T.begin(), T.end()); 
    int  res=0;
    for (int i = max; i>=1; i--){
        for(int j=0; j<n; j++){
            if(T[j].when < i) break;
            q.push(T[j].money);
        }
        if(!q.empty()){
            res += q.top();
            q.pop();
        }
    }
    cout << res;

}