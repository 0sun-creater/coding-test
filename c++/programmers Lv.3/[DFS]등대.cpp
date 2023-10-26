#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
트리라고 생각하고 맨끝 리프노드까지 타고 들어간다.
리프노드부터 부모와 자식을 확인하며 둘다 불이 안켜져 있다면 부모에 불을 킨다 
그러면 리프노드 바로 앞에 있는 얘들이 켜질 거임 (이게 불키는 최소로 만드는 것)
*/

int answer = 0;
bool light[100001] = {false, };

void dfs(int cur, int parent, vector<vector<int> > &graph) {
    //연결되어 있는 만큼
    for (int i=0; i<graph[cur].size(); i++) {
        if (graph[cur][i] != parent) {
            dfs(graph[cur][i], cur, graph);
            if (!light[graph[cur][i]] && !light[cur]) {// 부모 자식 둘다 불이 안켜져있다면
                
                light[cur] = true;
                answer++;
            }
      	}
    }
}

//트리라고 생각. 
//node 1을 root로 시작
int solution(int n, vector<vector<int> > lighthouse) {
    vector<vector<int> > graph(n+1);
    for(auto num : lighthouse) {
        graph[num[0]].push_back(num[1]);
        graph[num[1]].push_back(num[0]);
    }
    dfs(1, 1, graph);
    return answer;
}
/*
struct Info{
    int hous;
    int idx;
    Info(int a, int b){
        hous = a;
        idx = b;
    }
};


bool compare (vector<Info> &v1, vector<Info> &v2){
    return v1.size() > v2.size();
}



bool light[100001];
vector<vector<Info> > house(100001);

bool check_equal(int m){
    for(int i=1; i<m;i++){
        if(light[i] == false) return false;
    }
    return true;
}

int solve(int mode, int n){
    int cnt =0;
    for(int i=0; i< n; i++){
		if(check_equal(n+1)) break;        //전부 true가 되었으면 break
		if(mode ==1) {
            if(light[house[i][0].idx] == true) continue;
        }
        if(int(house[i].size()) > 1){
            light[house[i][0].idx] = true;
            cnt ++;
            for(auto ing : house[i]){
                light[ing.hous] = true;
            }
        }
        else{
            for(int k=1; k<=n;k++){
                if(light[k] == false) {
                    light[k] = true;
                    cnt ++;
                }
            }
        }
    }
    return cnt ++;
}
int solution(int _n, vector<vector<int>> lighthouse) {
    int answer = 0;
    
    for(auto h : lighthouse){
        house[h[0]].push_back(Info(h[1],h[0]));
        house[h[1]].push_back(Info(h[0],h[1]));
    }

    sort(house.begin(), house.end(), compare);
    
    int a1 = solve(0,_n);
    fill(&light[0], &light[100001], false);
    int a2 = solve(1,_n);
    answer = min(a1,a2);
    return answer;
}
*/