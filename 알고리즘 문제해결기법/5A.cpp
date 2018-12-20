#include<cstdio>
#include<cstdlib>
#include<memory.h>
#include<iostream>
#include<algorithm>


using namespace std;


int get_minimum_trashes(int **waste, int N, int K) {
 int answer = K * K; // answer은 최소값이 되어야하므로, 가질 수 있는 최대 값으로 설정 (전부다 폐기물일 경우)
 for (int firstRow = 0; firstRow + K - 1 < N; firstRow += 1) {
			for (int firstCol = 0; firstCol + K - 1 < N; firstCol += 1) {
				int lastRow = firstRow + K - 1; 
				int lastCol = firstCol + K - 1;
				// 범위안에서의 최소 폐기물을 계산
				int cnt = 0;
		 for (int r = firstRow; r <= lastRow; r += 1) {
					for (int c = firstCol; c <= lastCol; c += 1) {
							if(waste[r][c]==1) //폐기물이라면
									cnt++;
					}
			}
			//cnt가 더 작다면,
		  if(answer > cnt){
			   answer = cnt;
			}
		}
	}

	return answer;
}

void test_case(int caseIndex) {
	int N, K;
	scanf("%d %d", &N, &K);

	int **wastes = new int *[N];
	for (int r = 0; r < N; r += 1) {
		wastes[r] = new int[N];
		for (int c = 0; c < N; c += 1) {
			scanf("%d", &wastes[r][c]);
		}
	}

	int answer = get_minimum_trashes(wastes, N, K);
	printf("%d\n", answer);

	for (int r = 0; r < N; r += 1) {
		delete[] wastes[r];
	}
	delete[] wastes;
}

int main() {
	int caseSize;
	scanf("%d", &caseSize);

	for (int caseIndex = 0; caseIndex < caseSize; caseIndex += 1) {
		test_case(caseIndex);
	}
	return 0;
}
