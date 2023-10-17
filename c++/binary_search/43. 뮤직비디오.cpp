//뮤직비디오(이분검색 응용)
/*지니레코드에서는 불세출의 가수 조영필의 라이브 동영상을 DVD로 만들어 판매하려 한다. 
DVD에는 총 N개의 곡이 들어가는데, DVD에 녹화할 때에는 라이브에서의 순서가 그대로 유지 되어야 한다. 순서가 바뀌는 것을 우리의 가수 조영필씨가 매우 싫어한다.
즉, 1번 노래와 5번 노래를 같은 DVD에 녹화하기 위해서는 1번과 5번 사이의 모든 노래도 같은 DVD에 녹화해야 한다.
지니레코드 입장에서는 이 DVD가 팔릴 것인지 확신할 수 없기 때문에 이 사업에 낭비되는 DVD를 가급적 줄이려고 한다.
고민 끝에 지니레코드는 M개의 DVD에 모든 동영상을 녹화하기로 하였다. 이 때 DVD의 크기(녹화 가능한 길이)를 최소로 하려고 한다.
그리고 M개의 DVD는 모두 같은 크기여야 제조원가가 적게 들기 때문에 꼭 같은 크기로 해야 한다.

라이브에서 부른 순서대로 부른 곡의 길이가 분 단위로 주어짐
dvd의 최소 용량 크기를 출력
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> arr;

int DVD_cnt(int dvd){ 
    int cnt =1, sum =0;
    for(int i =0; i<n; i++){ //모든 곡 탐색
        if(sum + arr[i] > dvd){ //arr[i] 곡은 불가
            cnt +=1; //새로운 dvd
            sum = arr[i];
        }
        else{
            sum += arr[i]; //가능 - 기존 dvd에 저장
        }
    }
    return cnt; //필요한 dvd 개수
}
int main(){
    int m, tmp, left=1, right=0, mid, max = -2147000000;
	cin >> n >> m;

	for(int i=0; i<n; i++){
		cin >> tmp;
		arr.push_back(tmp);
        right += tmp; 
        if(tmp > max) max = tmp;
	}
    int min_size = right;
    while(left<=right){
        mid = (left+right) / 2;
        if(max <= mid && DVD_cnt(mid) <= m){
            min_size = mid;
            right = mid-1;
        }
        else{
            left = mid+1; //답이 아님
        }

    }

    cout << min_size;

}