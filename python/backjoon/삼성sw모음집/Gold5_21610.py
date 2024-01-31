'''
파이어볼, 토네이도, 파이어스톰, 물복사버그 + 비바라기
nxn 각 칸엔 바구니 / 저장 물 양 제한 없음
비바라기 : (N, 1), (N, 2), (N-1, 1), (N-1, 2)에 비구름
구름에 M번 명령 i번째 이동 명령은 방향 di와 거리 si로 이루어져 있다.
8 방향 있음 왼, 왼위, 위, 오위, 오, 오아, 아, 왼아 순서
1. 모든 구름이 di방향으로 si칸 이동
2. 각 구름에서 비가 내려 바구니 물의 양이 1 증가
3. 구름 사라짐
4. 2에서 증가한 칸에 물복사 마법 시전
(물 복사 : 대각선 방향으로 거리 1에 물이 있는 바구니의 수만큼 (r,c)에 물 증가)
 - 경계를 넘어가는 칸은 대각선 방향으로 거리가 1인 칸이 아니다.
 - (n,n)에서 인접한 대각선 칸은 (n-1, n-1) 뿐이다.
5. 바구니에 저장된 물의 양이 2이상인 모든 칸에 구름이 생기고, 물의 양이 2 줄어든다.
   이때 구름이 생기는 칸은 3에서 구름이 사라진 칸이 아니어야 한다.

M 번의 이동이 모두 끝난 후 바구니에 들어있는 물의 양의 합을 구해보자.
'''


import sys
n, m = map(int, sys.stdin.readline().split())
bucket = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
move = [list(map(int, sys.stdin.readline().split())) for _ in range(m)]

# 구름 시작 위치 (N-1, 0), (N-1, 1), (N-2, 0), (N-2, 1)
cloud = [[n-2,0],[n-2,1],[n-1,0],[n-1,1]]
# 0, 왼, 왼위, 위, 오위, 오, 오아, 아, 왼아 (경계 넘어가기 : % 이용)
dx = [0, -1,-1, 0, 1,1,1,0,-1]
dy = [0, 0,-1,-1,-1,0,1,1, 1]

x = [-1, 1,1,-1]
y = [-1,-1,1, 1]

for d, s in move:
    visited = [[False]*n for _ in range(n)]
    # 1. 구름 이동
    # move_x = (dx[d] x s) % n /  move_y = (dy[d] x s) % n
    # cloud 모든 원소 x + move_x, y + move_y
    move_x = (dx[d] * s) % n
    move_y = (dy[d] * s) % n
    for c in cloud:
        c[0] += move_y
        c[1] += move_x
    
        if c[0] >= n:
            c[0] -=  n
        if c[1] >= n:
            c[1] -= n
        # 2. 이동한 자리 1씩 증가
        bucket[c[0]][c[1]] +=1
        visited[c[0]][c[1]] = True
        # 얘를 모든 클라우드에 +1 한 이후에 세야해
    for c in cloud:
        # 4. cloud 각각 대각선 4위치에 물 있는 바구니 cnt 확인 cnt만큼 ++
        cnt = 0
        for i in range(4):
            checkX = c[0] + y[i]
            checkY = c[1] + x[i]
            if checkX >=0 and checkY >= 0 and checkX < n and checkY < n and bucket[checkX][checkY] > 0:
                cnt += 1
        bucket[c[0]][c[1]] += cnt

    cloud = []
    # 5. cloud 제외 물의 양이 2이상인 칸 = new_cloud / bucket -= 2
    for i in range(n):
        for j in range(n):
            if visited[i][j]:
                continue
            if bucket[i][j] > 1:
                cloud.append([i,j])
                bucket[i][j] -= 2


print(sum(sum(bucket, [])))

