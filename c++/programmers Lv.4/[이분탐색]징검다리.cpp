#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
출발지 + dist = 도착지도 rocks 끝에 붙이고 생각
중간에 있는 바위를 제거하려고함

바위 n개를 제거한 뒤 각 지점 사이의 거리의 최소값 중 가장 큰 값 리턴
*/
int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    sort(rocks.begin(), rocks.end());
    //rocks.insert(rocks.begin(), 0);
    rocks.push_back(distance);
    int l=0,r=distance,cnt;
    
    while(l<=r){
        int mid = (l+r) / 2;
        cnt = 0; // 돌을 뺀 횟수
        int compare = 0;
        for(auto r : rocks){ //mid보다 사이거리가 작으면 빼버림 (mid가 최소값이 되도록)
            if(r - compare >= mid) compare = r;
            else cnt++;
        }
        if(cnt > n){  //돌을 뺀 횟수가 n보다 크다면
            r = mid - 1; //오른쪽은 버린다.
        }
        else{ //돌을 뺀 횟수가 n보다 작다면
            answer = max(answer, mid); //최소값 중 최대값을 답으로 한다.
            l = mid + 1; 
        }
    }
    return answer;
}