'''
nxn 도시
0 빈칸, 1 집, 2 치킨집 

"치킨 거리" : 가장 가까운 치킨집과 집 사이의 거리
"도시의 치킨거리" : 모든 집의 치킨 거리의 합

거리 = |r1-r2| + |c1-c2|

최대 M개의 치킨집, 나머지 폐업
도시의 치킨 거리를 가장 작게 만들기
'''


import sys
from itertools import combinations
n, m = map(int, sys.stdin.readline().split())
city = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]


chikin = []
house = []

for i in range(n):
    for j in range(n):
        if city[i][j] == 1:
            house.append([i,j])
        elif city[i][j] == 2:
            chikin.append([i,j])

#뭘 빼야할지를 결정하는 알고리즘 작성
#조합 or 백트레킹 해야함
ans = 1234567
for combi in combinations(chikin, m):
    city_dist = 0

    #모든 집에 대해서 최소 거리 구하기
    for h in house:
        dist = 1234567
        for c in combi:
            dist = min(dist, abs(h[0] - c[0]) + abs(h[1] - c[1]))

        #모든 집의 최소 거리를 더하면 도시 거리
        city_dist += dist

    #도시거리를 최소로 만들기
    ans = min(ans, city_dist)

print(ans)
