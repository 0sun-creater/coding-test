/*
이항계수
n개의 원소를 가지는 집합에서 r개의 원소를 뽑아 부분집합을 만드는 경우의 수
공식은 nCr

*/

#include <iostream>
using namespace std;

int dy[21][21];

int C(int n, int r){
	if(dy[n][r]>0) return dy[n][r];
	if(n==r || r==0) return 1;
	else return dy[n][r]=C(n-1, r)+C(n-1, r-1);
}

int main(){
    int n, r;
    cin >> n >> r;
    cout << C(n,r);
}