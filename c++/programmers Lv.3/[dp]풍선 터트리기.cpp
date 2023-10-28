#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
/*
인접한 풍선 중 하나만 터트릴 수 있다..
풍선이 1개만 남을때까지 터트린다.

번호가 더 작은 풍선을 터트리는건 최대 1번만 가능
어떤 풍선이 최후까지 남을까?
무슨 수를 쓰더라도 마지막까지 남기는 것이 불가능할수도있음

i번째 수를 기준으로 좌/우에 모두 i번째 수보다 작은게 있으면 걘 남기는거 불가능
좌측에만 작은수 ok, 우측에만 작은수 ok, 양쪽 모두 없음
*/
int answer;

int solution(vector<int> a) {
	int answer = 0;
    int size = int(a.size());
    if(size == 1) return 1;
    if(size == 2) return 2;
	
    answer = 3; //처음,끝,min 은 무조건 가능하다.
    int min_idx = min_element(a.begin(), a.end()) - a.begin();
    if(min_idx == 0) answer =2; //젤 작은 애가 첫번째 원소일경우
    if(min_idx == size-1) answer =2; //젤 작은 애가 마지막 원소일경우

    int left_min = a[0], right_min = a[size-1];
    for(int i=1; i<min_idx;i++){
        left_min = min(left_min, a[i]);
        if(left_min == a[i]) answer++;
    }
    
    for(int i=size-2; i>min_idx;i--){
        right_min = min(right_min, a[i]);
        if(right_min == a[i]) answer++;
    }
    
    return answer;
}