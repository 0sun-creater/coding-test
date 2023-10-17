//Inversion Sequence
//1부터 n까지의 수를 한 번씩만 사용하여 이루어진 수열이 있을 때, 
//1부터 n까지 각각의 수 앞에 놓여 있는 자신보다 큰 수들의 개수를 수열로 표현한 것을 Inversion Sequence라 한다.

//n과 1부터 n까지의 수를 사용하여 이루어진 수열의 inversion sequence가 주어졌을 때, 
//원래 의 수열을 출력하는 프로그램을 작성하세요.

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,tmp;
    cin >> n;
    vector<int> inversion(n+1);
    vector<int> original(n+1);
    for(int i =1; i<n+1; i++){
        cin >> tmp;
        inversion[i]=tmp;
    }
    int pos;
    for(int i =n; i>0; i--){
        pos = i;
        for(int j =1; j<=inversion[i]; j++){
            original[pos] = original[pos+1];
            pos++; 
        }
        original[pos] = i;
    }

    for(int i =1; i<n+1; i++){
        cout << original[i] << " ";
    }

}


