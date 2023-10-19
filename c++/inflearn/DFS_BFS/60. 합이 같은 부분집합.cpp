/*
합이 같은 부분집합(DFS : 아마존 인터뷰)
N개의 원소로 구성된 자연수 집합이 주어지면, 이 집합을 두 개의 부분집합으로 나누었을 때 
두 부분집합의 원소의 합이 서로 같은 경우가 존재하면 “YES"를 출력하고, 
그렇지 않으면 ”NO"를 출력하는 프로그램을 작성하세요.

예를 들어 {1, 3, 5, 6, 7, 10}이 입력되면 {1, 3, 5, 7} = {6, 10} 으로 
두 부분집합의 합이 16으로 같은 경우가 존재하는 것을 알 수 있다.
*/


#include <iostream>
#include <vector>

using namespace std;
vector<int> vec; //자연수 집합

int n, total=0;
bool flag = false;

void dfs(int depth, int sum){
    if (sum > (total/2)) return;
    if (flag == true) return;
    if(depth == n+1){ //종료 지점
        //<부분집합 합>과 나머지의 합이 같으면 YES
        if(sum==(total-sum)){
            flag = true;
        }
    }else{
        dfs(depth+1, sum + vec[depth]); //이번 원소를 사용한다.
        dfs(depth+1, sum); //이번 원소를 사용하지 않는다.
    }

}
int mina(){
    int tmp;
    cin >> n;
    vec.push_back(0);
    for(int i =1;i <= n; i++){
        cin >> tmp;
        vec.push_back(tmp);
        total += tmp;
    }

    dfs(1, 0);

    if(flag) cout << "YES";
    else cout << "NO";

    return 0;

}