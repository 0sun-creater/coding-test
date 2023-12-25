'''
총 N개의 시험장이 있고, 각각의 시험장마다 응시자들이 있다. i번 시험장에 있는 응시자의 수는 Ai명이다.
감독관은 총감독관과 부감독관으로 두 종류가 있다.
총감독관은 한 시험장에서 감시할 수 있는 응시자의 수가 B명이고,
부감독관은 한 시험장에서 감시할 수 있는 응시자의 수가 C명이다.

각각의 시험장에 총감독관은 오직 1명만 있어야 하고, 부감독관은 여러 명 있어도 된다.

각 시험장마다 응시생들을 모두 감시해야 한다.
이때, 필요한 감독관 수의 최솟값을 구하는 프로그램을 작성하시오.

입력1 시험장의 개수 n <=1,000,000
입력2 각 시험장에 있는 응시자 수 <=1,000,000   각 시험 장의 인원수는 다르다
입력3 B C <=1,000,000
'''
import sys
n = int(input())
s = list(map(int, sys.stdin.readline().split()))

b, c = map(int, sys.stdin.readline().split())

#총 감독관 1명이 B를 감시
answer = n

#부감독관 (s-b) / C 명 만큼 필요 
for student in s:
    total = student - b
    if total > 0:
        if total % c == 0:
            answer += total // c
        else:
            answer += (total // c) +1


print(answer)
