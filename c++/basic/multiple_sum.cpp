//1부터 n까지 m까지 배수합
//자연수 n이 입력되면 1부터 n까지의 수 중 m의 배수합 출력
#incllude <iostream>
using namespace std;
int main() {
    int n,m, sum =0;
    cin>>n>>m;
    for(int i = 1; i<=n;i++){
        if(i%m==0){
            sum += i;
        }
    }
    cout>>sum;
}