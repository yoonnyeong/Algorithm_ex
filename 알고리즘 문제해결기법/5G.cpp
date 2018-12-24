#include <iostream>
#include <stdio.h>
using namespace std;
//방향
int dx[4] = {0,1,1,-1};
int dy[4] = {1,-1,0,1};
int map[101][101];

void testcase(){
		int n;
		scanf("%d", &n);
		for(int i = 0;  i < n; i++){
				for(int j=0; j <n; j++){
						map[i][j]=0;
				}
		}
	int lastIndex = n*n;
	int cr =0;
	int cc = 0;
	int cdir =0;
	
	for(int i = 1;  i<= lastIndex; i++){
		
			// 지금 내가 있는 칸의 숫자를 채워 넣는다.
			map[cr][cc] = i; 

			if(i == lastIndex) {
				break;
			}
			 int nr =  cr + dx[cdir];
			 int nc =  cc + dy[cdir];		
			while(true){ 
				//범위안에 든다면 종료
				if( nr >=0 && nc >= 0 && nr < n && nc < n && map[nr][nc]==0){
					break;
				}
				//범위 밖이라면, 방향을 다시 계산해준다. -> if문을 다시 체크
				cdir = (cdir + 1) % 4;
				nr =  cr + dx[cdir];
			  nc =  cc + dy[cdir];		
			}
			//실제로 그 칸으로 말을 옮긴다. -> 변수를 잘못 선언해서 계속 오류
			cr = nr;
			cc = nc;

			//이번에 말을 옮길 방향이 아래나, 오른쪽이라면 (1번씩만 실행되어야하므로 옮겨준다.)
			if(cdir==0 || cdir ==2){
				cdir = (cdir + 1) % 4;}
		 }
	
	
	
		//전체 출력
		for(int i = 0;  i < n; i++){
				for(int j=0; j <n; j++){
					 if(j>0) printf(" ");
					 printf("%d", map[i][j]);
					
				}
			printf("\n");
		}
	
}
int main() {
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t; i++){
			testcase();
	}
  return 0;
}

