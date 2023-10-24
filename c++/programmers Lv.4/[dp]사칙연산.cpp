
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

const int INF = 987654321;
int solution(vector<string> arr)
{
    int minmax[2] = {0,0};
    int size = int(arr.size());
    int sum =0;
    int cnt =0;
	for(int i = size-1; i>-1; i--){
        if (arr[i] == "+") continue;
        else if (arr[i] == "-"){
            if(cnt==0){
                minmax[0] = -sum;
                minmax[1] = -sum;
                cnt++;
                
            }
            else{               
                // - 를 만났을때 식 전체에 - 붙일래? 하나에만 붙일래?
                //최소값 : - 방향으로 크게, -(sum+최대) or -(sum) + 최소
                //최대값 : + 방향으로 크게, -(sum+최소) or -(sum[0])+sum[1:]+최대
				int tmp_min = minmax[0];
                int tmp_max = minmax[1];
                minmax[0] = min(-(sum + tmp_max), -sum + tmp_min);
                int v = 0;
                if (i+1 != size) v= stoi(arr[i+1]);
                minmax[1] = max(-(sum + tmp_min), -v+(sum-v) + tmp_max);
            }
            sum = 0;
            
        }
        else if(stoi(arr[i])>=0){
            sum += stoi(arr[i]);
        }
    }
    minmax[1] += sum;
	return minmax[1];
}


/* 남 코드 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;

const int INF = 987654321;
const int MAX = 200 + 20;

int cache[MAX][MAX][2];
vector<int> numbers;
vector<string> ops;

void init(vector<string> arr){
	for (int i = 0; i < arr.size(); i++){
		if (i % 2 == 0){
			numbers.push_back(stoi(arr[i]));
		}
		else{
			ops.push_back(arr[i]);
		}
	}
}

int func(int start, int end, bool isMax){
	int &result = cache[start][end][isMax];

	if (result != -1) return result;
	if (start == end) return result = numbers[start];

	result = isMax ? -INF : INF;
	//(조건) ? A : B    조건이 맞으면 A 틀리면 B
	for (int i = start; i < end; i++){
		if (ops[i] == "-"){
			result = isMax ?
				max(result, func(start, i, true) - func(i + 1, end, false)) :
				min(result, func(start, i, false) - func(i + 1, end, true));
		}else{
			result = isMax ?
				max(result, func(start, i, true) + func(i + 1, end, true)) :
				min(result, func(start, i, false) + func(i + 1, end, false));
		}
	}
	return result;
}

int solution(vector<string> arr)
{
	init(arr);
	memset(cache, -1, sizeof(cache));

	return func(0, arr.size() / 2, true);
}

*/
