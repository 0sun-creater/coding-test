/*
정글 n*n
토끼 m마리
격자에는 토끼가 1마리 있거나 없음
심바의 크기 초기값 2 / 격자 칸에서는 9로 표기
1초에 인접한 상하좌우 격자칸으로 이동가능
자신보다 크기가 작은 토끼만 잡아먹을 수 있음
크기가 같은 토끼는 먹을 수 없고 칸은 지날 수 있다.

1) 더이상 먹을 수 있는 토끼가 정글에 없으면 복수하러갈 수 있다.
2) 거리가 가장 가까운 토끼를 먹으러 간다. (거리는 지나야하는 칸의 개수 최소값)
3) 가장 가까운 토끼가 여럿이면 가장 위쪽, 그게 여럿이면 가장 왼쪽 잡아먹음

토끼를 먹는 데 걸리는 시간은 없다. 이동할 때만 1초
토끼를 먹으면 빈칸이 된다.

자신의 몸 크기와 같은 마리수 만큼 잡아먹으면 몸의 크기가 1 증가

출력 : 심바가 몇 초동안 토끼를 잡아먹고 삼촌에게 복수를 하러 갈 수 있는지 구하기
*/

#include <vector>
#include <queue>
#include <iostream>
#include <map>;

using namespace std;

struct Pos{
    int x;
    int y;
    Pos(int a, int b){
        x = a;
        y = b;
    }
};
int main(){
    vector<Pos> rabit[8];
    int mapp[26][26];
    int n, tmp;
    cin >> n;
    int simba_size = 2;

    Pos cur = Pos(0,0);

    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> tmp;
            mapp[i][j] = tmp;
            rabit[tmp].push_back(Pos(i,j));
            if(tmp == 9) {
                cur.x = i;
                cur.y = j;
            }
        }
    }



}
