'''
n+1일째 되는 날 퇴사를 하기 위해 n일 동안 최대한 많은 상담
t 상담을 완료하는데 걸리는 기간
p 상담을 했을 때 받을 수 있는 금액

최대 수익 구하는 프로그램

입력1 n
입력2 n개 줄에 t와 p
출력 최대 이익
'''
import sys

n = int(input())
tp = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

dp = [0 for _ in range(n+1)]

    
for i in range(n-1, -1, -1):
    #tp[i][0] : Ti i일째의 보수기간
    #tp[i][1] : Pi i일째의 보수
    if tp[i][0] + i > n: #i일 + 보수기간  > 퇴사날 
        dp[i] = dp[i+1] #지난 상담까지의보수 
    else:
        #1. [i일 + 보수기간] + i일째의 보수 : 오늘 상담을 할 경우
        #2. dp[i+1] : 지난 상담까지의 보수 (오늘 상담을 하지 않을 경우)
        #1,2 중에서 누적 보수가 큰 경우를 저장
        dp[i] = max(dp[tp[i][0] + i] + tp[i][1], dp[i+1])
    #print(dp)

print(dp[0])
