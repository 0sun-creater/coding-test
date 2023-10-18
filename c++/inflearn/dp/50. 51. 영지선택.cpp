/*영지(territory) 선택 : 브루트포스-슬라이싱해서 전부 sum 해보면서 세기/dp
세종대왕은 현수에게 현수가 다스릴 수 있는 영지를 하사하기로 했다. 전체 땅은 사각형으로 표 시된다. 
그 사각형의 땅 중에서 세종대왕이 현수가 다스릴 수 있는 땅의 크기(세로의 길이와 가 로의 길이)를 정해주면
전체 땅 중에서 그 크기의 땅의 위치를 현수가 정하면 되는 것이다.
전체 땅은 사각형의 모양의 격자로 되어 있으며, 그 사각형 땅 안에는 많은 오렌지 나무가 심 겨져 있다.
현수는 오렌지를 무척 좋아하여 오렌지 나무가 가장 많이 포함되는 지역을 선택하고 싶어 한다.
현수가 얻을 수 있는 영지의 오렌지 나무 최대 개수를 출력하는 프로그램을 작 성하세요.
다음과 같은 땅의 정보가 주어지고, 현수가 하사받을 크기가, 가로 2, 세로 3의 크 기이면 가장 많은 오렌지 나무가 있는 영지는 총 오렌지 나무의 개수가 16인 3행 4열부터 시 작하는 구역이다.
*/

#include <iostream>
#include <vector>

using namespace std;

int mapp[701][701], dp[701][701];
int main(){
    int n, m, tmp;
    cin >> n >> m;
    for(int i =1; i<= n; i++){
        for(int j =1; j <=m; j++){
            cin >> tmp;
            mapp[i][j] = tmp;
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mapp[i][j];
        }
    }
    int h, w;
    cin >> h >> w;
    int result = -2147000000;
    for(int i =h; i<= n; i++){
        for(int j =w; j<=m; j++){
            tmp = dp[i][j]-dp[i-h][j]-dp[i][j-w]+dp[i-h][j-w];
            if(tmp>result) result = tmp;
        }
    }
    cout << result;
}