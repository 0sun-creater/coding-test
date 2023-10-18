#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;
    queue<int> q;
    for(int i =0; i< bridge_length;i++){
        q.push(0);
    }
    
    int truck_idx = 0;
    int sum=0, next_truck =0;
    while(!q.empty()){
		time++;
        sum -= q.front();
        q.pop();
        
        
        if(truck_idx < truck_weights.size()){
            next_truck = truck_weights[truck_idx];
            if(sum + next_truck <= weight){
                sum += next_truck;
                q.push(next_truck);
                truck_idx ++;
            }
            else{
                q.push(0);
            }
        }
        
    }
    
    
    return time;
}