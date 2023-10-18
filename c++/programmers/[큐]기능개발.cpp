#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int day, prev=0, cnt =0;

    for(int i =0; i<progresses.size(); i++){
        if ((100-progresses[i]) % speeds[i]==0 ){
            day = (100-progresses[i]) / speeds[i];
        }
        else{
            day = ( (100-progresses[i]) / speeds[i]  ) +1;
        }
        if (i==0){
            answer.push_back(1);
            prev = day;
        }
        else if(day > prev ){
            answer.push_back(1);
            prev = day;
            cnt++;
        }
        else{
            answer[cnt] ++;
        }
        
    }
    
    return answer;
}