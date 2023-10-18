/*올바른 괄호(stack)
괄호가 입력되면 올바른 괄호이면 “YES", 올바르지 않으면 ”NO"를 출력합니다.
(())() 이것은 괄호의 쌍이 올바르게 위치하는 거지만, (()()))은 올바른 괄호가 아니다.
*/

#include <stack>
#include <iostream>

using namespace std;

int main(){
    string input;
    getline(cin, input);

    stack<char> s;

    for(int i =0; input[i]!='\0';i++){

        if(input[i] =='('){
            s.push('(');
        }
        else if(input[i] ==')'){
            if (s.empty()){
                cout << "NO";
                return 0;
            }
            s.pop();
        }
    }

    if(s.empty()) cout << "YES";
    else cout << "NO";

}