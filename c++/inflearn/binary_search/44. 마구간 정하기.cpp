//마구간 정하기(이분검색 응용)
//N개의 마구간이 1차원 수직선상에 있습니다. 각 마구간은 x1, x2, x3, ......, xN의 좌표를 가 지며, 마구간간에 좌표가 중복되는 일은 없습니다.
//현수는 C마리의 말을 가지고 있는데, 이 말들은 서로 가까이 있는 것을 좋아하지 않습니다.
//각 마구간에는 한 마리의 말만 넣을 수 있고, 가장 가까운 두 말의 거리가 최대가 되게 말을 마구간에 배치하고 싶습니다.
//C마리의 말을 N개의 마구간에 배치했을 때 가장 가까운 두 말의 거리가 최대가 되는 그 최대 값을 출력하는 프로그램을 작성하세요.

#include <iostream>

using namespace std;
int n;
int check(int len, int x[]){
    int cnt =1, pos = x[1];
    for (int i =2; i<=n; i++){
        if(x[i]-pos >= len){ //거리가 mid보다 크면
            cnt ++; //말을 위치시킴
            pos=x[i];
        }
    }
    return cnt; //놓을 수 있는 말의 개수
}
int main(){
    int c,tmp,result;
    cin >> n >> c;
    int *xi = new int[n+1];
    for(int i =1; i< n+1; i++){
        cin >> xi[i];
    }
    sort(xi+1, xi+n+1);
    int right = xi[n];
    int left = 1, mid;
    //결정 알고리즘 : mid가 답이라고 결정지어놓고 되는지 안되는지 확인하기
    while(left <= right){
        mid = (left + right) /2;
        if (check(mid, xi) >= c){
            result = mid;
            left = mid+1;
        }
        else{
            right = mid-1;
        }
    }
    cout << result;
    delete[] xi;
    return 0;
}