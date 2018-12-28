#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Player{
public:
	int index; //나의 인덱스

	Player(int index){
		this->index = index;
	}
};

/**
 * 조세퍼스 게임을 수행하여 각 플레이어가 제거된 순서를 리스트로 반환하는 함수
 *
 * @param n         플레이어의 수
 * @param m         매 턴마다 건너 뛸 사람의 수
 * @param players   좌석에 앉아있는 순서대로 주어지는 플레이어 정보
 * @return
 */
vector<Player> getDeadPlayersList(int n, int m, const vector<Player>& players){
	// 현재 게임에서 제외된 플레이어들의 리스트
	vector<Player> deadPlayers;

	// 아직 게임에서 제외되지 않는 플레이어들의 리스트
	queue<Player> playerQueue;
	
	
	// 1~ n까지의 데이터가 들어온다.
	for(int i =0; i < n; i++){
		playerQueue.push(players[i]);
	}
	
	for(int i =0 ; i < n; i++){
			int jump = 1 + (m-1) % playerQueue.size();
		  //(m-1)개의 데이터는 옮겨준다.
			for(int i = 0; i < jump-1; i++){
						//진짜 삭제할 것이 아니고, 자리만 이동시켜줄 것이므로
						Player p = playerQueue.front();
						playerQueue.pop();
						playerQueue.push(p); //뒤로 이동시켜놓는다. 
						
			}
			// 이동을 다시킨후, m번째는 front에 위치해있으므로 삭제
		  Player dead = playerQueue.front();
			playerQueue.pop();
				
			//삭제된 리스트에 추가
		  deadPlayers.push_back(dead);
	
	}
	//deadPlayers를 차례대로 출력
	return deadPlayers;
}

void process(int caseIndex) {
	int n, m;
	cin >> n >> m;

	vector<Player> players;
	for(int i = 0; i < n; i++) {
		players.push_back(Player(i + 1)); // 1번 인덱스부터 시작
	}

	vector<Player> deadPlayers = getDeadPlayersList(n, m, players);

	for(int i = 0; i < n; i ++) {
		if(i > 0) {
			cout << " ";
		}

		Player p = deadPlayers[i];
		cout << p.index;
	}

	cout << endl;
}

int main() {
	int caseSize;
	cin >> caseSize;

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
		process(caseIndex);
	}
}

