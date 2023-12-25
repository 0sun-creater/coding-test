'''
축구는 평일 오후에 하고 의무 참석 아님
모인 사람 n명 (짝수)
n/2로 스타트팀과 링크팀 나누기

i와j번 사람이 같은 팀에 속했을 때 팀에 더해지는 능력치
팀의 능력치는 팀에 속한 모든 쌍의 능력치의 합

Sij와 Sji는 다를 수도 있다.
따라서 1,2번이 한 팀이면 S12 + S21 해주어야 함

두 팀의 능력치의 차이를 최소로 하려고 한다.
 ==> 차가 0에 가까워야함 min(mini, abs())

입력1 n
입력2 n개의 줄에 S가 주어짐 Sii는 항상 0
출력 능력치 차이의 최소값
'''
import sys
import math

n = int(input())

s = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

dp = [[0 for _ in range(n)] for _ in range(n)]

for i in range(n):
    for j in range(i+1, n):
        dp[i][j] = s[i][j] + s[j][i]
        dp[j][i] = s[i][j] + s[j][i]
      
# 조합으로 n/2 개 뽑기라고 치면 스타트팀과 링크팀의 선수가 바뀐것도 계산함
# 절반 잘라줌

from itertools import combinations
arr = [i for i in range(n)]

combi = list(combinations(arr,n//2))
combi_len = math.comb(n, n//2) -1

mini = 1000000000
for i in range(combi_len//2 +1):
    Ateam = 0
    Bteam = 0
    comA = combinations(combi[i],2)
    comB = combinations(combi[combi_len-i],2)

    for a in comA:
        Ateam += dp[a[0]][a[1]]

    for b in comB:
        Bteam += dp[b[0]][b[1]]

    mini = min(mini, abs(Ateam - Bteam))

print(mini)

    



    























