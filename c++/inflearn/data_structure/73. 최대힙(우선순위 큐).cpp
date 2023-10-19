/*
최대힙(priority_queue : 우선순위 큐)
최대힙은 완전이진트리로 구현된 자료구조입니다. 
그 구성은 부모 노드값이 왼쪽자식과 오른쪽 자식노드의 값보다 크게 트리를 구성하는 것입니다.
그렇게 하면 트리의 루트(root)노드는 입력된 값들 중 가장 큰 값이 저장되어 있습니다. 
예를 들어 5 3 2 1 4 6 7순으로 입력되면 최대힙 트리는 아래와 같이 구성됩니다
   7
 4   6
1 3 2 5 

최대힙 자료를 이용하여 다음과 같은 연산을 하는 프로그램을 작성하세요.
1) 자연수가 입력되면 최대힙에 입력한다.
2) 숫자 0 이 입력되면 최대힙에서 최댓값을 꺼내어 출력한다.
(출력할 자료가 없으면 -1를 출력한다.) 3) -1이 입력되면 프로그램 종료한다.
*/

#include <iostream>
#include <queue>

using namespace std;

int main(){
    priority_queue<int> q; //기본적으로 가장 큰 값이 top();
    int tmp;
    while(1){
        cin >> tmp;
        if (tmp== -1) exit(0);
        else if (tmp== 0){
            if(q.empty()) {
                cout << "-1"; 
                exit(0);
            }
            else{
                cout << q.top() << endl;
                q.pop();
            }
        }
        else{
            q.push(tmp);
        }
    }
}