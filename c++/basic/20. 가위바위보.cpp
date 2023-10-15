// 가위 바위 보
//A, B 두 사람이 가위바위보 게임을 합니다. 
//총 N번의 게임을 하여 A가 이기면 A를 출력하고, B가 이기면 B를 출력합니다. 
//비길 경우에는 D를 출력합니다.
//가위, 바위, 보의 정보는 1:가위, 2:바위, 3:보로 정하겠습니다.
//두 사람의 각 회의 가위, 바위, 보 정보가 주어지면 각 회를 누가 이겼는지 출력하는 프로그램 을 작성하세요

#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    vector<int> B(n);
    for (int i =0; i < n; i++){
        cin >> A[i];
    }
    for (int i =0; i < n; i++){
        cin >> B[i];
    }

    for (int i =0; i< n;i++){
        if (A[i] == B[i]) {
            cout << "D" <<endl;
        }
        else if (A[i] == 1 && B[i] ==2){
            cout << "B" <<endl;
        }
        else if (A[i] == 1 && B[i] ==3){
            cout << "A" <<endl;
        }
        else if (A[i] == 2 && B[i] ==3){
            cout << "B" <<endl;
        }
        else if (A[i] == 2 && B[i] ==1){
            cout << "A" <<endl;
        }
        else if (A[i] == 3 && B[i] ==1){
            cout << "B" <<endl;
        }
        else if (A[i] == 3 && B[i] ==2){
            cout << "A" <<endl;
        }
    }
}