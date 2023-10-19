//자연수 N이 주어지면 1부터 N까지의 원소를 갖는 집합의 부분집합을 모두 출력하는 프로그램

#include <iostream>
using namespace std;

int n;
int tmp[101];
void dfs(int v){
    int i;
    if (v == n+1){
        for(i=1; i<=n; i++){
            if(tmp[i] == 1){
                cout << i << " ";
            }
        }
        cout << endl;
    }
    else{
        tmp[v] =1;
        dfs(v+1); //원소 사용
        tmp[v] =0;
        dfs(v+1); //원소 미사용
    }


}

int main(){
    cin >> n;

    dfs(1);
}
