/*
복면산 SEND+MORE=MONEY
출력형태
  9567
+ 1085
-------
 10652

 숫자를 문자로 치환하여 나타낸 수식으로부터 각 문자가 나타내는 원래의 숫자를 알아내어 전체식을 완성하는 문제
 특별한 언급이 없는 한, 같은 문자는 같은 숫자를 나타냄
 첫 번재 자리의 숫자는 0이 아니라고 가정하는 것이 보통
 본면산 문제의 답은 유일해야함.

*/
//a[o,e,m,n,o,r,s,y] 로 대응되어 있음
//순열 문제라는데 뭔소린지 모르겠음;

#include<stdio.h>
using namespace std;
int a[10], ch[10];
int send() {
	return a[6]*1000+a[1]*100+a[3]*10+a[0];
}
int more() {
	return a[2]*1000+a[4]*100+a[5]*10+a[1];
}
int money() {
	return a[2]*10000+a[4]*1000+a[3]*100+a[1]*10+a[7];
}
void P(int L) {
	if(L==8) {
		if(send()+more()==money()){
			if(a[2] == 0 || a[6] == 0) return;
			printf("  %d %d %d %d\n", a[6], a[1], a[3], a[0]);
			printf("+ %d %d %d %d\n", a[2], a[4], a[5], a[1]);
			printf("---------\n");
			printf("%d %d %d %d %d\n", a[2], a[4], a[3], a[1], a[7]);
		}
	}
	else {
		for(int i=0; i<10; i++) {
			if(ch[i]==0) {
				a[L]=i;
				ch[i]=1;
				P(L+1);
				ch[i]=0;
			}
		}
	}
}
int main() {
	P(0);
	return 0;
}