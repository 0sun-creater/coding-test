#include <string>
#include <vector>

using namespace std;
/*
펄스수열 : 1또는 -1로 시작하면서 1과 01이 번갈아 나오는 수열
연속부분수열 x 펄스 수열 의 합 중 가장 큰 것 return
sequence <=500,000
*/
vector<int> purse(vector<int> v, int num){
    for(int i = 0; i < v.size(); i++){
        v[i] = v[i]*num;
        num *= -1;
    }
    return v;
}
long long solution(vector<int> sequence) {
    // 1로 시작하는 펄스 벡터
    vector<int> seq1 = purse(sequence,1);
    // -1로 시작하는 펄스 벡터
    vector<int> seq2 = purse(sequence,-1);
    
    long long answer = -999999999;
    long long dp1[seq1.size()]; // 1 dp 배열
    long long dp2[seq2.size()];// -1 dp 배열
    
    dp1[0] = seq1[0];
    dp2[0] = seq2[0];
    
    long long maxi = 0;
    for(int i = 1; i < sequence.size(); i++){
        // max로 비교위해 자료형 치환
        dp1[i] = max(dp1[i-1]+(long long)seq1[i],(long long)seq1[i]);
        dp2[i] = max(dp2[i-1]+(long long)seq2[i],(long long)seq2[i]);

        maxi = max(dp1[i], dp2[i]);
        answer = max(answer,maxi);
    }
    
    // 1일때는 그냥 둘 중 더 큰거
    if(sequence.size() == 1){
        answer = max(seq1[0],seq2[0]);
        return answer;
    }
    return answer;  
}

/* test 12이상 시간초과 
vector<int> purse(vector<int> v, int num){
    for(int i = 0; i < v.size(); i++){
        v[i] = v[i] * num;
        num *= -1;
    }
    return v;
}

long long solution(vector<int> sequence) {
    long long answer = 0;
    long long dp1[500001];
    long long dp2[500001];
    //dp1 = [1,-1,1,-1..]
    //dp2 = [-1,1,-1,1..]
    // 1로 시작하는 펄스 벡터
    vector<int> seq1 = purse(sequence,1);
    // -1로 시작하는 펄스 벡터
    vector<int> seq2 = purse(sequence,-1);
    long long tmp;
    vector<int> calcu = seq1;
    vector<int> calcu2 = seq2;
    for(int i=1; i< int(sequence.size()); i++){
        for(int j=i; j< int(sequence.size()); j++){
            calcu[j] = calcu[j-1] + calcu[j];
            calcu2[j] = calcu2[j-1] + calcu2[j];
            if(calcu[j] > calcu2[j]) tmp = calcu[j];
            else tmp = calcu2[j];
            if(tmp > answer) answer = tmp;
        }
        calcu = seq1;
        calcu2 = seq2;
    }
    
    return answer;
}

*/