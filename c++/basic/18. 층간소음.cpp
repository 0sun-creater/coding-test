//층간소음
//T편한 세상 아파트는 층간소음 발생 시 윗집의 발뺌을 방지하기 위해 애초 아파트를 지을 때 바닥에 진동센서를 설치했습니다.
//이 센서는 각 세대의 층간 진동소음 측정치를 초단위로 아 파트 관리실에 실시간으로 전송합니다.
//그리고 한 세대의 측정치가 M값을 넘으면 세대호수와 작은 경보음이 관리실 모니터에서 울립니다.
//한 세대의 N초 동안의 실시간 측정치가 주어지면 최대 연속으로 경보음이 울린 시간을 구하세요.
//경보음이 없으면 -1를 출력합니다.

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m,tmp;
    cin >> n >> m;
    int cnt = 0;
    int max = -2147000000;
    for(int i =0; i<n; i++){
        cin >> tmp;
        if(tmp > m){
            cnt +=1;
        }
        else{
            cnt = 0;
        }
        if (cnt > max){
            max = cnt;
        }
    }
    if (max == 0) cout << "-1";
    else {
        cout << max;
    }

}