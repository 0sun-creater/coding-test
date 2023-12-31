/*특정 수 만들기(DFS : MS 인터뷰)
N개의 원소로 구성된 자연수 집합이 주어지면, 집합의 원소와 ‘+’, ‘-’ 연산을 사용하여 
특정 수인 M을 만드는 경우가 몇 가지 있는지 출력하는 프로그램을 작성하세요. 각 원소는 연산에 한 번만 사용합니다.
예를 들어 {2, 4, 6, 8}이 입력되고, M=12이면
2+4+6=12
4+8=12
6+8-2=12
2-4+6+8=12
로 총 4가지의 경우가 있습니다. 만들어지는 경우가 존재하지 않으면 -1를 출력한다.
*/
#include <iostream>
#include <vector>

using namespace std;

int cnt=0, n,m;
vector<int> num_set;

void dfs(int idx, int sum){
    if(idx == n){
        if(sum == m) cnt ++;
    }
    else{
        dfs(idx+1, sum + num_set[idx]);
        dfs(idx+1, sum);
        dfs(idx+1, sum - num_set[idx]);
    }
}
int main(){
    int tmp;
    cin >> n >> m;

    for(int i =0; i<n; i++){
        cin >> tmp;
        num_set.push_back(tmp);
    }

    
    dfs(0, 0);
    if (cnt ==0) cout << "-1";
    else cout << cnt;
}