//분노 유발자
//오늘은 수능이 끝난 다음날로 교장선생님은 1, 2학년 재학생들에게 강당에 모여 어벤져스 영 화를 보여준다고 하여 학생들이 강당에 모였습니다.
//강당의 좌석은 영화관처럼 계단형이 아니라 평평한 바닥에 의자만 배치하고 학생들이 앉습니다. 
//그런데 만약 앞자리에 앉은 키가 큰 학생이 앉으면 그 학생보다 앉은키가 작은 뒷자리 학 생은 스크린이 보이지 않습니다. 
//한 줄에 앉은키 정보가 주어지면 '뒷사람 모두'의 시야를 가려 영화 시청이 불가능하게 하는 분노유발자가 그 줄에 몇 명이 있는지 구하는 프로그램을 작성 하세요.

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,tmp;
    cin >> n;
    vector<int> student;
    for(int i =0; i < n; i++){
        cin >> tmp;
        student.push_back(tmp);
    }


    int max = student[n-1];
    int cnt = 0;
    for(int i =n-2; i>=0; i--){
        if(student[i] > max){
            cnt +=1;
            max = student[i];
        }
    }
    
    cout << cnt;
    
}