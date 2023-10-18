//석차 구하기
//N명의 학생의 수학점수가 입력되면 각 학생의 석차를 입력된 순서대로 출력하는 프로그램을 작성하세요.

#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n,tmp;
    cin >> n;
    vector<int> student;
    int *rank = new int[n];
    for (int i =0; i <n;i++){
        cin >>tmp;
        student.push_back(tmp);
        rank[i] = 1;
    }

    //BF 동점자도 동일 석차일 때 가능
    for (int i =0 ; i< n; i++){
        for (int j =0; j<n; j++){
            if (student[i] < student[j]){
                rank[i] +=1;
            }
        }
    }

    for (int i =0 ; i < n; i++){
        cout << rank[i] <<" ";
    }



}