#동전의 종류가 주어질 때, 주어진 금액을 만드는 모든 방법을 세기

#입력0 t 테스트 케이스 개수
#테스트별
#입력1 n 동전의 가지 수
#입력2 n 가지 동전의 각 금액 (오름차순) 1~10000 (정수) 공백으로 구분
#입력3 주어진 n 가지 동전으로 만들어야 할 금액 m
#방법의 수는 2^31-1 보다 작음

#출력 각 테케에 대해 n가지 동전으로 금액 m을 만드는 모든 방법의 수 출력


#이전의 경우를 저장해놓고, 현재의 경우와 이전의 경우를 합해 나가면서 경우의 수를 계산
import sys

test_case = int(input())

for _ in range(test_case):
    n = int(input())
    cost = list(map(int, input().split()))
    target = int(input())

    dp = [0] * (target + 1)
    dp[0] = 1

    for coin in cost:
        for i in range(target + 1):
            if i >= coin:
                dp[i] += dp[i - coin]

    print(dp[target])

'''

#Knapsack 알고리즘

Fraction Knapsack :  물건의 가격을 무게로 나누어 무게 대비 가격이 비싼 순서로 물건을 정렬해서 넣으면 쉽게 해결할 수 있다.
남은 배낭이 감당할 수 있는 무게보다 물건의 무게가 많이 나가면 잘라서 넣으면 됩니다.
0-1 Knapsack :  물건을 자를 수 없기 때문에 물건, 물건의 무게, 물건의 가격, 배낭의 남은 용량을 모두 고려해야 한다.
= 이 문제에 해당하는 유형으로 dp로 해결할 수 있습니다.


def knapsack(n, coins, cost):
    DP = [[0] * (cost + 1) for _ in range(n+1)]
    DP[0][0] = 1
    for i in range(1, n+1):
        coin = coins[i]
        for j in range(0, cost+1):
            cnt = j//coin
            for k in range(0,coin*cnt +1,coin):
                DP[i][j] += DP[i-1][j-k]
    print(DP[n][cost])
'''
