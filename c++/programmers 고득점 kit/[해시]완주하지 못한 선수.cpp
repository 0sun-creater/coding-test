#include <string>
#include <vector>
#include <map>

using namespace std;
//한놈은 낙오
//완주못한 사람 출력
string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> m;
    
    for(int i =0; i< int(completion.size()); i++){
        m[completion[i]] += 1;
    }
    
    for(auto p : participant){
        m[p] -= 1;
        if(m[p] < 0) return p;
    }
    
    return answer;
}