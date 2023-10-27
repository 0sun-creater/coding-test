#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

/*
칫솔의 판매 이익 10%를 추천인 (부모노드) 나머지는 자신이 가짐 (루트노드까지 타고 가야함)
단, 10%를 계산할 때에는 원 단위에서 절사. 1원 미만인 경우 분배 안함

enroll : 판매원의 이름 <=10,000
referral : 각 판매원의 부모노드  "-"면 추천인 없음 (center) .. 부모는 항상 자식보다 idx가 작음
seller : 집계 데이터의 판매원 이름 .. 중복가능
amount : 집계 데이터

각 판매원이 득한 이익금을 나열한 배열 return (enroll 순서)
*/
vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    int size = int(enroll.size());
    map<string, int> number;
    map<string, string> parent;
    for(int i =0; i < size; i++){
        number[enroll[i]] = 0;
        parent[enroll[i]] = referral[i];
    }
    
    for(int i=0; i< int(seller.size());i++){
        string s = seller[i];
        int coin = amount[i] * 100;
        while(s != "-"){
            if((coin * 0.1) < 1){
                number[s] += coin;
                break;
            }
            if(parent[s] == "-"){
                number[s] += ceil(coin * 0.9);
                break;
            }
            number[s] += ceil(coin * 0.9);
            s = parent[s];
            coin = floor(coin * 0.1);
        }
    }
    for(int i=0; i< size; i++){
        answer.push_back(number[enroll[i]]);
    }
    
    return answer;
}