/*
이진트리 깊이우선탐색(DFS)
아래 그림과 같은 이진트리를 전위순회와 후위순회를 연습해보세요.
    1
  2   3
4  5 6  7
전위순회 출력 : 1 2 4 5 3 6 7 
중위순회 출력 : 4 2 5 1 6 3 7 
후위순회 출력 : 4 5 2 6 7 3 1
*/
#include <iostream>
using namespace std;

//부모 > 왼쪽 > 오른쪽
void front(int i){
    if (i > 7) return;
    cout << i << " ";
    front(i*2); //왼
    front(i*2 + 1); //오
}


//왼쪽 > 부모 > 오른쪽
void middle(int i){
    if (i > 7) return;

    middle(i*2); //왼
    cout << i << " ";
    middle(i*2 + 1); //오
}

//왼쪽 > 오른쪽 > 부모
void back(int i){
    if (i > 7) return;

    back(i*2); //왼
    back(i*2 + 1); //오
    cout << i << " ";
}


int main(){
    cout << "전위순회 출력 : ";
    front(1);
    cout << endl << "중위순회 출력 : ";
    middle(1);
    cout << endl << "후위순회 출력 : ";
    back(1);
}