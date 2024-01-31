#여행에 필요하다고 생각하는 n개 물건 (무게 W, 가치 V)
#가치 V만큼 즐김
#최대 K만큼의 무게만을 넣는 배낭

#입력0 N 물품의 수 K 버틸 무게
#입력1 N개의 줄에 거쳐 각 물건의 무게 W와 가치 V가 주어짐

#출력 V를 최대치로 만들기

n, k = map(int, input().split())

knapsack = [[0,0]]
for _ in range(n):
    w, v = map(int, input().split())
    knapsack.append([w,v])


dp = [[0] *(k+1) for _ in range(n+1)]

for i in range(1,n+1):
    for j in range(1,k+1):
        w = knapsack[i][0]
        v = knapsack[i][1]

        if j < w:
            dp[i][j] = dp[i-1][j]
        else:
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-w]+v)

print(dp[n][k])




'''
#Knapsack 알고리즘

Fraction Knapsack :  물건의 가격을 무게로 나누어 무게 대비 가격이 비싼 순서로 물건을 정렬해서
넣으면 쉽게 해결할 수 있다.
남은 배낭이 감당할 수 있는 무게보다 물건의 무게가 많이 나가면 잘라서 넣으면 됩니다.
--> 그리디

0-1 Knapsack :  물건을 자를 수 없기 때문에 물건의 무게, 물건의 가격, 배낭의 남은 용량을
모두 고려해야 한다. --> dp

https://hongcoding.tistory.com/50
'''
