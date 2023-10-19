#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    bool visited[201] = {false};

    for(int i =0 ; i< n; i++){
        if(visited[i] == true) continue;
        answer ++;
        visited[i] = true;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            
            for(int k =0 ; k < n; k++){
                if(visited[k] == false && computers[cur][k]==1){
                    q.push(k);
                    visited[k] = true;
                }
            }

        }
    }
    
    
    return answer;
}