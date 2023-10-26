#include <string>
#include <vector>

using namespace std;
/*
target 에서 0이 될때까지 던짐
최선의 던질 다트 수, 싱글 또는 불을 맞춘 합
*/


int dp[100001][2];

void set_best_case(int target) {
    if (dp[target - 60][0] == dp[target - 50][0]) {
        dp[target][0] = dp[target - 50][0] + 1;
        dp[target][1] = max(dp[target - 60][1], dp[target - 50][1] + 1);
    }
    else if (dp[target - 60][0] < dp[target - 50][0]) {
        dp[target][0] = dp[target - 60][0] + 1;
        dp[target][1] = dp[target - 60][1];
    }
    else {
        dp[target][0] = dp[target - 50][0] + 1;
        dp[target][1] = dp[target - 50][1] + 1;
    }
}

vector<int> solution(int target) {
    vector<int> answer(2, 0);

    for (int i = 1; i <= target; i++) {
        // 1. 한 번 만에 끝내기 가능한 경우
        // 1-1. 싱글 or 불 1번으로 끝내는 경우
        if (i == 50 || i <= 20) {
            dp[i][0] = 1;
            dp[i][1] = 1;
        }
        // 1-2. 60 이하의 3의 배수인 경우는 트리플 한 번이면 게임 끝
        else if (i <= 60 && i % 3 == 0) {
            dp[i][0] = 1;
            dp[i][1] = 0;
        }
        // 1-3. 40 이하의 2의 배수인 경우에는 더블 한 번이면 게임 끝
        else if (i <= 40 && i % 2 == 0) {
            dp[i][0] = 1;
            dp[i][1] = 0;
        }
        // 2. 50보다 크고 70 이하라면 항상 2번(불 + 싱글)이 최선의 경우임
        else if (i > 50 && i <= 70) {
            dp[i][0] = 2;
            dp[i][1] = 2;
        }
        // 3. 그렇지도 않은데 70보다 작은 수들이면 2가지로 나뉨.
        else if (i < 70) {
            // 3-1. 40 보다 작은 수들이면 싱글 2번이 최선의 경우
            if (i < 40) {
                dp[i][0] = 2;
                dp[i][1] = 2;
            }
            // 3-2. 아니라면 더블 1번 싱글 1번이 최선의 경우
            else {
                dp[i][0] = 2;
                dp[i][1] = 1;
            }
        }
        else {
            set_best_case(i); //101이상은 이후에 60아니면 50만 맞춘다고 생각하면 된다
        }
    }

    answer[0] = dp[target][0];
    answer[1] = dp[target][1];

    return answer;
}

    //초기화 1 한 번 만에 target 점수를 맞추는 경우. {1,1} - 싱글
	//초기화 2 target이 1 이상 20 이하이거나, 50인 경우 {1,1} - 싱글, 불
    //초기화 3 target이 60 이하이면서 3의 배수인 경우 {1,0} - 트리플
    //초기화 4 target이 40 이하이면서 2의 배수인 경우 {1,0} - 더블
    //초기화 5 target이 50보다 크고 70 이하인 경우 {2,2} - 불+싱글
    //초기화 6 target이 70 보다 작은 경우
    //			ㄴ40 보다 작다면? {2,2} -싱글 두번
	//			ㄴ나머지 {2,1} -트리플+싱글 / 더블 + 싱글
 
 	/*
    타겟 101 가정
    dp[41]에서 20 트리플(60점)을 맞춘 경우와, dp[51]에서 불(50점)을 맞춘 경우이다.
	즉, 둘 중에서 던진 횟수가 더 작은 경우를 택하거나, 
    둘 다 같다면 (싱글 + 불)을 맞춘 횟수가 더 많은 경우를 선택한다

 	
	dp[i] = dp[i - 50]인 상태에서 불을 던지는 경우와 dp[i - 60]인 상태에서 20 트리플을 맞추는 경우 중 
    최선의 경우 선택
    */
