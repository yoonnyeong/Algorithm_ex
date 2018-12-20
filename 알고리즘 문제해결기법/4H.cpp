#include <stdio.h>
// 모든 배열에 대해 계산하지 않고, index와 x의 값이 같은 것에 대해서만 계산
int solution(int m, int n, int x, int y){
	  // x 좌표는 x = x+m = x= km 이므로 x에 대해 주기 m만큼 더하면서 계산
	  for(int index = x; index <= n*m; index += m){
			//Y의 좌표와 똑같다면 
			if(((index - 1) % n + 1)==y)
				return index;
		}
	return -1;  //유효하지 않은 표현
}

int main() {
int t; //테스트 케이스
scanf("%d", &t);
	for(int i = 0 ; i < t ; i++){
		int n, m, x, y;
		scanf("%d %d %d %d", &m, &n, &x, &y);
		int result = solution(m, n, x, y);		
		printf("%d\n", result);
	}
return 0;
}
