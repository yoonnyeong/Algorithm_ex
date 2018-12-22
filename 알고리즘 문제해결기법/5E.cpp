#include <iostream>
#include <stdio.h>
using namespace std;
//우, 하, 좌, 상
/*
규칙에 맞게 배열을 채운 후, 그 배열을 출력
*/
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int map[100][100];

int main() {
	int t;
	scanf("%d", &t);
	for(int i = 0 ; i < t; i++){
		 int n ;
		 scanf("%d", &n);
		 // n*n만큼 
		int r =0; int c=0; //맨처음 행과 열
	  int position = 0; // 방향정보
		
		//배열을 전부 초기화
		for(int i =0; i<n; i++){
			for(int j= 0; j <n; j++){
				map[i][j]=0;
			}
		}
		for(int i = 1; i <= n*n; i++){
				// 다음에 받을 위치를 미리 계산
				int nextR = r + dx[position];
			  int nextC = c + dy[position];
				//위치는 i가 되어야함 
				map[r][c] = i; 
			  if(nextR < 0 || nextC < 0 || nextR >= n || nextC >= n || map[nextR][nextC] !=0)
					 position = (position + 1) % 4;
		    // r과 c를 바꿔줘야함
			  r= r+ dx[position];
				c= c+ dy[position];
		}
		//출력
		for(int i =0; i<n; i++){
			for(int j= 0; j <n; j++){
				if(j>0){
					printf(" ");
				}
					printf("%d", map[i][j]);
			}
			cout << endl;
		}
	
	}
  return 0;
}
