'''
8개의 톱니를 가진 톱니바퀴 4개가 일렬로 놓여져 있음 (1~4번)
각 톱니는 N극 또는 S극 중 하나를 나타낸다

k번 회전 시킬거임
- 회전시킬 톱니와 방향 필요
- 서로 맞닿은 극이 다르다면 옆 톱니는 반대방향으로 회전 / 같으면 회전x

초기상태와 톱니 회전 방법이 주어졌을 때 최종 톱니 상태 구하기

입력1 4톱니의 초기 상태 (12시방향부터 초기상태, 0:N극, 1:S극)
입력2 회전 횟수 k
입력3 회전방법 : 회전톱니 번호, 방향 (1:시계, -1:반시계)

출력 k번 회전시킨 이후 네 톱니바퀴 점수의 합 출력
12시 방향이 N극이면 0점
1번 S극이면 1점, 2번 S극이면 2점, 3번 S극이면 4점, 4번 S극이면 8점
'''

import sys
from collections import deque

topni = []

topni.append(deque(list(map(int, input().rstrip()))))
topni.append(deque(list(map(int, input().rstrip()))))
topni.append(deque(list(map(int, input().rstrip()))))
topni.append(deque(list(map(int, input().rstrip()))))

k = int(input())



for _ in range(k):
    num, d = map(int, sys.stdin.readline().split())
    num -= 1
    prev = num - 1
    next = num + 1

    #[1][2],[2][6] / [2][2],[3][6] / [3][2],[4][6]
    #초기상태 기준으로 회전시키는 것 (순차적 진행 아님)
    #num을 기준으로 나머지 방향을 정해주고 돌리면 됨

    direct = [0] * 4
    direct[num] = d
    cur = num
    while prev > -1:
        #print(prev, num, ": ",topni[prev][2], topni[num][6])
        if topni[prev][2] == topni[cur][6]:
            break
        else:
            direct[prev] = -1 * direct[cur]

        prev -= 1
        cur -= 1
    cur = num
    while next < 4:
        if topni[cur][2] == topni[next][6]:
            break
        else:
            direct[next] = -1 * direct[cur]
        next +=1
        cur +=1
        
    #print(direct)
    for i in range(4):
        if direct[i] == 0: continue
        if direct[i] == 1: #시계방향
            topni[i].appendleft(topni[i].pop())
        else: #반시계방향
            topni[i].append(topni[i].popleft())

ans = 0
if topni[0].popleft() == 1:
    ans += 1
if topni[1].popleft() == 1:
    ans += 2
if topni[2].popleft() == 1:
    ans += 4
if topni[3].popleft() == 1:
    ans += 8

print(ans)
