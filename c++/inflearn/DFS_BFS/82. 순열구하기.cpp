/*
n과 r이 주어지면 서로 다른 n개의 자연수 중 r개를 뽑아 일렬로 나열하는 프로그램 작성
DFS
*/

#include <iostream>
#include <vector>

using namespace std;

int n, r, tmp, cnt =0;
int numbers[21];
int result[21];
//순열은 한번 사용한건 다시 사용하지 않음 (중복x)
bool check[21];
void dfs(int cur){
    if(cur==r) {
        for(int i=0; i<cur; i++){
            cout << result[i] << " ";
        }
        cnt ++;
        puts("");
    }
    else{
        for(int i=1; i<=n; i++){
            if(check[i] == 0){
                check[i] = 1;
                result[cur] = numbers[i];
                dfs(cur+1);
                check[i] = 0;
            }
        }
    }
}

int main(){
    cin >> n >> r;

    for(int i=1; i<=n; i++){
        cin >> tmp;
        numbers[i] =tmp;
    }

    dfs(0);
    cout << cnt;
}

/*
#include<stdio.h>
using namespace std;
int n, r, cnt=0;
int a[20], res[20], ch[20];
void DFS(int L){
	if(L==r){
		for(int j=0; j<L; j++){
			printf("%d ", res[j]);
		}
		cnt++;
		puts("");
	}
	else{
		for(int i=1; i<=n; i++){
			if(ch[i]==0){
				res[L]=a[i];
				ch[i]=1;
				DFS(L+1);
				ch[i]=0;
			}
		}
	}
}

int main(){
	freopen("input.txt", "rt", stdin);
	scanf("%d %d", &n, &r);
	for(int i=1; i<=n; i++){
		scanf("%d", &a[i]);
	}
	DFS(0);
	printf("%d\n", cnt);
	return 0;
}
*/