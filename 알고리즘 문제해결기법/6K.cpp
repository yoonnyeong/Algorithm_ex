#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin >> N;

	// 현재까지 최다득표한 후보들의 목록
	vector<string> curMaxFreqName;

	// 각 후보 이름과 득표 수를 저장하는 key-value Map
	map<string, int> frequencyMap;

	int maxFrequency = 0; // 가장 많은 득표수
	
  //각이름이하나추가될때마다 현재까지의 최다 특표 값 갱신, 최다 득표 후보 리스트를 갱신해간다.
  //vector의 clear메소드는 O(1)이다.
	for (int i = 0; i<N; i++) {
		string st; //getline(cin, st);
		cin >> st;
		// 이름이 들어오면, 그 이름을 가진 후보의 득표수를 1증가
		frequencyMap[st]++;
		// 특정 후보의 득표수에 대해서
		int k = frequencyMap[st];
		// 현재 최대값 보다 크다면, 
		if (k>maxFrequency) {
			//최대값을 변경해준 후, 
			maxFrequency = k;
			//이전에 있었던 후보는 다 지운다.
			curMaxFreqName.clear();
			//현재 최대값을 가진 후보의 이름을 추가
			curMaxFreqName.push_back(st);
		}
		// 최대값과 후보이름의 득표수가 일치한다면, 배열에 추가
		else if (k == maxFrequency) {
			curMaxFreqName.push_back(st);
		}
	}
	
	// 최대 득표 후보 수를 출력한다.
	cout << curMaxFreqName.size() << endl;

	// 최대 득표를한 동점 후보들 이름을 사전순으로 출력한다.
	sort(curMaxFreqName.begin(), curMaxFreqName.end());
	for(auto i : curMaxFreqName){
		cout << i << ' ';
	}
	cout << endl;
}
