#include <cstdio>
#include <vector>

using namespace std;
int data[5000];
int check[5000];
int lucky[5000];
int main() {
	// n: 전체 티켓의 수
	// m: 요청 고객의 수
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
			scanf("%d", &data[i]);
	}
	//행운권의 번호를 부여하기
  for(int i = 0; i < m; i++){ // m개의 데이터에 대해서만 
			int num = data[i] % n;  // 나머지를 계산해서 그방에 넣을 것
		  
			if(check[num]==0){ //아직 안넣은 곳이니까 번호를 넣어줘도 됌.
					lucky[i]= num;
				  check[num]++;
			}
		  else if(check[num]==1){ // 이미 들어간 방이라면, 다시 방번호를 계산
				// num++ 만 하지않고, % n을 하는 이유는 순환하는 방식으로 조회 (NUM이 N을 넘어갔을때)
				num = (num + 1) % n; 
				while(check[num]!=0){ //num이 0이면 빠져나와야함
							num = (num + 1) % n;
				}
				lucky[i]= num;
				check[num]++;
			}
	
	}
						
	for(int i = 0 ; i < m; i++){
			printf("%d\n", lucky[i]);
	}
}
