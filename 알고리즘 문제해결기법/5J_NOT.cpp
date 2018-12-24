#include <iostream>
#include <stdio.h>
/*청소를 하면 1로 바꿔주고 청소를 안한상태는 0*/
using namespace std;
// 위, 아래, 왼, 오
int dx[] ={-1, 1, 0, 0};
int dy[] ={0, 0, -1, 1};

int map[101][101];

void test_case(){
	
	 int n, k;
   scanf("%d %d", &n, &k);
	 //배열 초기화
	 for(int i = 0; i <n; i++){
	  for(int j = 0; j <n; j++)
			map[i][j]=0;
	 }
	
	 int r, c; // 초기 로봇청소기의 위치 
	 scanf("%d %d", &r, &c);
	 //하나씩 빼줘야함
	 r= r-1;
	 c= c-1;
	 int count = 0; // 초기에 청소한 위치 
	 //k개의 명령어를 입력받음
	 bool turnOn = true;
	 for(int i = 0;  i < k; i++){
			int d, l;
		 	// 입력받을 방향
		  scanf("%d %d", &d, &l);
		 	//이미 로봇이 동작을 정지했다면 다음 명령들은 그냥 스킵한다
			if (turnOn == false)
			{
					continue; // 현재의 반복문을 일찍 종료 하고자 할 때 사용
			}
		  // 처음 명령어 시작, l만틈 이동
		 	for(int j = 0; j < l; j++){
					count++;
				 	
				  map[r][c] = 1;
		
					// 다음에 갈 위치를 미리 계산
					int nr = r + dx[d-1];
				  int nc = c + dy[d-1];
				
					//다음에 갈 위치가 범위를 초과할 경우, 또는 이미 청소가 되어있을 경우
				  if( nr < 0 || nc < 0 || nr >= n || nc >= n || map[nr][nc] !=0)
					{ //가장 안쪽 for문만 탈출함
						 turnOn = false;
						 break; //반목문을 탈출
					}
				  r = nr;
				  c = nc;
		 	}
		
				
	}
		
	//청소한 것을 출력
	printf("%d\n", count);
}

int main() {
	int t; 
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
			test_case();
	}
  return 0;
}
