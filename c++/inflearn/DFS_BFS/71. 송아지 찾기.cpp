/*
송아지 찾기(BFS : 상태트리탐색)
현수는 송아지를 잃어버렸다. 다행히 송아지에는 위치추적기가 달려 있다. 
현수의 위치와 송아 지의 위치가 직선상의 좌표 점으로 주어지면 
현수는 현재 위치에서 송아지의 위치까지 다음과 같은 방법으로 이동한다.
현수는 스카이 콩콩을 타고 가는데 한 번의 점프로 앞으로 1, 뒤로 1, 앞으로 5를 이동할 수 있다. 
최소 몇 번의 점프로 현수가 송아지의 위치까지 갈 수 있는지 구하는 프로그램을 작성 하세요.

*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main(){
    int start, end;
    cin >> start >> end;
    int visited[10001];

    int check[3] = {-1,1,5};
    queue<int> q;
    q.push(start);
    visited[start] =1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i =0; i<3;i++){
            int pos = cur +check[i];
            if(pos <= 0 || pos >10000) continue;
            if(pos == end){
                cout << visited[cur];
                return 0;
            }
            if(visited[pos]==0){
                visited[pos] = visited[cur] + 1;
                q.push(pos);
            }
        }        
    }
}