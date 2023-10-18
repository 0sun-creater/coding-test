/*
기차운행(stack 응용)
A도시에서 출발한 기차는 B도시로 도착한다. 
그런데 도로 중간에 T자형 교차로가 있어 출발한 기차의 도착 순서를 조정할 수 있다.

교차로에서는 다음과 같은 두 개의 작업을 합니다.
P(push)작업 : A도시에서 오는 기차를 교차로에 넣는다.
O(out)작업 : 교차로에 들어온 가장 최근 기차를 B도시로 보낸다.
만약 2 1 3 기차 번호 순으로 A도시에서 출발하더라도 B도시에는 T교차로를 이용하여 1 2 3 순으로 도착하게 할 수 있습니다.
그 작업 P, P, O, O, P, O순으로 작업을 하면 B도시에 1, 2, 3 순으로 도착합니다.
1부터 N까지 번호를 가진 기차가 A도시에서 어떤 순으로 출발하든, B도시에 번호순으로 도착 하도록 하는 교차로 작업을 출력합니다. 
모든 기차는 교차로에 들어가야만 B도시로 갈 수 있 습니다. 
번호 순서대로 도착이 불가능하면 impossible 이라고 출력합니다.
*/

#include <stack>
#include <iostream>
#include <string>

using namespace std;

int main(){
    int n,tmp;
    cin >> n;
    string result = "";
    stack<int> s;
    int pos=1;
    for(int i=0; i <n; i++){
        cin >> tmp;
        s.push(tmp);
        result += "P";
        cout << result;
        while(!s.empty()) {
            if(pos == s.top()){
                s.pop();
                result += "O";
                pos ++;
            }
        }

    }
    if (!s.empty()) cout << "impossible";
    cout << result;
    
    

}

/*
5
2 1 5 4 3
PPOOPPPOOO
7
3 2 4 7 6 5 1
impossible
30
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 
POPOPOPOPOPOPOPOPOPOPOPOPOPOPOPOPOPOPOPOPOPOPOPOPOPOPOPOPOPO
30
2 1 26 4 3 5 16 15 14 13 12 11 10 9 8 7 6 25 19 18 17 20 21 22 23 24 29 28 27 30  
PPOOPPPOOPOPPPPPPPPPPPOOOOOOOOOOOPPPPOOOPOPOPOPOPOOOPPPOOOPO
30
30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 
PPPPPPPPPPPPPPPPPPPPPPPPPPPPPPOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
*/