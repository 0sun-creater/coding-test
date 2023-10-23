/*
위상정렬은 어떤 일을 하는 순서를 찾는 알고리즘입니다.
각각의 일의 선후관계가 복잡하게 얽혀있을 때 각각 일의 선후관계를 유지하면서 전체 일의 순서를 짜는 알고리즘입니다.
만약 아래와 같은 일의 순서를 각각 지키면서 전체 일의 순서를 정한다면
1 4 //1번일을 하고 난 후 4번일을 해야한다.
5 4
4 3
2 5
2 3
6 2
전체 일의 순서는 1 6 2 5 4 3
여러가지가 있을 수 있음 ~
*/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int n, m, a, b, score;
	cin>>n>>m;
	vector<vector<int> > graph(n+1, vector<int>(n+1, 0));
	vector<int> degree(n+1);
	queue<int> Q;
    //입력
    //degree 카운트 만큼 앞에 해야할 일이 있음
	for(int i=0; i<m; i++){
		cin>>a>>b;
		graph[a][b]=1;
		degree[b]++;
    }
    //제일 처음으로 할 수 있는 일은 degree가 0인 일
	for(int i=1; i<=n; i++){
		if(degree[i]==0) Q.push(i);
	}

	while(!Q.empty()){
		int now=Q.front();
		Q.pop();
		cout<<now<<" ";
		for(int i=1; i<=n; i++){
			if(graph[now][i]==1){ //연결되어있으면 degree 하나 빼주기
				degree[i]--;
				if(degree[i]==0) Q.push(i); //앞에 해야할일을 다했으면 나도 할수있음
			}
		}
	}
	return 0;
}





