#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

bool right1(int answer, int i){
    int c[5] = {1,2,3,4,5};
    
    if(c[i%5] == answer) return true;
    return false;
}

bool right2(int answer, int i){
	int a[8] = {2,1,2,3,2,4,2,5};
    
    if(a[i%8] == answer) return true;
    return false;
}

bool right3(int answer, int i){
    int b[10] = {3,3,1,1,2,2,4,4,5,5};
    
    if(b[i%10] == answer) return true;
    return false;
}

//가장 많은 문제를 맞힌 사람이 누구인지 return
vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int cnt[4] = {0,0,0,0};
    for(int i =0; i< int(answers.size()); i++){

        if(right1(answers[i], i)) cnt[1]++;
            
        if(right2(answers[i], i)) cnt[2]++;
          
        if(right3(answers[i], i)) cnt[3]++;
        
    }
    
    int maxi = max(cnt[1], max(cnt[2], cnt[3]));

    for(int i=1; i<4; i++){
        if(maxi == cnt[i]) answer.push_back(i);
    }
    
    return answer;
}