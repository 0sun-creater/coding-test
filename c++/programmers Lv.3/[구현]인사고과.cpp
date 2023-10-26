#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int solution(vector<vector<int>> scores) {
    int answer = 1;
    int score = scores[0][0] + scores[0][1];
    
    // 점수 내림차순 정렬
    auto comp = [](vector<int> v1, vector<int> v2) 
    {
        return (v1[0]+v1[1]) > (v2[0]+v2[1]);
    };
    
    sort(scores.begin()+1, scores.end(), comp);
    
    // 완호 위치 구하기
    for(int i = 1; i < scores.size(); ++i)
    {
        // 완호가 인센티브를 못 받는 경우
        if(scores[0][0] < scores[i][0] 
          && scores[0][1] < scores[i][1])
            return -1;
        
        int other_score = scores[i][0] + scores[i][1];
        if(score < other_score)
            ++answer;
        else break;
    }
    
    // 완호보다 앞 선 사람들 중 인센티브를 받지 못하는 사람 빼기
    int wanho = answer;
    for(int c = 2; c < wanho; ++c)
    {
        for(int p = 1; p < c; ++p)
        {        
            if(scores[c][0] < scores[p][0] 
               && scores[c][1] < scores[p][1])
            {
                --answer;
                break;
            }
        }
    }
    
    return answer;
}





/*

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

근무태도, 동료평가 점수
두 점수가 어떤 임의의 사원보다 모두 낮으면 인센x
두 점수의 합이 높은 순으로 석차 내어 차등 지급

두 점수의 합이 동일한 사원은 동석차
동석차의 수만큼 다음 석차는 건너 뜀

완호의 석차 return
인센 못받는 경우는 -1

bool compare(vector<int> &v1, vector<int> &v2){
    return (v1[0]+v1[1] > v2[0] + v2[1]); //점수 내림차순
}


int solution(vector<vector<int>> scores) {
    int answer = 0;
    int n = int(scores.size());
    int wanho = scores[0][0] + scores[0][1];
    
    //scores.erase(scores.begin());
    sort(scores.begin()+1, scores.end(), compare);

    //등수 세기
    int cnt = 1;
    for(int i=1; i < n; i++){
        if(scores[0][0] < scores[i][0] && scores[0][1] < scores[i][1]) return -1; 
        if(scores[i][0] + scores[i][1] > wanho) cnt ++;
        else break;
    }

    //인센 못받는 사람 빼기
    for(int i = 2; i < cnt; i++){
        for(int j = 1; j < i; j++){        
            if(scores[i][0] < scores[j][0] && scores[i][1] < scores[j][1]){
                cnt--;
                break;
            }
        }
    }
    
    return cnt;
}

*/