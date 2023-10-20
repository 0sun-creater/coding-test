/*
길이가 n인 자연수로 이루어진 수열이 주어진다.
수열의 각 항 사이에 끼워넣을 n-1개의 연산자가 주어짐 덧뺄곱나눗셈만 있음
수열은 그대로, 연산자를 적절히 배치하면 다양한 수식이 나옴
수식을 계산하는 결과는 연산자 우선순위를 따지지 않고 맨 앞쪽 연산자부터 차례로 계산

만들 수 있는 수식들 중에서 연산한 결과가 최대인것과 최소인것을 출력
*/

//0번 덧셈, 1번 뺄셈, 2번 곱셈, 3번 나눗셈

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> numbers;
int oper[4];
int n, result_max = -2147000000, result_min = 2147000000;
void dfs(int cur, int sum){
    if(cur == n){
        if(result_max < sum) result_max = sum;
        if(result_min > sum) result_min = sum;
    }
    else{
        if(oper[0]>0){
            oper[0]--;
            dfs(cur+1,sum+numbers[cur]);
            oper[0]++;
        }
        if(oper[1] > 0){
            oper[1]--;
            dfs(cur+1,sum-numbers[cur]);
            oper[1]++;
        }
        if(oper[2] > 0){
            oper[2]--;
            dfs(cur+1,sum*numbers[cur]);
            oper[2]++;
        }
        if(oper[3] > 0){
            oper[3]--;
            dfs(cur+1,sum/numbers[cur]);
            oper[3]++;
        }
    }

}

int main(){
    int tmp;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> tmp;
        numbers.push_back(tmp);
    }
    for(int j=0; j<4; j++){
        cin >> tmp;
        oper[j] =tmp;
    }
    dfs(1, numbers[0]);

    cout << result_max << endl;
    cout << result_min << endl;

    return 0;
}