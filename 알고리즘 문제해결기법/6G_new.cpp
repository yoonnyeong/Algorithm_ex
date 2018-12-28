#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class City {
public:
	int index;     // 도시의 인덱스
	int income;    // 해당 도시의 소득

	City(int index, int income){
		this->index = index;
		this->income = income;
	}

	bool operator < (const City& o) const {
		return this->income < o.income;
	}
	bool operator > (const City& o) const {
		return this->income > o.income;
	}
};

int getMaximumRangeDifference(int n, int k, const vector<City>& cities) {
	// 최대값을 저장할 변수
	int answer = 0;

	// 소득이 가장 작은 도시부터 pop되는 우선순위 큐
	/* 우선순위 큐는 다음과 같이 정의할 수 있다.
	 인자 1) 자료형
	 인자 2) vector<int>가 기본
	 인자 3) less<int>가 기본이며, 큰 데이터순으로 정렬 / greater<int>는 오름차순으로 정렬
	*/
	priority_queue<City, vector<City>, greater<City>> rangeMinimum;

	// 소득이 가장 높은 도시부터 pop되는 우선순위 큐
	priority_queue<City> rangeMaximum;
	
	
	// 맨처음엔 0~ k-1개에 대해서막 2개의 우선순위 큐에 넣어준다.
	for(int i = 0; i < k -1 ; i++){
		rangeMinimum.push(cities[i]);
		rangeMaximum.push(cities[i]);
	}
	
	// k개의 범위 안에서 가장 왼쪽에 있는 인덱스를 기준으로, 범위 밖의 데이터는 pop()
	for(int i = k-1; i < n; i++){
		//k번째의 데이터도 큐에 넣어준다.
		rangeMinimum.push(cities[i]);
		rangeMaximum.push(cities[i]);
		
		while(rangeMaximum.top().index < i - k+ 1) rangeMaximum.pop(); //범위 밖이므로 제거
		while(rangeMinimum.top().index < i - k+ 1) rangeMinimum.pop();
		
		//범위를 벗어나지 않는 다면, 최대 - 최소 계산
		answer = max(answer, rangeMaximum.top().income - rangeMinimum.top().income);
	}
	return answer;
}

void process(int caseIndex) {
	int n, k;
	cin >> n >> k;
	vector<City> cities;

	for(int i = 0 ; i < n ; i += 1){
		int income;
		cin >> income;
		cities.push_back(City(i, income));
	}

	int answer = getMaximumRangeDifference(n, k, cities);

	cout << answer << endl;
}

int main() {
	int caseSize;
	cin >> caseSize;

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
		process(caseIndex);
	}
}
