#include <string>
#include <vector>
#include <iostream>

using namespace std;

int answer =0;
vector<int> number;
int _target;
void dfs(int idx, int sum){
	if(idx == number.size()) {
        if (sum == _target) answer ++;
    }
    else{
        dfs(idx+1, sum + number[idx]);
        dfs(idx+1, sum - number[idx]);
    }
    
}

int solution(vector<int> numbers, int target) {
    _target = target;
    number = numbers;
    dfs(1,0 + numbers[0]);
    dfs(1,0 - numbers[0]);
    return answer;
}