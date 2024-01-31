#최장 공통 부분 수열 문제
#두 수열이 주어졌을 때,모두의 부분 수열이 되는 수열 중 가장 긴 것 찾기

#입력1 문자열
#입력2 문자열

#출력 두 문자열의 LCS의 길

import sys
read = sys.stdin.readline

word1, word2 = read().strip(), read().strip()
w1, w2 = len(word1), len(word2)

dp = [0] * w2

for i in range(w1):
    cnt =0
    for j in range(w2):
        if cnt < dp[j]:
            cnt = dp[j]
        elif word1[i] == word2[j]:
            dp[j] = cnt+1
print(max(dp))





#https://myjamong.tistory.com/317 풀이2
        
