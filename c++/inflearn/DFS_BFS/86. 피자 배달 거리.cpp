/*
n*n 도시 지도
0은 빈칸, 1은 집, 2는 피자집
피자배달거리 : 각 집의 피자배달거리는 해당 집과 도시의 존재하는 피자집들과의 거리중 최소값
집과 피자집의 피자 배달거리는 |x1-x2|+|y1-y2|

피자집 중 m개만 살리고 나머지는 보조금을 주고 폐업시킬래
기준 : 도시의 피자배달거리가 최소가 되는 m개의 피자입을 선택
도시의 피자배달거리 = 각 집들의 피자배달거리를 합한 것
*/

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


struct Pointer{
    int x;
    int y;
    Pointer(int a, int b){
        x = a;
        y = b;
    }
};
vector<Pointer> pizza;
vector<Pointer> house;
int n,m, res = 2147000000, dist, sum=0; //n은 격자 크기, m은 선택할 피자집 갯수
int check[51];
int pizza_dist(int x1, int y1, int x2, int y2){
    return abs(x1-x2) + abs(y1-y2);
}

void dfs(int depth, int cnt){
    if(depth > int(pizza.size())) return;
    if(depth == m){
        sum=0;
        //집마다 피자배달거리 구하기
        for(int i=0; i< int(house.size()); i++){
            dist = 2147000000;
            //모든 피자집의 거리를 구해보고 젤 작은거
            for(int j=0; j<m; j++){
                dist = min(dist, pizza_dist(house[i].x, house[i].y, pizza[check[j]].x, pizza[check[j]].y));
            }
            //집마다 피자배달거리 더하면 도시 피자배달거리
            sum += dist;
        }
        if(sum < res) res = sum;
    }
    else{
        //조합 (피자집 중 m개가 뽑힐 조합)
        for(int i=cnt; i< int(pizza.size()); i++){
            check[depth] = i;
            dfs(depth+1, cnt+1);
        }
        /*
        check[cnt] = cur;
        dfs(cur+1, cnt+1);
        dfs(cur+1, cnt);*/
    }
}

int main(){
    cin >> n >> m;
    int tmp;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> tmp;
            if (tmp == 1) {
                house.push_back(Pointer(i,j));
            }
            if (tmp == 2){
                pizza.push_back(Pointer(i,j));
            }
        }
    }

    dfs(0,0);

    cout << res;
}
