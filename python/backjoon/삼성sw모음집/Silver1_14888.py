'''
n 개의 수열 주어짐
수와 수 사이에 끼워넣는 n-1개 연산자 주어짐 (+-*/)
주어진 수의 순서 바꾸기 안됨
식의 계산은 연산자 우선순위 무시 / 나눗셈은 정수 나눗셈(몫만 취함)
음수를 양수로 나눌때 = 양수로 바꾼 뒤 몫을 취하고 그 몫을 음수로 변환

만들 수 있는 식의 결과가 최대인 것과 최소인 것 구하기

입력1 N
입력2 N개의 숫자
입력3 덧 뺄 곱 나 의 갯수
'''
import sys
from itertools import permutations

n = int(input())
seq = list(map(int, sys.stdin.readline().split()))
plus, minus, multi, divid = map(int, sys.stdin.readline().split())


oper =[]
for i in range(plus):    
    oper.append('+')
for i in range(minus):
    oper.append('-')
for i in range(multi):
    oper.append('*')
for i in range(divid):
    oper.append('//')

maxi = -1000000000
mini = 1000000000

#순열 : 순서 상관있음, 중복 없음
#순열 for문 돌면서 계산하기
for case in permutations(oper,n-1):
    temp = seq[0]
    for i in range(1, n):
        if case[i-1] =='+':
            temp += seq[i]
        elif case[i-1] == '-':
            temp -= seq[i]
        elif case[i-1] == '*':
            temp *= seq[i]
        elif case[i-1] == '//':
            temp = int(temp/seq[i])

    maxi = max(maxi, temp)
    mini = min(mini, temp)
    
print(maxi)
print(mini)
        
