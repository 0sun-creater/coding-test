/*친구인가?
반학생들 n명. 각 학생들의 친구관계 알고싶어요
모든 학생 1~n
친구관계는 숫자쌍으로 주어짐
1,2 친구 2,3 친구 3,4 친구 면,
1,4도 2,3을 통해서 친구임

연결되어 있는 네트워크 찾기

특정 두명이 친구인지를 판별하는 프로그램 작성
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
    vector<vector<int> > fr;
    int n, m, tmp, tmp2;
    cin >> n >> m;

    
    for(int i =0; i<=n; i++){
        vector<int> temp;
        fr.push_back(temp);
    }
    for(int i =0; i< m; i++){
        cin >> tmp >> tmp2;
        fr[tmp].push_back(tmp2);
        fr[tmp2].push_back(tmp);
    }

    int start, end;
    cin >> start >> end;

    queue<int> q;

    bool visited[n+1];
    memset(visited, false, sizeof(visited));
    
    visited[start] =true;
    q.push(start);
    bool flag = false;
    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for(int i=0;i<fr[cur].size(); i++){
            if(fr[cur][i]==end) {
                flag = true;
                break;
            }
            if(visited[fr[cur][i]]== false){
                visited[fr[cur][i]] =true;
                q.push(fr[cur][i]);
            }
        }
        if(flag) break;
    }

    if(flag) cout << "YES";
    else{
        cout << "NO";
    }

    return 0;

}


/*
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int unf[1001];

int Find(int v){
	if(v==unf[v]) return v;
	else return unf[v]=Find(unf[v]);
}

void Union(int a, int b){
	a=Find(a);
	b=Find(b);
	if(a!=b) unf[a]=b;
}

int main(){
	freopen("input.txt", "rt", stdin);
	int i, n, m, a, b, fa, fb, j;
	scanf("%d %d", &n, &m);
	for(i=1; i<=n; i++){
		unf[i]=i;
	}
	for(i=1; i<=m; i++){
		scanf("%d %d", &a, &b);
		Union(a, b);
	}
	scanf("%d %d", &a, &b);
	fa=Find(a);
	fb=Find(b);
	if(fa==fb) printf("YES\n");
	else printf("NO\n");
	return 0;
}


*/