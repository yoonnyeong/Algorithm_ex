#include<cstdio>
#include<cstdlib>


using namespace std;
//상, 하, 좌, 우, 대각선 방향
int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

int map[100][100];

void testCase(int caseIndex) {
	
	int n, k;
	scanf("%d %d", &n, &k);
		// 2차원 배열 입력
		for(int i = 0 ; i < n; i++){
			for(int j =0; j < n; j++){ //증감식의 j를 실수로 i로 쓴 탓에 계속 timeout오류가 났었음
					scanf("%d", &map[i][j]);
			}
		}

	
	int answer = 0;
	//건설지점을 입력받고, 그 지점들을 중심으로 탐색
	for(int i = 0 ; i < k; i++){
			int r, c; // 입력받을 행, 열번호
		  scanf("%d %d", &r, &c);
	    r= r-1;
			c= c-1;
			int count = map[r][c];  //처음 건설지점의 값을 포함
			
			for(int d = 0; d < 8; d++){
					//각 방향에 대해서
				 for(int step = 1; step <= n; step++){
						 int nx = r + step * dx[d];
					 	 int ny = c + step * dy[d];
					   if( 0 > nx || nx >= n || 0 > ny || ny >=n) //범위를 초과하면 반복문 탈출
						   break;
	
					 count += map[nx][ny];
					}
			}
		
		if( answer < count){
			answer = count;
		}
	}
	
	printf("%d\n", answer);
}

int main() {
	
		int t;
		scanf("%d", &t);

		for (int caseIndex = 1; caseIndex <= t; caseIndex += 1) {
			testCase(caseIndex);
		}

	


	return 0;
}
