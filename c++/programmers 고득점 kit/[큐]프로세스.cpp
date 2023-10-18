#include <vector>
#include <deque>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    deque<pair<int,int>> q;
    for(int i =0; i< priorities.size(); i++){
        q.push_back({priorities[i],i});
    }
    
    int cnt = 0;
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop_front();
        cnt++;
        for(int i = 0; i < q.size(); i++){
            if(q[i].first > p.first){
                q.push_back(p);
                p = { -1,-1};
                cnt--;
                break;
            }
        }
        if(p.second == location) return cnt;
    }
}