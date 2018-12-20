//팬미팅 문제 := 배열
#include <cstdio>
 
using namespace std;
//배열이 전역변수로 선언될 때에는 모든 값이 0으로 초기화 
// but 지역변수로 선언될 때에는 그 값이 어떤 값으로 초기화 될지 모름
int data[2000000];
int birth[1000000];

int main(){
//n,k 입력받음
	int n,k;
	scanf("%d %d", &n, &k);
	//생일을 입력 받음
	for(int i = 0 ; i < n; i++){
			scanf("%d", &data[i]);
	}
	
	int cnt=0; // 그룹이 k개 만큼 묶였는지 확인해줄 변수
	int answer=0; //중복 없이 n개중 k개를 선택할 수 있는 경우의 수
	for(int i = 0; i < n; i++){
			int d = data[i]; // 생일을 하나 꺼내옴
			birth[d]++; // 빈도수를 1 증가
			//빈도수를 1증가시켰는데 1이라면, 0 -> 1로 바뀐애
		 if(birth[d]==1){
		 			cnt++; // 포함될 수를 1증가시킴
		 }
		
		 //옮겨줘야될때 왼쪽꺼는 하나삭제, 오른쪽꺼 하나 추가
		if(i >= k){
			int rb = data[i-k];
			birth[rb]--;
			if(birth[rb]==0){ //삭제한 후, 0이된거면 기존에 하나있었다는 것
					cnt--; //그룹에서 빼준다.
			}
		}
		// k개가 완성되었을 때
		if(i >= k-1){
				if(cnt==k){
					answer++;
				}
		}
	
	
	}
printf("%d", answer);
return 0;
}
