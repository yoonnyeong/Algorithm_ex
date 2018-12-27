#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
// 세 방향에 대해 정의 오른쪽, 대각선, 아래
int dx[] ={0, 1, 1};
int dy[] ={1, 1, 0};

void test_case(){
		int n;
		scanf("%d", &n);
		char P[101];
		scanf("%s", P);
		//P의 길이
	  int plen = (int)strlen(P);
		char puzzle[101][101];
	
		for(int i = 0; i < n; i++){
				scanf("%s", puzzle[i]);
		}
		//모든 row, col에 대해서
		int answer = 0;
		for(int row = 0; row < n; row++){
				for(int col = 0; col < n; col++){
					// 세 방향을 탐색
					for(int dir = 0; dir < 3; dir++){
								int lastRow = row + (plen-1) * dx[dir]; // plen의 길이만큼 
								int lastCol = col + (plen-1) * dy[dir]; 
						    
								// 끝의 행, 열이 puzzle을 벗어날 경우에는, 다른 방향에 대해 탐색
								if(lastRow >= n || lastCol >= n) continue;
								
								int matchCount = 0;
								
									for(int i = 0; i < plen; i++){
										// 다음 칸 계산, 
										int targetRow = row + i * dx[dir];
										int targetCol = col + i * dy[dir];
									
										char word = puzzle[targetRow][targetCol];
									  if( word != P[i]) break;
									  else matchCount++;
								  }
								if(matchCount == plen) answer+=1;
						}
				
				}
		}
		printf("%d\n", answer); 
}



int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
			test_case();
	}
	return 0;
}
