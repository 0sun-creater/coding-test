//선택정렬
//N개이 숫자가 입력되면 오름차순으로 정렬하여 출력하는 프로그램을 작성하세요.
//정렬하는 방법은 선택정렬입니다.

#include<stdio.h>
int main() {
	int a[101], n, tmp, idx, i, j;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	for(i=0; i<n-1; i++){
		idx=i;
		for(j=i+1; j<n; j++){
			if(a[j]<a[idx]) idx=j;
		}
		tmp=a[i];
		a[i]=a[idx];
		a[idx]=tmp;
	}
	for(i=0; i<n; i++){
		printf("%d ", a[i]);
	}
	return 0;
}
