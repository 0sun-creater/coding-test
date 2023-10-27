#include <string>
#include <vector>

using namespace std;
//목표 : 금 a, 은 b 
//i번 도시는 i번 왕복 가능 
//금 g[i], 은 s[i], 운반가능 w[i], 편도시간 t[i]
//a,b를 전달할 수 있는 가장 빠른 시간 리턴

//제한사항이 dp는 안돼
//이분탐색이란다.. mid 는 시간
 
bool Search(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t, long long Mid)
{
    long long Total_Gold = 0;
    long long Total_Silver = 0;
    long long Total_Mineral = 0;
 
    for (int i = 0; i < g.size(); i++) //모든 도시 탐색
    {
        long long Time = t[i];
 
        long long Round_Time = Time * 2;	//왕복 시간
        long long Move_Cnt = Mid / Round_Time; //이동 가능횟수
        if (Mid % Round_Time >= Time) Move_Cnt++; //도시부터 출발이어서 %가 남으면 한번 더 갈 수 있어
        long long Max_Take = w[i] * Move_Cnt;  //최대로 가져갈 수 있는 광물 kg = 편도 kg * 왕복 횟수
 
        Total_Gold += min((long long)g[i], Max_Take); //옮길 수 있는 금의 양
        Total_Silver += min((long long)s[i], Max_Take); //옮길 수 있는 은의 양
        Total_Mineral += min((long long)g[i] + s[i], Max_Take); //옮길 수 있는 전체 광물 양
    }
 	//전부 가넝?
    if (Total_Gold >= a && Total_Silver >= b && Total_Mineral >= a + b) return true;
    return false;
}
 
long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t)
{
    long long answer = -1;
    long long Start = 0;
    long long End = 10e14 * 3; //졸라큰수(최악의 상황 가정)
    answer = End;
    while (Start <= End)
    {
        long long Mid = (Start + End) / 2;
        if (Search(a, b, g, s, w, t, Mid) == true) //mid시간 안에 가능하니?
        {
            answer = min(answer, Mid); //웅
            End = Mid - 1; //더 작은 시간안에도 가능한가?
        }
        else Start = Mid + 1; //아니 시간더줘.
    }
 
    return answer;
}
