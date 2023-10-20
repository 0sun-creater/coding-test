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

#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int map[21][21], ch[21][21];
int dx[4]={-1, 0, 1, 0};
int dy[4]={0, 1, 0, -1};
struct State{
	int x, y, dis;
	State(int a, int b, int c){
		x=a;
		y=b;
		dis=c;
	}
//	bool operator<(const State &bb)const{
//		if(dis==bb.dis){
//			if(x==bb.x) return y>bb.y;
//			else return x>bb.x;
//		}
//		else return dis>bb.dis;
//	}
	bool operator<(const State &b)const{
		if(dis!=b.dis) return dis>b.dis;
		if(x!=b.x) return x>b.x;
		else return y>b.y;
	}
};

struct Lion{
	int x, y, s, ate;
	void sizeUp(){
		ate=0;
		s++;
	}
};
	
int main(){
	int n, i, j, res=0;
	priority_queue<State> Q;
	Lion simba;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j]==9){
				simba.x=i;
				simba.y=j;
				map[i][j]=0;
			}
		}
	}
	Q.push(State(simba.x, simba.y, 0));
	simba.s=2;
	simba.ate=0;
	while(!Q.empty()){
		State tmp=Q.top();
		Q.pop();
		int x=tmp.x;
		int y=tmp.y;
		int z=tmp.dis;

        //잡아먹을 수 있니?
		if(map[x][y]!=0 && map[x][y]<simba.s){	//토끼가 있고, 크기가 작더라
			simba.x=x;
			simba.y=y;
			simba.ate++; //잡아먹음
			if(simba.ate>=simba.s) simba.sizeUp(); 
			map[x][y]=0; //토끼위치 0
			for(i=1; i<=n; i++){    //check 초기화
				for(j=1; j<=n; j++){
					ch[i][j]=0;
				}
			}
			while(!Q.empty()) Q.pop(); //다시 출발해야되니 초기화
			res=tmp.dis; //갱신없이 최초심바 위치부터 토끼먹은 거리
        }

        //이동가능한 곳은 전부 push
		for(i=0; i<4; i++){
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1 || xx>n || yy<1 || yy>n || map[xx][yy]>simba.s || ch[xx][yy]>0) continue;
			Q.push(State(xx, yy, z+1));
			ch[xx][yy]=1;		
		}
	}
	printf("%d\n", res);
	return 0;
}
/*
#include <vector>
#include <queue>
#include <iostream>
#include <cmath>

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

    //위, 왼 순으로 rabit 저장 되어있음 sorting 필요 x
    for(int i =0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> tmp;
            mapp[i][j] = tmp;
            if(tmp == 9) {
                cur.x = i;
                cur.y = j;
            }
            else{
                rabit[tmp].push_back(Pos(i,j));
            }
        }
    }


    포문이 1~8 순서대로 돌면 안돼
    사이즈는 커지고 옆에 먹을 수 있는 토끼가 있을 수도 있어
    그러니 우선순위 큐를 이용해야함!
    int cnt =0;
    int time =0; 
    for(int i =1; i <8; i++){
        if (i >= simba_size) continue;
        while(int(rabit[i].size())!=0){
            //거리계산 , 지날 수는 있으니 abs(x1-x2) + abs(y1-y2)
            //제일 가까운 곳, idx가 빠른 순 토끼 먹으러감
            Pos min_pos(0,0);
            int dist = 2147000000;
            int erase =0;
            for(int j=0; j<int(rabit[i].size()); j++){
                int r_dist = abs(cur.x-rabit[i][j].x) + abs(cur.y-rabit[i][j].y);
                if(dist > r_dist) {
                    dist = r_dist; 
                    min_pos.x = rabit[i][j].x;
                    min_pos.y = rabit[i][j].y;
                    erase =j;
                }
            }
            //먹은 토끼 자리 mapp에서 0으로 만들기
            //심바 위치 갱신
            cur.x = min_pos.x;
            cur.y = min_pos.y;
            mapp[cur.x][cur.y] = 0;
            rabit[i].erase(rabit[i].begin() + erase); 
            time += dist;
            cnt ++;
            if (cnt == simba_size){
                simba_size++;
                cnt = 0;
            }
        }
    }

    cout << time;

}
*/
