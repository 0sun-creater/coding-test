//이분검색
//임의의 N개의 숫자가 입력으로 주어집니다.
//N개의 수를 오름차순으로 정렬한 다음 N개의 수 중 한 개의 수인 M이 주어지면
//이분검색으로 M이 정렬된 상태에서 몇 번째에 있는지 구하는 프로그램을 작성하세요.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n, i, key, lt=0, rt, mid, tmp;
	cin >> n >> key;
	vector<int> arr;
	for(i=0; i<n; i++){
		cin >> tmp;
		arr.push_back(tmp);	
	}
	sort(arr.begin(), arr.end());
    
	rt=n-1;
	while(lt<=rt){
		mid = (lt+rt)/2;
		if(arr[mid]==key){
			cout << mid+1;
			return 0;
		}
		else if(arr[mid]>key) rt = mid - 1;
		else lt = mid + 1;
	}
	return 0;
}