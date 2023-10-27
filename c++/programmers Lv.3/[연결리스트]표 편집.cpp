/*
U : X칸 위에 행 선택
D : X칸 아래 행 선택
C : 현재 행 삭제 후 아래 행 선택 (가장 마지막행이면 바로 위 행 선택)
Z : 가장 최근에 삭제된 행을 복구함 (현재 선택된 행은 바뀌지 않음)

처음 표와 비교하여 삭제되지 않은 행은 o 삭제된 행은 x로 리턴
*/

//주의할 점 : z를 한번에 여러번 할 수도 있음 - 삭제한 걸 stack에 담아두자 > vector
//표의 범위 벗어나는 입력 없음, 삭제된 행이 없는데 z가 되는 경우 없음
//n: 행 갯수, k: 처음 행의 위치

//STL로 제공되는 list를 사용하면 문제가 해결되지 않는다...
//직접 연결 리스트를 구현할 수 있어야 풀 수 있는 문제
#include <string>
#include <vector>
#include <sstream>
#include <stack>
#include <algorithm>
using namespace std;

struct Node {
    int n;
    Node* prev;
    Node* next;
    Node(int n, Node* prev, Node* next) : n(n), prev(prev), next(next) {}
};

string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'O');
    stack<Node*> remove_table;

    Node* o = new Node(0, NULL, NULL);
    
    // 현재 가리키는 행
    Node* select = o;
    
    // 테이블 만들기
    for (int i = 1; i < n; i++) {
        o->next = new Node(i, o, NULL);
        o = o->next;
    }
    
    // k 번째 행을 가리키게 하기
    for (int i = 0; i < k; i++) { 
        select = select->next;
    }
    
    // 명령어 실행
    for (const auto& c : cmd) {
        if (c == "C") {
            remove_table.push(select);
            if (select->prev != NULL) {
                select->prev->next = select->next;
            }

            if (select->next != NULL) {
                select->next->prev = select->prev;
            }

            if (select->next == NULL) {
                select = select->prev;
            }
            else {
                select = select->next;
            }
        }
        else if (c == "Z") {
            Node* t = remove_table.top();
            remove_table.pop();

            if (t->prev != NULL) {
                t->prev->next = t;
            }

            if (t->next != NULL) {
                t->next->prev = t;
            }
        }
        else {
            int count = stoi(c.substr(2));

            if (c[0] == 'D') {
                for (int i = 0; i < count; i++) {
                    select = select->next;
                }
            }
            else {
                for (int i = 0; i < count; i++) {
                    select = select->prev;
                }
            }
        }
    }

    while (!remove_table.empty()) {
        answer[remove_table.top()->n] = 'X';
        remove_table.pop();
    }

    return answer;
}
/*시간 초과 + 문제 일부 맞음 
string solution(int n, int k, vector<string> cmd) {
    string answer(n, 'O');
    vector<pair<int, int>> ctrlz; //"이름" 열은 없음 당시idx, 가진숫자
	vector<int> change;
    for(int i=0; i<=n; i++){
        change.push_back(i);
    }
    for(auto c : cmd){
        
		if(c[0]== 'U'){
        	k -= (c[2]-'0');    
        }
        else if (c[0]=='D'){
            k += (c[2]-'0');
        }
        
        else if (c[0]=='C'){
            ctrlz.push_back({k, change[k]});
         	change.erase(change.begin()+k);
            if(k == int(change.size()) - 1) k -= 1;
        }
        
        else{//'Z'
            int z = int(ctrlz.size())-1;
            pair<int, int> zp = ctrlz[z];
            change.insert(change.begin()+zp.first, zp.second);
            ctrlz.pop_back();
            if(zp.first <= k) k+=1;
        }
        
        //cout << k << endl;

    }
    
    for(int i=0; i<int(ctrlz.size()); i++){
    	answer[ctrlz[i].first] = 'X';
    }
	
    
    return answer;
}*/