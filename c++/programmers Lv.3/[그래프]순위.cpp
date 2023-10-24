#include <string>
#include <vector>
#include <algorithm>

using namespace std;
/*
정확하게 순위를 매길 수 있는 선수의 수를 리턴

플로드 와샬은 맞아
이기고 지는걸 명확히 해줘야해 순위를 매겨야하니까.
*/
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    int graph[101][101];
    fill(&graph[0][0], &graph[100][101],0);
    for(auto r : results){
        graph[r[0]][r[1]] =1; //이김
        graph[r[1]][r[0]] =-1; //짐
    }
    
    for(int k=1; k<=n; k++){
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(graph[i][k] ==1 && graph[k][j]==1) {//i가 k를 이기고 k가 j를 이기면
                	graph[i][j] =1; //i는 j를 이긴다.
                    graph[j][i] =-1; //j는 i한테 진다.
                }
                if(graph[i][k] ==-1 && graph[k][j] ==-1){ //i가 k한테 지고 k가 j한테 지면
                    graph[i][j] = -1; //i는 j한테 진다.
                    graph[j][i] =1; //j는 i한테 이긴다.
                }
            }
        }
    }
    
    int cnt =0;
    for(int i=1; i<=n; i++){
        cnt =0;
        for(int j=1; j<=n; j++){
            if(graph[i][j] != 0) cnt++;
        }
        if(cnt == n-1) answer ++;
    }
    
    return answer;
}