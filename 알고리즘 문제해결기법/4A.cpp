/*
스도쿠 보드
그룹번호 구하는게 핵심
행, 열을 구분해서 1~9까지 그룹번호가 어떻게 변화하는지
행   1 2 3 4 5 6 7 8 9 
그룹 1 1 1 4 4 4 7 7 7 

열    1 2 3 4 5 6 7 8 9 
그룹  1 1 1 2 2 2 3 3 3 
*/
#include <cstdio>

using namespace std;

int data[100];
int main() {
 int n;
 scanf("%d", &n);
 for(int i = 0 ; i < n; i++){
 		scanf("%d", &data[i]);
 }
	
	int row = 0;  //행
	int col = 0; // 열
	int group = 0;
	for(int i = 0; i < n; i++){
	
		row = (data[i]-1) / 9 + 1;
		col =  (data[i]-1) % 9 + 1;
		int left = ((row-1)/3)*3 + 1;
		int offset = (col-1)/3;
		group = left + offset;
		
	//케이스 번호 출력
	printf("Case #%d:\n", i+1);
  printf("%d %d %d\n", row, col, group);
	}
}
