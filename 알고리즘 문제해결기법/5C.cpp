#include<cstdio>
#include<cstdlib>
#include<memory.h>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class GameMap {
private:
	int **buildings;

public:
	int rows;
	int columns;

	GameMap(int rows, int columns) {
		this->rows = rows;
		this->columns = columns;
		this->buildings = new int *[rows];
		for (int r = 0; r < rows; r += 1) {
			this->buildings[r] = new int[columns];
			fill(buildings[r], buildings[r] + columns, 0);
		}
	}

	~GameMap() {
		for (int r = 0; r < rows; r += 1) {
			delete[] buildings[r];
		}
		delete[] buildings;
	}

	bool isInside(int r, int c) {
		if (r < 0 || r >= this->rows || c < 0 || c >= this->columns) {
			return false;
		}
		return true;
	}

	int getBuildingsAt(int r, int c) {
		if (this->isInside(r, c) == false) {
			return 0;
		}
		return this->buildings[r][c];
	}

	void setBuildingsAt(int r, int c, int value) {
		this->buildings[r][c] = value;
	}
};

int dr[8] = {-1, -1, 0, 1, 1, 1, 0 , -1 }; //dr[d] := d번 방향으로 한 번 움직일때 이동하는 행방향 거리
int dc[8] ={0, 1, 1, 1, 0 , -1 , -1 , -1}; //dc[d] := //  ---- 열방향 거리

void test_case(int caseIndex) {
	int N, K;
	scanf("%d %d", &N, &K);

	GameMap gameMap(N, N);

	for (int r = 0; r < N; r += 1) {
		for (int c = 0; c < N; c += 1) {
			int value;
			scanf("%d", &value);
			gameMap.setBuildingsAt(r, c, value);
		}
	}
int answer = 0;

		for(int i = 0 ; i < K ; i += 1){
			int r, c;
			scanf("%d %d", &r, &c);
			r = r-1;
			c= c-1;

			int buildings = 0;
			buildings += gameMap.getBuildingsAt(r, c);

			for(int di = 0 ; di < 8; di += 1){
				for(int length = 1; length <= N; length += 1){
					int newR = r + dr[di] * length;
					int newC = c + dc[di] * length;
					if(gameMap.isInside(newR, newC) == false){
						break;
					}

					buildings += gameMap.getBuildingsAt(newR, newC);
				}
			}

		if(answer < buildings)
			answer = buildings;
		}

		printf("%d\n", answer);
}

int main() {
	int caseSize;
	scanf("%d", &caseSize);

	for (int caseIndex = 0; caseIndex < caseSize; caseIndex += 1) {
		test_case(caseIndex);
	}
	return 0;
}
