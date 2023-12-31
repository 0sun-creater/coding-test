//Anagram(아나그램 : 구글 인터뷰 문제)
//Anagram이란 두 문자열이 알파벳의 나열 순서를 다르지만 그 구성이 일치하면 두 단어는 아나그램이라고 합니다.
//예를 들면 AbaAeCe 와 baeeACA 는 알파벳을 나열 순서는 다르지만 그 구성을 살펴보면 A(2), a(1), b(1), C(1), e(2)로 알파벳과 그 개수가 모두 일치합니다. 
//즉 어느 한 단어를 재 배열하면 상대편 단어가 될 수 있는 것을 아나그램이라 합니다.
//길이가 같은 두 개의 단어가 주어지면 두 단어가 아나그램인지 판별하는 프로그램을 작성하세요. 
//아나그램 판별시 대소문자가 구분됩니다.

#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    //대문자 65-90 소문자 97-122
    //-65로 배열에 첫번째 문자열은 ++ 두번째 문자열은 --
    //sum이 0이면 YES, 아니면 NO

    string input1, input2;
    cin >> input1 >> input2;

    vector<int> cnt(58);

    for(int i =0; i<input1.length(); i++){
        cnt[input1[i]-65] +=1;
        cnt[input2[i]-65] -=1;
    }

    if (accumulate(cnt.begin(), cnt.end(),0) == 0){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

}