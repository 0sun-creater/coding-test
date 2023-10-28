#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int K;
bool isgo(int n ,vector<int> &stones) 
{//n은 인원수가 가능한지?
    int count = 0;
    for(int i = 0; i < stones.size(); i++){
        if(stones[i] - n <= 0) //못건너게 되는 돌
            count++;
        else 
            count = 0;
        if(count >= K) //못건너게 되는 돌이 연속으로 k개 있으면
            return false; //불가넝
    }
    return true; //가넝
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    K = k;
    //돌멩이의 max 숫자가 건너갈수 있는 최대 인원 수
    int start = 0, end = *max_element(stones.begin(),stones.end()); 
    int mid; //건너갈 수 있는 인원 수 
    while(start <= end){
        mid = ( start + end ) / 2;
        if (isgo(mid,stones)){ //가능하니?
            start = mid + 1;//응
        }
        else{
            end = mid - 1; //인원수를 줄여서 다시 살펴보자
        }
    }
    return start;
}