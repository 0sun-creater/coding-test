/*
이번 정보올림피아드대회에서 좋은 성적을 내기 위하여 현수는 선생님이 주신 N개의 문제를 풀려고 합니다. 
각 문제는 그것을 풀었을 때 얻는 점수와 푸는데 걸리는 시간이 주어지게 됩니다.
제한시간 M안에 N개의 문제 중 최대점수를 얻을 수 있도록 해야 합니다.
(해당문제는 해당시간이 걸리면 푸는 걸로 간주한다, 한 유형당 한개만 풀 수 있습니다.)

입력 문제 개수 <=100, 제한시간 <=1000
문제를 풀었을 때 얻는 점수 / 푸는데 걸린 시간

출력 제한 시간안에 얻을 수 있는 최대 점수
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,m,tmp,tmp2;
    cin >> n >> m;
    vector<pair<int, int> > problem;
    for(int i=0; i<n; i++){
        cin >> tmp >> tmp2;
        problem.push_back(make_pair(tmp,tmp2));
    }

    vector<int> dp(m+1, 0);

    for(int i=0; i<n; i++){
        int score = problem[i].first;
        int time = problem[i].second;
        for(int j=time; j<=m;j++){
            dp[j] = max(dp[j-time]+score, dp[j]);
        }
    }    

    cout << dp[m];

}

