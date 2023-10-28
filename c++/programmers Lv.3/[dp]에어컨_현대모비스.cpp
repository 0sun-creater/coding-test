#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;
//t1~t2 유지
//희망온도 변경가능 (실내-희망이 다르면 1분 후 1도 상승/하강, 둘이 같으면 안변함)
//전원을 끄면 실외 온도 쪽으로 1분 후 1도 상승/하강, 둘이 같으면 안변함

//소비 전력 상승/하강할 때 a 소비, 같으면 b, 꺼져있으면 0
//소비전력 최소화하기

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
	int k = 1000 * 100;
    t1 += 10;
    t2 += 10;
    temperature += 10;
    int n = int(onboard.size());
    int DP[n][51];
    for (int i = 0; i <n; i++) {
        for (int j = 0; j < 51; j++) {
            DP[i][j] = k;
        }
   }
        
   DP[0][temperature] = 0;
        
   int flag = 1; //냉난방 판단
   if (temperature > t2) {
        flag = -1;
   }
        
   for (int i = 1; i < n; i++) {
        for (int j = 0; j < 51; j++) {
            int minV = k;
            //i분 j온도에서 손님이 있을 경우 j가 쾌적온도(t1 ~ t2) 범위안에 / 손님이 없다면 상관없다.
            if (( onboard[i] == 1 && t1 <= j && j <= t2 ) || onboard[i] == 0) {
                //에어컨을 키지 않는 경우 / 실외온도가 실내온도와 차이가 나서 -flag 방향으로 변하는 경우
                if (0 <= j+flag && j+flag <= 50) {
                    minV = min(minV, DP[i-1][j+flag]);
                } 
                //에어컨을 키지 않는 경우 / 온도가 변하지 않는 경우
                if (j == temperature) {
                    minV = min(minV, DP[i-1][j]);
                }
                //에어컨을 키는 경우 / 실내온도가 희망온도와 달라서 온도가 +flag방향으로 변하는 경우
                if (0 <= j-flag && j-flag <= 50) {
                        minV = min(minV, DP[i-1][j-flag] + a);
                }
                //에어컨을 키는 경우 / 온도가 유지되는 경우
                if (t1 <= j && j <= t2) {
                    minV = min(minV, DP[i-1][j] + b);
                }
                DP[i][j] = minV;
            }
        }
   }
        
    int i = n-1;
    int answer = DP[i][0];
    for (int j = 1; j < 51; j++) {
       answer = min(answer, DP[i][j]);
    }
    
    return answer;
}