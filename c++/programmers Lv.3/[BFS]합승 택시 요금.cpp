#include <string>
#include <vector>

using namespace std;

#define INF 20000000

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    vector<vector<int>> minTaxiCost(n + 1, vector<int>(n + 1, INF)); // 모든 정점들간의 최단 경로를 저장할 (i, j) 2차원 dp 테이블
    
    /* 준비 작업 : (i, j) 는 곧 "i -> 중간에 들리는 정점들 -> j" 의 최단 경로인데, 아직 중간에 뭘 들리기 전, 즉 i->j 직빵 연결된 가중치들이 있다면 기록 */
    for(int i = 0; i < fares.size(); ++i){ 
        minTaxiCost[fares[i][0]][fares[i][1]] = fares[i][2];
        minTaxiCost[fares[i][1]][fares[i][0]] = fares[i][2];
    }   

    /* 준비 작업 : dp[i][i] 자기 자신에서 자기 자신으로의 최단 경로는 0 으로 초기화 (대각선) */  
    for(int i = 1; i <= n; ++i)
        minTaxiCost[i][i] = 0;

    /* 플로이드 알고리즘 핵심  */
    for(int k = 1; k <= n; ++k) // ⭐k 를 거쳐갈 때⭐
        for(int i = 1; i <= n; ++i) // (i, j) : i->j 최단 경로
            for(int j = 1; j <= n; ++j) 
                if (minTaxiCost[i][j] > minTaxiCost[i][k] + minTaxiCost[k][j]) // i 에서 j 로 갈 때 k 를 거쳐가는게 더 좋은 최단 경로가 된다면 업데이트
                    minTaxiCost[i][j] = minTaxiCost[i][k] + minTaxiCost[k][j];

    // 위까지만 완료하면 minTaxiCost 테이블에 모든 (i, j) 정점 쌍의 i->j 최단 경로가 저장되게 된다.
    // 답 도출! 모든 정점(i)에 대하여 dp[s][i] + dp[i][a] + dp[i][b] 가 가장 최소가 될 때의 비용
    for(int i = 1; i <= n; ++i)
        if (answer > minTaxiCost[s][i] + minTaxiCost[i][a] + minTaxiCost[i][b])
            answer = minTaxiCost[s][i] + minTaxiCost[i][a] + minTaxiCost[i][b];
          
    return answer;
}

/*


#include <string>
#include <vector>
#include <queue>

using namespace std;
#define INF 20000000
#define num first 
#define cost second 

struct cmp {
    bool operator() (pair<int, int> a, pair<int, int> b) {
        return a.cost > b.cost;
    }
};

// taxi_cost 추가! (파라미터로 받는 vector 에 최소 비용을 업데이트 할 것이다. 즉, 출발지가 다를 때마다 최소 비용 vector도 따로따로)
// dest 없앴음 (어차피 출발지에서 모든 정점으로의 최단 경로를 구할 것이라서)
void dijkstra(vector<int>& taxi_cost, vector<vector<int>>& graph, int& n, int& start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

    pq.push({ start, 0 });
    taxi_cost[start] = 0;

    while (!pq.empty()) {
        int now = pq.top().num;
        int nowCost = pq.top().cost;
        pq.pop();
           
        for (int i = 1; i <= n; ++i) {

            if (graph[now][i] == 0)
                continue;

            if (taxi_cost[i] > nowCost + graph[now][i]) {
                taxi_cost[i] = nowCost + graph[now][i];
                pq.push({ i, nowCost + graph[now][i] });
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < fares.size(); ++i) {
        graph[fares[i][0]][fares[i][1]] = fares[i][2];
        graph[fares[i][1]][fares[i][0]] = fares[i][2];
    }
    // S 를 출발 정점으로 한 모든 정점까지의 최단 경로 구하여 StoI_cost 에 저장
    vector<int> StoI_cost(n + 1, INF);
    dijkstra(StoI_cost, graph, n, s);
    
    // A 를 출발 정점으로 한 모든 정점까지의 최단 경로 구하여 AtoI_cost 에 저장
    vector<int> AtoI_cost(n + 1, INF);
    dijkstra(AtoI_cost, graph, n, a);
    
    // B 를 출발 정점으로 한 모든 정점까지의 최단 경로 구하여 BtoI_cost 에 저장
    vector<int> BtoI_cost(n + 1, INF);
    dijkstra(BtoI_cost, graph, n, b);

    // (s->i) + (a->i) + (b->i) 택시비용중 최소가 되는 비용
    for (int i = 1; i <= n; ++i) {
        int result = StoI_cost[i] + AtoI_cost[i] + BtoI_cost[i];
        if (answer > result)
            answer = result;
    }

    return answer;
}

*/