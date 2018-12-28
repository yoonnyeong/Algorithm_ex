#include <stdio.h>
#include <set>
using namespace std;

int main() {
	int n; 
	scanf("%d", &n);
	
	set<int> integers;
	
	for(int i = 0; i < n; i++){
			int x; 
		  scanf("%d", &x);
			
		
			// set 컨테이너 안에 x가 존재 하지 않는다면, end()를 반환하게 된다.
			if(integers.find(x) != integers.end()){ //이미 있는 숫자이므로, duplicated를 출력
					printf("DUPLICATED\n");
			}
		  else{ //존재하지 않는 수라면, 새로 컨테이너에 추가해준 후, ok를 출력
				integers.insert(x);
				printf("OK\n");
			}	
	}
	return 0;
}
