'''
nxn 교실 학생 수는 n^2
(1,1) ~ (n,n)
|r1 - r2| + |c1 - c2| = 1 만족하는 두 칸이 (r1, c1)과 (r2, c2)를 인접


1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다
2. 1을 만족하는 칸이 여러 개이면,
   인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
3. 2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로,
   그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.
'''

#상하좌우 인접한 자리가 원하는 학생인지 탐색 => BFS
#조건 : 우선순위 존재
#1. 매칭 수의 내림차순 (매칭 수가 같다면 빈칸의 개수 순으로 내림차순)
#2. 빈칸의 개수가 같다면 행의 번호순으로 오름차순
#3. 행의 번호가 같다면 열의 번호순으로 오름차순

#매칭, 빈칸, 행/열 정보를 한 배열에 모아 정렬
#가장 앞에 있는 것이 최우선순위 -> 학생의 위치
import sys
from queue import PriorityQueue

class Data:
    def __init__(self, match, empty, r, c):
        self.match = match
        self.empty = empty
        self.r = r
        self.c = c

    def __lt__(self,other):
        
    
n = int(input())
room = [[0 for _ in range(n)] for _ in range(n)]
student = dict()
for _ in range(n*n):
    num, s1, s2, s3, s4 = map(int, sys.stdin.readline().split())
    student[num] = [s1, s2, s3, s4] 
print(student)


dx = [0,0,-1,1]
dy = [-1,1,0,0]

q = PriorityQueue()

# 정렬 규칙
# if
q.put()
while not q.empty():
    q.get()

import heapq



#학생의 만족도 리턴 (자리배치 끝난 후)
#인접한 칸에 좋아하는 학생 수
ans = 0
love = {0:0, 2:10, 3:100, 4:1000}
for i in range(n):
    for j in range(n):
        cnt = 0
        print(i,j)
        if i-1 >= 0 and room[i-1][j] in student[room[i][j]]:
            cnt +=1
        if j-1 >= 0 and room[i][j-1] in student[room[i][j]]:
            cnt +=1
        if i+1 < n and room[i+1][j] in student[room[i][j]]:
            cnt +=1
        if j+1 < n and room[i][j+1] in student[room[i][j]]:
            cnt +=1
        ans += love[cnt]

print(ans)
