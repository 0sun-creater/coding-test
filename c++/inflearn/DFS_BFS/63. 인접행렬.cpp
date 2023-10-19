// 가중치 방향 정보를 가진 그래프를 인접 행렬로 표현해보세요.

#include <iostream>
using namespace std;

int **mapp;
int main(){
    int n,m;
    cin >> n >> m;
    mapp = new int*[n+1];
    for(int i =0; i<=n; i++){
        mapp[i] = new int[n+1];
    }

    int tmp,tmp2,tmp3;
    for(int i =0 ;i<m; i++){
        cin >> tmp >> tmp2 >> tmp3;
        mapp[tmp][tmp2] = tmp3;
    }

    for(int i=1; i<=n; i++){
        for (int j =1; j<=n; j++){
            cout << mapp[i][j] << " ";
        }
        cout << endl;
    }



}