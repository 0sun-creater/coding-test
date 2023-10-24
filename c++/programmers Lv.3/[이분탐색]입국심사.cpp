#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
처음에 모든 심사대는 비어있다. 동시에 한 명만 심사가능
가장 앞에 서있는 사람은 비어있는 심사대로 가서 심사 받음
더 빨리 끝나는 심사대가 있으면 '기다렸다가' 그곳으로 가서 심사를 받을 수도 있음

모든 사람이 심사를 받는데 걸리는 시간을 최소로 만들기

n : 입국심사를 기다리는 사람 수
times : 각 심사관이 한 명을 심사하는데 걸리는 시간이 담긴 배열
*/

//mid 시간안에 몇명의 사람이 심사를 받을 수 있니?
long long check(long long midi, vector<int> time){
    long long sum = 0;
    for(auto t : time){
        sum += midi / t;
    }
    return sum;
}

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long l, r, mid=-1; //r은 전체시간
	//mid가 답이라고 결정지어놓고 되는지 안되는지 확인하기
	l = *min_element(times.begin(), times.end());
    r = *max_element(times.begin(), times.end());
    r *= n;
    
    while(l <= r){
    	mid = (l+r)/2;

        if (check(mid, times) >= n){
            answer = mid;
            r = mid -1;
        }
        else{
            l = mid +1;
        }

    }
    
    return answer;
}