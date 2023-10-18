//3의 개수는?
//자연수 N이 입력되면 1부터 N까지의 자연수를 종이에 적을 때 각 숫자 중 3의 개수가 몇 개 있는지 구하려고 합니다.
//예를 들어 1부터 15까지는 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, 1, 1, 1, 2, 1, 3, 1, 4, 1, 5으로 3의 개수는 2개입니다.
//자연수 N이 입력되면 1부터 N까지 숫자를 적을 때, 3의 개수가 몇 개인지 구하여 출력하는 프로그램을 작성하세요.
//N(3<=N<=1,000,000,000)

#include <iostream>
using namespace std;

int main(){
	int n, lt=1, rt, cur, k=1, res=0;
    cin >> n;
	while(lt!=0){
		lt=n/(k*10);
		rt=n%k;
		cur=(n/k)%10;
		if(cur>3) res+=(lt+1)*k;
		else if(cur==3) res+=(lt*k)+(rt+1);
		else res+=lt*k;
		k=k*10;
	}
    cout << res;
	return 0;
}