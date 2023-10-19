
//https://kbj96.tistory.com/15
#include <iostream>
#include <queue>

using namespace std;

int main(){
   priority_queue<int, vector<int>, greater<int> > q;
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