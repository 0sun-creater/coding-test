//멀티태스킹(카카오 먹방 문제 변형)
//현수의 컴퓨터는 멀티태스킹이 가능하다. 처리해야 할 작업이 N개 들어오면 현수의 컴퓨터는
//작업을 1부터 N까지의 번호를 부여하고 처리를 다음과 같이 한다.
//1) 컴퓨터는 1번 작업부터 순서대로 1초씩 작업을 한다. 즉 각 작업을 1초만 작업하고 다음 작업을 하는 식이다.
//2) 마지막 번호의 작업을 1초 했으면 다시 1번 작업으로 가서 다시 1초씩 후속 처리를 한다. 
//3) 처리가 끝난 작업은 작업 스케쥴에서 사라지고 새로운 작업은 들어오지 않는다.
//그런데 현수의 컴퓨터가 일을 시작한 지 K초 후에 정전이 되어 컴퓨터가 일시적으로 멈추었다.
//전기가 들어오고 나서 현수의 컴퓨터가 몇 번 작업부터 다시 시작해야 하는지 알아내는 프로그램을 작성하세요.
// 5초에 정전 [1,2,3]
// 0~1초 [0,2,3]
// 1~2초 [0,1,3]
// 2~3초 [0,1,2]
// 3~4초 [0,0,2]
// 4~5초 [0,0,1]  --> 3번 작업부터하면됨답

#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

int solution(vector<int> food_times, long long k) {
    int answer = 0;
    int n = food_times.size();
    
    map<int, int> food_freq; // key : 음식 먹는데 필요한 시간  value : 등장 횟수

    set<int> food; // 음식 먹는데 필요한 시간 오름차순 정렬 (중복 없음) 

    for (int i = 0; i < n; ++i){
        food_freq[food_times[i]] += 1;
        food.insert(food_times[i]);
    }
        
	long long eat_time = 0, cur_n = n, prev =0;
    long long temp_time = 0;
    long long next =0;
    for (auto & cur : food){
        temp_time = (cur - prev) * cur_n;
        if (eat_time + temp_time > k){
            next = cur;
            break;
        }
        eat_time += temp_time;
        cur_n -= food_freq[cur];
        prev = cur;
    }
    
    if (cur_n == 0) return -1;
    
    vector<pair<int,int>> have;
    
    for (int i =0 ; i< n; i++){
        if(food_times[i] >= next){
            have.push_back({food_times[i], i+1});
        }
    }
    
    answer = have[(k-eat_time)%have.size()].second;
    return answer;
}