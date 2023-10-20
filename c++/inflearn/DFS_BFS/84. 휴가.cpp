/*
카운셀러로 일하고 있는 현수는 오늘부터 n+1일째 되는 날 휴가를 가기 위해,
남은 n일 동안 최대한 많은 상담을 해서 휴가비를 넉넉히 만들어 휴가를 떠나려한다.

회사에 하루에 하나씩 서로 다른 사람의 상담이 예약되어 있다.
각각의 상담을 완료하는데 걸리는 날수 t와 상담을 했을 때 받을 수 있는 금액 p로 이루어져있다.

1일에 t=4 p=20이면 1일에 상담하면 4일까지는 상담을 할 수가 없다.
최대 이익이나는 상담 스케쥴을 짜는 프로그램 작성
*/

/*
1 +T 5+t 7 .  날짜 + t가 n+1보다 크면 할 수 없음
*/

#include <iostream>
#include <vector> 

using namespace std;

struct Work{
    int t;
    int p;

    Work(int a, int b){
        t =a;
        p =b;
    }
};

vector<Work> sca;
int n, result = -2147000000;
void dfs(int cur, int sum){
    if (cur == n+1){
        if(result < sum) result = sum;
        return;
    }
    if(cur + sca[cur].t <=n+1) {
        dfs(cur + sca[cur].t, sum + sca[cur].p);
    }
    dfs(cur+1, sum);
}

int main(){
    int tmp1, tmp2;
    cin >> n;
    sca.push_back(Work(-1,-1)); //0일차
    for (int i=0; i<n; i++){
        cin >> tmp1 >> tmp2;
        sca.push_back(Work(tmp1, tmp2));
    }
    dfs(1, 0);
    
    cout << result;
}