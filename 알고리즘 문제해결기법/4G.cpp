#include <cstdio>

using namespace std;

int main(){
  int data[1000];
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
			scanf("%d", &data[i]);
	}
	
	int p = 0; //배열을 명령대로 옮겼을 때 첫 번째 원소가 저장된 위치
	for(int i = 0; i < m; i++){
		int op; //명령어 유형
		scanf("%d", &op);
    int k;
		if(op!=3){
			scanf("%d", &k);
		}
		if(op==0){  //출력
			 int output = data[(p+k)%n];
			 printf("%d\n", output);
		}
		else if(op==1){// 왼쪽 이동
			k = k % n; //이 부분을 꼭 넣어줘야 함
		 	p = (p + k) % n; //p는 n을 넘어가면 안되니까
		}
		else if(op==2){ // 오른쪽 이동 int k;	 	
			k = k % n;
			p = (p - k + n) % n;	//음수가 나올 경우를 고려하여 +
		}
		else if(op==3){
				p = 0; //초기 배열
		}
	}
	return 0;
}
