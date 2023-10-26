#include <string>
#include <vector>

using namespace std;


/*
n x 3 크기의 판
새로운 도형에 대해서 새로운 조합의 타일을 만들어야 한다.
n = 2인 타일은 3가지 경우가 있지만, 3 * 1 + 3 * 1인 경우는 새로운 타일이 아니다.
n > 3인 경우, 3으로 나눈 나머지가 1, 2, 0일 때 새롭게 추가되는 유형의 타일링이 2, 2, 4개로 반복된다는 점이다. (
F(n) = F(n - 1) + F(n - 2) * 2 + F(n - 3) * 5 + sum(F(n - 4 - 3k)) * 2 + sum(F(n - 5 - 3k)) * 2 + sum(F(n - 6 -3k)) * 4
dp [0 1 2 3  4 5 6 7 8 9 10 11 12 13]
1 : 1
2 : 3 
3 :   (2+1)+(1+2) + 5 


*/
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long dp[100002] = { 1, 1, 3, 10, 23, 62, 170, };
long long sum[100002] = { 1, 1, 3, 11, 24, 65, 181, };

const int INF = 1e9 + 7;

int solution(int n) {
	for (int i = 7; i <= n; i++) {
		dp[i] = dp[i - 1];
		dp[i] += dp[i - 2] * 2;
		dp[i] += dp[i - 3] * 5;
		dp[i] += sum[i - 4] * 2;
		dp[i] += sum[i - 5] * 2;
		dp[i] += sum[i - 6] * 4;
		dp[i] %= INF;

		sum[i] = dp[i] + sum[i - 3];
		sum[i] %= INF;
	}

	return dp[n];
}