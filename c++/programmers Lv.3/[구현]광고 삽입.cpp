#include <string>
#include <vector>

using namespace std;
//해당 동영상의 어떤 구간을 재생했는 지 알 수 있는 기록 구함
//해당 기록을 바탕으로 공익 광고가 삽입될 최적의 위치를 구할 수 있다.
//시작시간~끝시간
//누적 재생시간이 가장 큰 구간 구하기

int timeToint(string S){
    string SH = S.substr(0, 2); //01
	int Hour = stoi(SH) * 3600;
	string SM = S.substr(3, 2); //34
	int Minute = stoi(SM) * 60;
	string SS = S.substr(6, 2); //67
	int Second = stoi(SS);
 
	int Total = Hour + Minute + Second;
	return Total;	
}

string intTostring(int t)
{
    string s = "";
    int hour = t / 3600;
    int minute = (t % 3600) / 60;
    int second = t % 60;
 
    if (hour <= 9) s += '0';
    s += to_string(hour);
    s += ':';
    if (minute <= 9) s += '0';
    s += to_string(minute);
    s += ':';
    if (second <= 9) s += '0';
    s += to_string(second);
    return s;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    
    int play = timeToint(play_time);
    int adv = timeToint(adv_time); //공익광고의 재생시간 길이
    if(play == adv) return "00:00:00";
    
    vector<int> total(360000, 0);
    for(int i=0; i < int(logs.size());i++){
        int start = timeToint(logs[i].substr(0,8)); //누적 재생시간
        int end = timeToint(logs[i].substr(9,8));
        
        for (int j = start + 1; j <= end; j++) total[j]++;
    }
    
    //누적 재생시간이 가장 많은 곳이 여러 곳이면 가장 빠른 시작 시각 return
    long long cur_time =0;
    long long max_time =0;
    int time =1;
    //0초에 광고를 삽입했다고 가정했을 때, 재생 누적시간
    //특정 시간에 광고가 재생되는 시간은, 해당 시간에 재생되고 있는 구간의 갯수에 비례해서 증가
    for(int i=1; i<= adv;i++){
        cur_time += total[i];
        max_time += total[i];
    }
    //광고가 들어갈 수 있는 최종시간까지 매시간마다 광고를 모두 삽입
    //1초 ~ 20초동안 광고가 실질적으로 재생된 재생누적시간을 'K'
    //K 라는 시간에서 21초 그 순간에서의 재생 구간의 갯수 만큼을 더해준 후에, 1초에서의 재생 구간의 갯수만큼만 빼주면" 된다.  -> 2 ~ 21초 동안의 재생 누적 시간을 구할 수 있을 것
    for(int i=2; i<=(play-adv+1); i++){
        cur_time += (long long)(total[i + adv - 1] - total[i - 1]);
        if (cur_time > max_time){ //재생누적시간이 가장 큰 시간을 저장
            max_time = cur_time;
            time =i;
        }
    }
    answer = intTostring(time-1);
    return answer;
}