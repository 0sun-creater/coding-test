'''
NxM 방
청소기는 바라보는 방향이 있음 (동,서,남,북)
빈 칸은 전부 청소되지 않은 상태

1. 현재 칸이 아직 청소되지 않은 경우, 현재 칸 청소
2. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 없는 경우,
   - 바라보는 방향을 유지한 채로 한 칸 후진할 수 있다면 후진하고 1번으로
   - 바라보는 방향의 뒤쪽 칸이 벽이라 후진할 수 없다면 stop
3. 현재 칸의 주변 4칸 중 청소되지 않은 빈 칸이 있는 경우,
   - 반시계 방향으로 90도 회전 (위->왼->아->오->위..)
   - 바라보는 방향을 기준으로 앞쪽 칸이 청소 x면 한칸 전진
   - 1번으로 돌아감
'''

import sys
from collections import deque

n, m = map(int, sys.stdin.readline().split())
r, c, d = map(int, sys.stdin.readline().split())
if d == 1: #첫 d = 북동남서
    d = 3
elif d== 3:
    d = 1
#distance 북서남동 (반시계방향)
dx = [-1, 0, 1, 0]
dy = [0, -1, 0,  1]

backx = [1, 0, -1, 0]
backy = [0, 1, 0, -1]
#0:청소x 1:벽 2:청소 완
room = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

ans = 0
while True:
    #print(r,c,d,ans)
    #현재 칸이 아직 청소되지 않은 경우
    if room[r][c] == 0:
        room[r][c] = 2
        ans +=1

    flag = 0
    #현재 칸의 주변 4칸 확인
    for i in range(4):
        _r = r + dx[i]
        _c = c + dy[i]
        _d = i
        if _r <0 or _c <0 or _r >= n or _c >= m: #room 밖으로는 continue
            continue

        if room[_r][_c] == 0:   
            flag = 1
            break

    #청소되지 않은 칸이 있는 경우
    if flag ==1:
        #반시계 방향으로 90도 회전
        d = (d+1) % 4
        #바라보는 방향을 기준으로 앞쪽 칸이 청소x인 경우 전진
        _r = r + dx[d]
        _c = c + dy[d]
        if room[_r][_c] == 0:
            r = _r
            c = _c
            continue
        

    #청소되지 않은 칸이 없는 경우
    else:
        #바라보는 방향을 유지한 채로 한 칸 후진
        r = r + backx[d]
        c = c + backy[d]

        #벽이라 후진할 수 없다면 stop
        if r <0 or c <0 or r >= n or c >= m or room[r][c] == 1:
            break

print(ans)            
        
