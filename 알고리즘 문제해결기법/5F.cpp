#include <iostream>
#include <stdio.h>
using namespace std;
//이동해야하니까 방향 배열이 필요함
int dx[] ={0,1,0,1,0,-1};
int dy[] ={1,0,-1,0,1,0};
int map[101][101];

void  testcase(int n){
	
	
	//배열을 초기화
	for(int i= 0; i <n; i++){
		for(int j=0; j<n; j++){
			map[i][j]=0;
		}
	}
	int cr = 0; //처음 행
	int cc = 0; // 처음 열
	int cdir = 0; // 처음의 방향
	int count = 0; // i,j에 들어갈 값
	// 전체 레벨에 대하여
	for(int level = 1; count < n*n ; level++){
			//레벨마다 3개의 방향
		  for(int i = 0; i < 3; i++){
						int length = 1; // level 마다 방향을 반복해야하니까 변수 선언
						
						if( i > 0) //첫번째만 1번 도니까, 그 이후는 length만큼 돌아야한다.
							length = level;
						
						// 그 방향에 대해 length 만큼 돌아서 수를 채워줌
						for(int j = 0; j <length; j++){
								count++;
								map[cr][cc] = count;
								//그다음 좌표를 미리 계산  
								cr = cr + dx[cdir];
							  cc = cc + dy[cdir];
			
						}
						if(count > n*n)  break;		
							// 방향 바꿔주기
				      cdir = (cdir + 1) % 6;
			} // 세개 방향 끝나는 곳
		 if(count > n*n)
			 break;
		
	
	}
	for(int i = 0; i < n; i++){
			for(int j =0; j < n; j++){
					if(j>0)
						printf(" ");
					printf("%d", map[i][j]);
			}
		printf("\n");
	}
}

int main() {
  int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
			int n;
		  scanf("%d", &n);
			testcase(n);
	}
  return 0;
}
