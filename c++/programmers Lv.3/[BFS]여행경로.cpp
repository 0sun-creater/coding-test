#include <string>
#include <vector>
#include <queue>

using namespace std;

bool can(string w1, string w2){
    int cnt =0;
    for(int i =0; i<w1.length(); i++){
        if(w1[i] != w2[i]) cnt++;
    }
    if (cnt ==1 ) return true;
    return false;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;

    queue<pair<string,int>> q;
    q.push(make_pair(begin,0));
    
    int flag =0;
    for(auto &word : words){
        if(word == target) flag=1;
    }
    if(flag ==0) return 0;
    
    
    int cnt =0;
   	
	while(!q.empty()){
        pair<string,int> cur = q.front();
        q.pop();
        
        for(auto &word : words){         
            if(can(cur.first, word)){
                if(word == target) {
                    return cur.second + 1;
                }
                q.push(make_pair(word, cur.second + 1));
            }
        }
        
    }
    
    
    
    return answer;
}