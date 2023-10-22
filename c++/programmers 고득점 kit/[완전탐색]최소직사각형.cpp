#include <string>
#include <vector>

using namespace std;

//모든 명함을 수납할 수 있는 가장 작은 크기 (가로 * 세로)
//명합을 눕혀서 넣는 것도 포함
int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int maxi=-1;
    vector<int> h;
    vector<int> w;
    for(int i =0; i< int(sizes.size());i++){
        vector<int> s = sizes[i];
        
        maxi = max(s[0],s[1]);
        if(maxi == s[0]) {
            h.push_back(s[0]);
            w.push_back(s[1]);
        }
        else{
            h.push_back(s[1]);
            w.push_back(s[0]);
        }
    }
    
    int maxh=-1, maxw=-1;
    for(int i=0; i<int(h.size());i++){
        if (maxh < h[i]) maxh = h[i];
    }

    for(int i=0; i<int(w.size()); i++){
        if(maxw < w[i]) maxw = w[i];
    }
    
    answer = maxh * maxw;

    return answer;
}