//N!에서 0의 개수
//자연수 N이 입력되면 N! 값에서 일의 자리부터 연속적으로 ‘0’이 몇 개 있는지 구하는 프로그 램을 작성하세요.
//만약 5! = 120으로 일의자리부터 연속적된 ‘0’의 개수는 1입니다.
//만약 12! = 479001600으로 일의자리부터 연속적된 ‘0’의 개수는 2입니다.
//n<=1000

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,i,j,tmp;
    cin >> n;
    vector<int> check(n+1);
    for (int i=2; i<=n; i++){
        tmp = i;
        j =2;
        while(tmp!=1){
            if(tmp%j == 0){
                tmp = tmp/j;
                check[j] +=1;
            }
            else{
                j++;
            }
        }    
    }
    
    if (check[2] > check[5]){
        cout << check[5];
    }
    else{
        cout << check[2];
    }

}

