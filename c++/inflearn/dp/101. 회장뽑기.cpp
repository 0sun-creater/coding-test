/*
월드컵축구의 응원을 위한 모임에서 회장을 선출하려고 한다. 
이모임은 만들어진지 얼마 되지 않았기 때문에 회원사이에 서로 모르는 사람도 있지만,
몇 사람을 통하면 서로 모두 알 수 있 다.

각 회원은 다른 회원들과 가까운 정도에 따라 점수를 받게 된다.
예를 들어 어느 회원이 다른 모든 회원과 친구이면, 이 회원의 점수는 1점이다.
어느 회원의 점수가 2점이면, 다른 모든 회원이 친구이거나, 친구의 친구임을 말한다.

또한, 어느 회원의 점수가 3점이면, 다른 모든 회원이 친구이거나, 친구의 친구이거나, 친국의 친구의 친구임을 말한다.

4점, 5점등은 같은 방법으로 정해진다.

각 회원의 점수를 정할 때 주의할 점은 어떤 두 회원이 친구 사이이면서 동시에 친구의 친구 사이이면,
이 두 사람은 친구사이라고 본다. 회장은 회원들 중에서 점수가 가장 작은 사람이 된다.
회장의 점수와 회장이 될 수 있는 모든 사람을 찾는 프로그램을 작성하시오.

입력의 첫째 줄에는 회원의 수가 있다.
단, 회원의 수는 50명을 넘지 않는다. 둘째 줄 이후로는 한 줄에 두 개의 회원번호가 있는데,
이것은 두 회원이 서로 친구임을 나타낸다.
회원번호는 1부터 회원의 수만큼 번호가 붙어있다. 마지막 줄에는 -1이 두 개 들어있다

첫째 줄은 회장 후보의 점수와 회장후보 수를 출력하고 두 번째 줄은 회장 후보를 모두 출력 한다.
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<vector<int> > f (n+1, vector<int>(n+1, 100));
    int tmp=0, tmp2=0;
    //입력
    while(1){
        cin >> tmp >> tmp2;
        if(tmp==-1 && tmp2==-1) break;
        f[tmp][tmp2] = 1;
        f[tmp2][tmp] = 1;
    }

    //플로드와샬 (최소거리)
    for(int k=1; k<=n; k++){
        for(int i=1;i<=n; i++){
            for(int j=1;j<=n; j++){
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }

    //최대 숫자가 젤 작은 놈이 회장
    int score = 100;
    vector<int> res(n+1);
    for(int i=1; i<=n; i++){
        for(int j=1;j<=n; j++){
            if(i==j) continue;
            res[i] = max(res[i], f[i][j]);
        }
        score = min(score, res[i]);
    }
    
    //vector 원소 수 세기
    int cnt = count(res.begin(), res.end(), score);
    
    cout << score << " " << cnt <<endl;
    for(int i=1; i<n; i++){
        if(res[i] == score) cout << i << " ";
    }
    return 0;
}