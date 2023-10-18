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
  
    answer = have[(k-eat_time) % have.size()].second;
    return answer;
}