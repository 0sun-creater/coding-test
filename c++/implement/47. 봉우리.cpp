/* 봉우리
지도 정보가 N*N 격자판에 주어집니다. 각 격자에는 그 지역의 높이가 쓰여있습니다.
각 격자 판의 숫자 중 자신의 상하좌우 숫자보다 큰 숫자는 봉우리 지역입니다.
봉우리 지역이 몇 개 있는 지 알아내는 프로그램을 작성하세요.
격자의 가장자리는 0으로 초기화 되었다고 가정한다.
만약 N=5 이고, 격자판의 숫자가 다음과 같다면 봉우리의 개수는 10개입니다.
*/
#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > mapp;
int n;
bool check (int r, int c){
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,-1,1};

    int nr, nc;
    for(int i = 0; i < 4; i++){
        nr = r+dx[i];
        nc = c+dy[i];
        if (nr < 0 || nr == n || nc <0 || nc ==n) continue;
        if(mapp[r][c] < mapp[nr][nc]) return false;
    }
    return true;
}

int main(){
    int tmp,result=0;
    cin >> n;
    for(int i =0; i< n; i++){
        vector<int> temp;
        for(int j =0; j <n; j++){
            cin >> tmp;
            temp.push_back(tmp);
        }
        mapp.push_back(temp);
    }


    for(int i =0; i< n; i++){
        for(int j =0; j<n; j++){
            if (check(i,j)){
                result ++;
            }
        }
    }

    cout << result;
}
