#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Tower {
public:
	int index; // 타워의 인덱스
	int height; // 타워의 높이
	int targetTowerIndex;  // 이 타워의 레이저를 수신하는 대상 타워

	Tower(int index, int height) {
		this->index = index;
		this->height = height;
		this->targetTowerIndex = 0;
	}

	void setTargetTowerIndex(int targetTowerIndex) {
		this->targetTowerIndex = targetTowerIndex;
	}

	int getTargetTowerIndex() {
		return this->targetTowerIndex;
	}
};

/**
 * 파라미터로 주어지는 각 타워들에 대해 타겟 타워를 계산하는 함수
 *
 * @param n         타워의 수
 * @param towers    왼쪽~오른쪽 순서로 저장된 타워 배열
 */
void findTargetTowers(vector<Tower>& towers) {
	// 현재 다른 타워의 신호를 수신할 가능성이 있는 타워들
	stack<Tower> towerStack;
	
	for(int i = 0; i < towers.size(); i++){
		Tower &t = towers[i];
		//수신할 인덱스
		int targetIndex = 0;
		//스택이 비어있지 않고, 스택에 있는 높이보다 내 높이가 크면 (수신을 못보냄) - 더 오른쪽에 있는 height가 작아야 신호전달 가능
		while( towerStack.empty() == false && t.height > towerStack.top().height){
					// 제거
			towerStack.pop();
					
		}
		
		// while문을 지나치고, 스택에 데이터가 있다면
		if(towerStack.size() > 0){
				targetIndex = towerStack.top().index;
		}
		// 나의 인덱스를 신호를 받을 수 있는 인덱스로 변경
		t.setTargetTowerIndex(targetIndex);
		
		// 그 다음, t도 스택에 push
		towerStack.push(t);
		
	}
}

int main() {
	int n;
	cin >> n;

	vector<Tower> towers;
	for(int i = 0; i < n; ++i) {
		int hi;
		cin >> hi;
		towers.push_back(Tower(i + 1, hi)); // 인덱스 1부터 저장
	}

	// 각 타워가 송신하는 레이저에 대해 타겟을 모두 계산한다
	findTargetTowers(towers);

	for(int i = 0 ; i < n; i ++) {
		if(i > 0) {
			cout << " ";
		}
		Tower t = towers[i];
		int targetIndex = t.getTargetTowerIndex();
		cout << targetIndex;
	}
}
