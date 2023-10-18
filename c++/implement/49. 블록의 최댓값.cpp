/*
블록의 최댓값
현수에게 정면에서 본 단면과 오른쪽 측면에서 본 단면을 주고 최대 블록개수를 사용하여
정면과 오른쪽 측면에서 본 모습으로 블록을 쌓으라 했습니다.
현수가 블록을 쌓는데 사용해야 할 최대 개수를 출력하는 프로그램을 작성하세요.

*/

#include <vector>
#include <iostream>

using namespace std;

int main(){
    int n,tmp;
    cin >> n;
    vector<int> front;
    vector<int> side;

    int** arr = new int*[n];      
    for(int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }

    for(int i = 0; i < n;i++){
        cin >> tmp;
        for(int j =0; j<n; j++){
            arr[j][i] = tmp;
        }
    }

    int sum =0;
    for(int i = 0; i < n;i++){
        cin >> tmp;
        for(int j =0; j<n; j++){
            if (arr[i][j] > tmp){
                arr[i][j] = tmp;
            }
            sum += arr[i][j];
        }
    } 

    cout << sum;
   
}