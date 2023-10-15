//나이계산
//주민등록증의 번호가 주어지면 주민등록증 주인의 나이와 성별을 판단하여 출력하는 프로그램 을 작성하세요.
//주민등록증의 번호는 -를 기준으로 앞자리와 뒷자리로 구분된다.
//뒷자리의 첫 번째 수가 1이면 1900년대생 남자이고, 2이면 1900년대생 여자, 3이면 2000년대 생 남자, 4이면 2000년대생 여자이다.
//올해는 2019년입니다. 해당 주민등록증 주인의 나이와 성별을 출력하세요.

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

int main(){
    string ssnumber;
    cin >> ssnumber;
    char sex;
    //char ssnumber[s.length() + 1];
    //s.copy(ssnumber, s.length() + 1);
    int year =0;
    if (ssnumber[7] == '1'){
        sex = 'M';
        year = 1900 + (ssnumber[0]-48) * 10 + (ssnumber[1]-48);
    }
    else if (ssnumber[7] == '2'){
        sex = 'W';
        year = 1900 + (ssnumber[0]-48) * 10 + (ssnumber[1]-48);
    }
    else if (ssnumber[7] == '3'){
        sex = 'M';
        year = 2000 + (ssnumber[0]-48) * 10 + (ssnumber[1]-48);

    }
    else{
        sex = 'W';
        year = 2000 + (ssnumber[0]-48) * 10 + (ssnumber[1]-48);
    }
    cout << 2020 - year << " " << sex;

}