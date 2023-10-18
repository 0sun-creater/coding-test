//공주 구하기
//정보 왕국에는 왕자가 N명이 있는데 서로 공주를 구하러 가겠다고 합니다. 
//왕은 왕자들을 나이 순으로 1번부터 N번까지 차례로 번호를 매긴다. 
//그리고 1번 왕자부터 N 번 왕자까지 순서대로 시계 방향으로 돌아가며 동그랗게 앉게 한다.
//그리고 1번 왕자부터 시계방향으로 돌아가며 1부터 시작하여 번호를 외치게 한다.
//한 왕자가 K(특정숫자)를 외치면 그 왕자는 공주를 구하러 가는데서 제외되고 원 밖으로 나오게 된다.
//그리고 다음 왕자부터 다시 1부터 시작하여 번호를 외친다.
//이렇게 해서 마지막까지 남은 왕자가 공주를 구하러 갈 수 있다.
/*
k = 3, pos = 1 erase(begin+pos+k)
n = k-1 =2
1 2 '3' 4 5 6 7 8 1시작 3아웃  pos+n : 3 , pos = pos + n : 3
1 2 4 5 '6' 7 8 4시작 6아웃    pos+n : 5, pos = pos + n : 5
'1' 2 4 5 7 8 7시작 1아웃      pos+n : 7, size():7 같음 : pos+n = pos+n - cicle.size() +1, pos = pos +n : 1
2 4 '5' 7 8 2시작 5 아웃       pos+n : 3, pos = pos + n : 3
'2' 4 7 8 7시작 2아웃          pos+n : 5, size():5 같음 : pos+n = pos+n - cicle.size() +1, pos = pos+n : 1
4 7 '8' 4시작 8아웃            pos+n : 3, pos = pos +n : 3
4 7 4시작 4아웃                pos가 size보다 크면 pos = pos - size : 1
                            pos+n : 3, size():3 같음 pos+n = pos+n - cicle.size() + 1
7
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    vector<int> circle(n+1);
    for(int i= 1; i<=n; i++){
        circle[i] = i;
    }
    
    int e = k-1, _pos =1, pos;
    while(circle.size() > 2){
        pos = _pos+e; 
        if(pos == (int)circle.size()){
            pos = pos - circle.size() + 1;
        }
        if (pos > (int)circle.size()){
            pos = pos - circle.size() - 1;
        } 
        circle.erase(circle.begin() + pos);
        _pos = pos;

    }
    cout << circle[1];
}



/*
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	freopen("input.txt", "rt", stdin);
	int n, k, p=0, i, bp=0, cnt=0;
	scanf("%d %d", &n, &k);
	vector<int> prince(n+1);
	while(1){
		p++;
		if(p>n) p=1;
		if(prince[p]==0){
			cnt++;
			if(cnt==k){
				prince[p]=1;
				cnt=0;
				bp++;
			}
		}
		if(bp==n-1) break;
	}
	for(i=1; i<=n; i++){
		if(prince[i]==0){
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}







#include<stdio.h>
#include<vector>
using namespace std;
int main(){
	freopen("input.txt", "rt", stdin);
	int n, k, pos=0, i, cnt=0;
	scanf("%d %d", &n, &k);
	vector<int> prince(n+1);
	while(1){
		for(i=1; i<=k; i++){
			while(1){
				pos++;
				if(pos>n) pos=1;
				if(prince[pos]==0) break;
			}
		}
		prince[pos]=1;
		cnt++;
		if(cnt==n-1) break;
	}
	for(i=1; i<=n; i++){
		if(prince[i]==0){
			printf("%d\n", i);
			break;
		}
	}
	return 0;
}*/