#include <string>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
/*
포화 이진트리 만들기 (루트 노드는 그대로 유지)
더미노드면 0 아니면 1
문자열에 저장된 이진수를 십진수로 변환

numbers : 이진트리로 만들고 싶은 수
이진트리로 표현 가능하면 1 안되면 0
*/
int bin[100] = {0};

bool check(long long s, long long e){
    if(s + 1 == e) return true; //둘이 첫 mid에 가까워짐
    long long mid = (s + e) / 2;
    if(bin[mid] == 0){	//부모노드가 0이고
        for(int i = s ; i < e ;i++){
            if(bin[i] == 1) //자식노드가 있을 경우
                return false;
        }
        return true;
    }
    return check(s,mid) && check(mid+1,e);
}
vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(long long num : numbers){
        long long k = 0;
        long long len = 1;
        memset(bin,0,sizeof(bin));
        
        //포화이진트리 크기 = 2^k - 1 (k은 레벨)
        while(pow(2,k) <= num){
            k += 1;
        }
        while(len < k){
            len *= 2;
        }
        len -= 1;
        //len 뒤에부터 숫자 채워넣기 (앞에는 0 더미로 채워질거임)
        for(int i = len - 1 ; i >= 0 ;i--){
            bin[i] = num % 2;
            num /= 2;
        }
        if(check(0,len)) answer.push_back(1);
        else answer.push_back(0);
    }
    return answer;
}