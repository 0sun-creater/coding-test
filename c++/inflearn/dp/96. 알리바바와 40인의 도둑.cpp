/*
알리바바와 40인의 도둑(Bottom-Up)
알리바바는 40인의 도둑으로부터 금화를 훔쳐 도망치고 있습니다.
알리바바는 도망치는 길에 평소에 잘 가지 않던 계곡의 돌다리로 도망가고자 한다. 
계곡의 돌다리는 N×N개의 돌들로 구성되어 있다. 각 돌다리들은 높이가 서로 다릅니다.
해당 돌다리를 건널때 돌의 높이 만큼 에너지가 소비됩니다. 
이동은 최단거리 이동을 합니다. 즉 현재 지점에서 오른쪽 또는 아래쪽으로만 이동해야 합니다.
N*N의 계곡의 돌다리 격자정보가 주어지면 (1, 1)격자에서 (N, N)까지 가는데 드는 에너지의 최소량을 구하는 프로그램을 작성하세요.
만약 N=3이고, 계곡의 돌다리 격자 정보가 다음과 같다면
3 3 5
2 3 4 
6 5 2
(1, 1)좌표에서 (3, 3)좌표까지 가는데 드는 최소 에너지는 3+2+3+4+2=14이다.
*/
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
    int n,tmp;
    cin >> n;
    int rock[21][21];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> tmp;
            rock[i][j] = tmp;
        }
    }
    for(int i=1; i<n; i++){
        rock[0][i] += rock[0][i-1];
        rock[i][0] += rock[i-1][0];
    }

    for(int i=1;i<n;i++){
        for(int j=1;j<n; j++){
            int mini = min(rock[i-1][j], rock[i][j-1]);
            rock[i][j] += mini;
        }
    }

    cout << rock[n-1][n-1];
}


/*
top-down
#include<bits/stdc++.h>
using namespace std;
int arr[21][21], dy[21][21];
int DFS(int x, int y){
	if(dy[x][y]>0) return dy[x][y];
	if(x==0 && y==0){
		return arr[0][0];
	}
	else{
		if(y==0) return dy[x][y]=DFS(x-1, y)+arr[x][y];
		else if(x==0) return dy[x][y]=DFS(x, y-1)+arr[x][y];
		else return dy[x][y]=min(DFS(x-1, y), DFS(x, y-1))+arr[x][y];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "rt", stdin);
	int n, cnt=0;
	cin>>n;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin>>arr[i][j];
		}
	}
	cnt=DFS(n-1, n-1);
	cout<<cnt;
	return 0;
}


*/