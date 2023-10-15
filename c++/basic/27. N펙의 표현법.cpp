//N!의 표현법
//임의의 N에 대하여 N!은 1부터 N까지의 곱을 의미한다. 
//이는 N이 커짐에 따라 급격하게 커진다. 
//이러한 큰 수를 표현하는 방법으로 소수들의 곱으로 표현하는 방법이 있다.
//먼저 소수는 2, 3, 5, 7, 11, 13... 순으로 증가함을 알아야 한다.
//예를 들면 825는 (0 1 2 0 1)로 표현이 가능한데, 이는 2는 없고 3은 1번, 5는 2번, 7은 없고, 11은 1번의 곱이라는 의미이다.
//101보다 작은 임의의 N에 대하여 N 팩토리얼을 이와 같은 표기법으로 변환하는 프로그램을 작성해 보자. 

#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n, tmp, j;
    cin >> n;
    vector<int> check(n+1);
    for (int i =2; i <=n; i++){
        tmp = i;
        //소인수분해
        j = 2;
        while(tmp!=1){
            if(tmp%j ==0){
                tmp = tmp/j;
                check[j] +=1;
            }
            else j++;
        }
    }

    cout << n <<"! = ";
    for(int i =2; i<=n; i++){
        if(check[i]!=0){
            cout << check[i] <<" ";
        }
    }
    return 0;
}