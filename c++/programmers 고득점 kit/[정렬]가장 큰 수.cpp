
/*
첫 자리수가 제일 큰 순서대로, 자릿수가 같으면 그 다음 자릿수가 제일 큰 순대로 정렬
95, 9, 6  --> 9956 : 첫 자릿수가 같으면 작은수부터(자릿수가 낮은순)
30, 3, 34 --> 34330 : 얜 아닌데? ㅜ 34,3,30 순 / 내림차순도 아님 우짬?
리스트가 0,0 인경우 0으로 나와야함 (string + 계산 주의)
*/
/*
numbers에 담긴 원소들을 특정한 기준에 의해 정렬

두 원소들 간에 서로 결합해 보고 사전 순서상 더 뒤에 오게 되는 숫자가 앞으로 가도록 정렬
두 원소간 결합을 하면 나오는 경우의 수 2가지의 자릿수는 동일할 것이므로, 사실상 사전 순서상 뒤에 오는 것이 숫자로 볼 때 더 큰 숫자를 의미하게 됩니다. (예 : 10과 2는 ‘102’와 ‘210’을 만들 수 있음)
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(const string &a, const string &b){
    if (a+b > b+a){
        return true; //순서 유지, 현재상태가 더 컸다면 유지
    }
    else{
        return false; //순서 바꾸기
    }
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> strVec;
    
	for (int i = 0; i < numbers.size(); i++) {
		strVec.push_back(to_string(numbers.at(i)));
	}
    
	sort(strVec.begin(),strVec.end(),compare);
    
	for (string str : strVec) {
		answer += str;
	}
    
	if (answer[0] == '0')
		return "0";
    
	return answer;
}