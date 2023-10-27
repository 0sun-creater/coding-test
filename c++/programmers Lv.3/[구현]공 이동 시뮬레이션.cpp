#include <string>
#include <vector>
//nxm 
//0 : j 감소, 1 : j 증가 열 m
//2 : i 감소, 3 : i 증가 행 n
//바깥으로 공이 이동하면 이동 멈춤
//도착지 x,y
//x,y 제외하고 시작점이 될 수 있음 / x,y에 도착하는 시작점의 개수는?
//10^9 > n,m 절대 완전탐색 불가능 dp는 메모리 초과
//벽에 부딪히는 경우 순서대로 처리해야돼 -> 일괄처리 불가능
//벽에 안부딪히면서 x,y에 도착할 수 있는 경우의 수는 무조건 하나임.. 
using namespace std;

//x,y를 시작점으로 찾아보자
//위치를 점이 아닌 면접 개념으로 보자 (벽에 부딪히게 될 때의 위치는 연속)
//한계값에 범위가 도달하면 멈춰두고 이동시키지 않습니다.
//한계에 도달하지 않은 값들은 계속해서 이동시켜주어 범위를 점차 늘려줍니다.
long long solution(int n, int m, int x, int y, vector<vector<int>> queries) {
    long long answer = -1;
	//r1,c1 정답이 될 수 있는 범위의 시작 부분
    //r2,c2 정답이 될 수 있는 범위의 끝 부분
    long long r1=x,c1=y,r2=x,c2=y;
    for(int i=queries.size() - 1; i >= 0; i--) {
        vector<int> q = queries[i];

        //방향 반전필요
        if(q[0] ==0){ //j 증가 오른쪽 확장
            c2 += q[1];
            if(c2 >= m) c2 = m-1;
            if(c1 != 0) c1 += q[1]; //최대위치까지 공이 퍼졌다고 생각
            if(c1 >= m) return 0; //절대 x,y에 도착할 수 없음
        }
        else if(q[0]==1) {//j 감소 왼쪽 확장
            c1 -= q[1];
            if(c1 < 0) c1 = 0;
            if(c2 != m-1) c2 -= q[1];
            if(c2 < 0) return 0;
        }
        else if(q[0]==2) { //i 증가 아래쪽 확장
            r2 += q[1];
            if(r2 >= n) r2 = n -1;
            if(r1 != 0) r1 += q[1];
            if(r1 >= n) return 0;
        }
        else{ // i감소 위쪽 확장
            r1 -= q[1];
            if(r1 < 0) r1 = 0;
            if(r2 != n-1) r2 -= q[1];
            if(r2 < 0) return 0;
        }
    }
    //r1~r2,c1~c2 범위 내의 개수가 정답
    return (r2-r1+1) * (c2-c1+1);
}