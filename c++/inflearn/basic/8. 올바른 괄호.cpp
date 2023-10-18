//올바른 괄호
//괄호가 입력되면 올바른 괄호이면 “YES", 올바르지 않으면 ”NO"를 출력합니다.
//(())() 이것은 괄호의 쌍이 올바르게 위치하는 거지만, (()()))은 올바른 괄호가 아니다.

#include <iostream>
#include <string>

using namespace std;
int main(){
    string input;
    getline(cin, input);
    int result = 0;

    int open=0, close =0;
    for (int i =0; i < input.length(); i++){
        if (input[i] == '('){
            open +=1;
        }
        else if (input[i] == ')'){
            close +=1;
        }

        if (open < close){
            result = 1;
            break;
        }

    }

    if (result == 1){
        cout << "NO";
    }
    else if (open != close){
        cout << "NO";
    }
    else{
        cout << "YES";
    }


}