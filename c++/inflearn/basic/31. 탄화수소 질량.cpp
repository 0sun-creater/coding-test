//탄화수소 질량
//탄소(C)와 수소(H)로만 이루어진 화합물을 탄화수소라고 합니다.
//탄소(C) 한 개의 질량은 12g, 수소(H) 한 개의 질량은 1g입니다. 에틸렌(C2H4)의 질량은 12*2+1*4=28g입니다.
//메탄(CH4)의 질량은 12*1+1*4=16g입니다.
//탄화수소식이 주어지면 해당 화합물의 질량을 구하는 프로그램을 작성하세요.
//식의 형태는 CaHb 형태이며 (1<=a, b<=100)이다. 
//단 a 나 b 가 1이면 숫자가 식에 입력되지 않는다. 

#include <iostream>
#include <string>
using namespace std;

int main(){
    string input;
    cin >> input;
    int result =0;
    if(input[1] != 'H'){
        result += 12*(input[1]-48);
    }
    else{
        result += 12;
    }

    if(input.length() ==3 && input[2] == 'H'){
        result +=1;
    }
    else if (input.length() == 3){
        result += input[2] -48;
    }
    else{
        
        result += input[3]- 48;
    }

    cout << result;
}
