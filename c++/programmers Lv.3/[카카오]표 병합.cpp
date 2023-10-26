#include <string>
#include <vector>
#include <iostream>
#include <sstream>

//구현
using namespace std;
//표의 크기는 50 50 고정
string table[51][51];
int merge_table[51][51];
vector<string> solution(vector<string> commands) {
    vector<string> answer;
	fill(&table[0][0], &table[50][51], "EMPTY");
    int merge_cnt = 0;
    for(auto command : commands){
        //string 자르기
        vector<string> c;
        istringstream iss(command);
        string str_buf;
        while(getline(iss, str_buf, ' ')){
            c.push_back(str_buf);
        }
        
        if(c[0] == "UPDATE"){
            //update r c value
            if(int(c.size())==4){
                int up = -1;
                int r1 = stoi(c[1]);
                int c1 = stoi(c[2]);
                //머지가 되어있을 때
                if(merge_table[r1][c1] != 0){
                    up = merge_table[r1][c1];
                    for(int i=0; i<51; i++){
                        for(int j=0; j<51; j++){
                            if(merge_table[i][j] == up){
                                table[i][j] = c[3];
                            }
                        }
                    }
                }
                //머지가 안되어 있을 때
                else{
                	table[r1][c1] = c[3];
                }

            }
            //update value1 value2
            else{    
                for(int i=0; i<51; i++){
                    for(int j=0; j<51; j++){
                        if(table[i][j] == c[1]){
                            table[i][j] = c[2];
                        }
                    }
                }
            }
    	}
        
        if(c[0] == "MERGE"){
            int r1 = stoi(c[1]);
            int c1 = stoi(c[2]);
            int r2 = stoi(c[3]);
            int c2 = stoi(c[4]);
            //같은 셀일 경우 무시
            if(r1 == r2 && c1 == c2) continue;
            
            int mcnt =0;
            int flag =0;
            //한쪽이 머지되어 있는 그룹일 경우
            if(merge_table[r1][c1] !=0 && merge_table[r2][c2] ==0){
                //한쪽 머지 숫자를 저장
                mcnt =merge_table[r1][c1];
            }
            else if(merge_table[r2][c2] !=0 && merge_table[r1][c1] ==0){
                mcnt =merge_table[r2][c2];
            }
            else if (merge_table[r1][c1] !=0 && merge_table[r2][c2] !=0){
                //둘다 머지되어있는 그룹일 경우
                mcnt =merge_table[r1][c1];
                flag =merge_table[r2][c2];
            }

            else{
                merge_cnt +=1;
                mcnt = merge_cnt;
			}                                              
            
            //한쪽이 머지되어 있거나 둘다 머지가 되어 있지 않을 때
            merge_table[r1][c1] = mcnt;
            merge_table[r2][c2] = mcnt;
            
            
            //두 셀 중 한 셀이 값을 가지고 있을 경우 병합된 셀은 그 값을 가지게 됩니다.
            string mer;
            if(table[r1][c1] == "EMPTY" && table[r2][c2] != "EMPTY") {
                mer = table[r2][c2];
            }
            else if(table[r2][c2] == "EMPTY" && table[r1][c1] != "EMPTY"){
                mer = table[r1][c1];
            }
            //두 셀 모두 값을 가지고 있을 경우 병합된 셀은 (r1, c1) 위치의 셀 값을 가지게 됩니다.
            else{ 
                mer = table[r1][c1];
            }
            
            for(int i =0; i<51; i++){
                for(int j=0; j<51; j++){
                    if(merge_table[i][j] == mcnt){
                        table[i][j] = mer;
                    }
                }
            }
        
            //둘다 그룹일 경우 mcnt와 mer를 바꿔주어야함
        	if(flag > 0){
                for(int i =0; i<51; i++){
                    for(int j=0; j<51; j++){
                        if(merge_table[i][j] == flag){
                            table[i][j] = mer;
                            merge_table[i][j] = mcnt;
                    	}
               		}
            	}
            }

        }
        
        //해당 셀의 모든 병합을 해제한다.
        if(c[0] == "UNMERGE"){
            int r1 = stoi(c[1]);
            int c1 = stoi(c[2]);
            
            int mcnt = merge_table[r1][c1];
            //머지가 안되어있으면 무시
            if(mcnt == 0) continue; 
            for(int i=0; i<51; i++){
                for(int j=0; j<51; j++){
                    if(merge_table[i][j]== mcnt) {
                        merge_table[i][j] = 0;
                        if(i==r1 && j == c1) continue; //r1,r1위치에는 셀의 그 값을 저장
                        table[i][j] = "EMPTY"; 
                    }
                }
            }
        }
        
        if(c[0] == "PRINT"){
            int r1 = stoi(c[1]);
            int c1 = stoi(c[2]);
            answer.push_back(table[r1][c1]);
        }
    }
    return answer;
}