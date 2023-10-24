#include <string>
#include <vector>
#include <iostream>

using namespace std;
//누적합
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int> > sum;
    sum = triangle;
    int size = int(triangle.size());
    for(int i=1; i< size ;i++){
        sum[i][0] += sum[i-1][0];
        sum[i][i] += sum[i-1][i-1];
    }
    
    for(int i=2; i< size; i++){
        for(int j=1; j < int(triangle[i].size())-1; j++){
            int maxi = max(sum[i-1][j-1], sum[i-1][j]);
            sum[i][j] += maxi;
        }
    }
    
    answer = -1;
    for(auto a : sum[size-1]){
        if(answer < a) answer = a;
    }
    return answer;
}