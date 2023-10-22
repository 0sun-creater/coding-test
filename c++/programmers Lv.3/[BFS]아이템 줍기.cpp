#include <string>
#include <vector>
#include <queue>

using namespace std;
//외곽은 1로
//안쪽은 0으로

int solution(vector<vector<int> > rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    int mapp[110][110];
    //1,3,7,8
    //map 사이즈를 2배 키워야 중간에 겹치는 경우가 없게 된다.
    characterX *= 2, characterY *= 2, itemX *= 2, itemY *= 2;
    //2,6,14,16

    int x1, x2, y1, y2;
    
    for(int i =0; i < int(rectangle.size()); i++){ //사각형의 갯수만큼
        for(int j =0; j < int(rectangle[0].size()); j++){ //좌표위치 2배 키우기
            rectangle[i][j] = rectangle[i][j]*2;
        }    
        x1 = rectangle[i][0], y1 = rectangle[i][1]; //좌측 하단
        x2 = rectangle[i][2], y2 = rectangle[i][3]; //우측 상단
       
        //사각형 전부 1로 채우기
        for(int k =x1; k<=x2; k++){
            for(int l =y1; l<=y2; l++){
                mapp[k][l] = 1;
            }
        }
    }
    
    //0으로 채우기 (나중에 해야돼)
    for(int i =0; i < int(rectangle.size()); i++){ 
        x1 = rectangle[i][0], y1 = rectangle[i][1]; //좌측 하단
        x2 = rectangle[i][2], y2 = rectangle[i][3]; //우측 상단 

        for(int k =x1+1; k<x2; k++){
            for(int l =y1+1; l<y2; l++){
                mapp[k][l] =0;
            }
        }
    }
    queue<pair<int, int>> q;
    q.emplace(characterX, characterY);
    int dx[4] = {-1,0,0,1};
    int dy[4] = {0,-1,1,0};
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(mapp[nx][ny] == 1){
                q.emplace(make_pair(nx,ny));
                mapp[nx][ny] = mapp[x][y] + 1;
            }
        }
        
    }
    
    answer = mapp[itemX][itemY] /2;
        
    return answer;
}