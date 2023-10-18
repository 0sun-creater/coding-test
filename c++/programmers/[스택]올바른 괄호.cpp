#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
	stack<char> st;
    
    for(int i =0; s[i]!='\0';i++){

        if(s[i] =='('){
            st.push('(');
        }
        else if(s[i] ==')'){
            if (st.empty()){
                return false;
            }
            st.pop();
        }
    }

    if(st.empty()) return true;
    else return false;


    return answer;
}