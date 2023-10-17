//Least Recently Used(카카오 캐시 문제 변형)

//철수의 컴퓨터는 캐시메모리 사용 규칙이 LRU 알고리즘을 따 른다.
//LRU 알고리즘은 Least Recently Used 의 약자로 직역하자면 가장 최근에 사용되지 않은 것 정도의 의미를 가지고 있습니다.
//캐시에서 작업을 제거할 때 가장 오랫동안 사용하지 않은 것을 제거하겠다는 알고리즘입니다.
//2 3 1 6 7 순으로저장
//1) Cache Miss : 해야할 작업이 캐시에 없는 상태로 위 상태에서
// 만약 새로운 작업인 5번 작 업을 CPU가 사용한다면 Cache miss가 되고 모든 작업이 뒤로 밀리고 5번작업은 캐시의 맨앞에위치한다.(7번작업은캐시에서삭제된다.)
//2) Cache Hit : 해야할 작업이 캐시에 있는 상태로 위 상태에서 만약 3번 작업을 CPU가 사용
//한다면 Cache Hit가 되고, 3번 앞에 있는 5, 2번 작업은 한 칸 뒤로 밀리고, 3번이 맨 앞으로
//위치하게 된다. 5 2 3 1 6 ---> 3 5 2 1 6

//캐시의 크기가 주어지고, 캐시가 비어있는 상태에서 N개의 작업을 CPU가 차례로 처리한다면 
//N개의 작업을 처리한 후 캐시메모리의 상태를 가장 최근 사용된 작업부터 차례대로 출력하는 프로그램을 작성하세요.

/*
assign() : 데크에 원소를 집어넣는다.
ex) 3의 값으로 4개의 원소 할당

dq.assign(4, 3);
push_back() : 데크 끝에 원소를 집어 넣는다.
push_front() : 데크 맨 앞에 원소를 집어 넣는다.
pop_back() : 마지막 원소 제거
pop_front() : 첫번째 원소를 제거
insert() : 데크 중간에 원소 추가
deque.insert(n, item)	n번 index에 원소를 추가한다.
erase() : 원소 제거
swap() : 다른 데크와 바꿔치기
clear() : 원소를 모두 제거

*/
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main(){
    int size, n, cur;
    cin >> size >> n;
    
    deque<int> cash(size);
    for(int i =0; i<n; i++){
        cin >> cur;
        deque<int>::iterator it = find(cash.begin(), cash.end(), cur);
        if(it!=cash.end()){ //값이 있으면 Hit
            it = cash.erase(it);
            cash.push_front(cur); 
        }
        else{ //값이 없으면 Miss
            cash.push_front(cur);
        }
    }
    for(int i =0; i<size;i++){
         printf("%d ", cash[i]);
    }

}


/*
삽입정렬 스타일
#include <stdio.h>
int C[20];
int main() {
	freopen("input.txt", "rt", stdin);
	int s, n, a, i, j, pos;
	scanf("%d %d", &s, &n);
	for(i=1; i<=n; i++){
		scanf("%d", &a);
		pos=-1; 
		for(j=0; j<s; j++) if(C[j]==a) pos=j;
		if(pos==-1){
			for(j=s-1; j>=1; j--) C[j]=C[j-1];
		}
		else{
			for(j=pos; j>=1; j--) C[j]=C[j-1];
		}
		C[j]=a;
	}
	for(i=0; i<s; i++) printf("%d ", C[i]);
	return 0;
}


*/