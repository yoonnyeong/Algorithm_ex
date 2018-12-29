#include<iostream>
#include<vector>
using namespace std;

/**
	 * 두 오름차순 배열 A와 B를 하나로 합쳐 재정렬하는 함수
	 *
	 * @param n 배열 A의 길이
	 * @param m 배열 B의 길이
	 * @param arrayA 배열 A
	 * @param arrayB 배열 B
	 * @return 두 배열을 합쳐 정렬한 결과를 반환한다
	 */
vector<int> mergeArray(int n, int m, vector<int>&arrayA, vector<int>&arrayB) {
	vector<int>answer;
	int idxA = 0;
	int idxB = 0;
	// n과 m이 같을 때까지는 같이 정렬,  -> 각각 오름차순으로 정렬되어있음
	while( idxA < n && idxB <m ){
			if(arrayA[idxA] < arrayB[idxB]){
				  //작은값부터 answer에 추가 후, 인덱스 추가
				  answer.push_back(arrayA[idxA++]);
			}
			else{
					answer.push_back(arrayB[idxB++]);
			}
				
	}
	// 둘중에 완료되지 않은 것들에 대해서, 이미 오름차순으로 정렬된 배열이니까 추가만 해주면 된다.
	while( idxA < n){
		answer.push_back(arrayA[idxA++]);
	}
	
	while( idxB < m){
		answer.push_back(arrayB[idxB++]);
	}
	return answer;
}

int main() {
	//해당 명령은 iostream의 cin, cout을 빠르게 해준다.
	//해당 명령을 사용할 경우 stdio의 scanf, printf를 사용할 수 없다.
	ios_base::sync_with_stdio(false);
	cin.tie(false);

	int n, m;
	cin >> n >> m;
	vector<int>arrayA(n);
	vector<int>arrayB(m);
	for (int i = 0; i < n; i++) {
		cin >> arrayA[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> arrayB[i];
	}
	vector<int>mergedArray = mergeArray(n, m, arrayA, arrayB);
	for (int i = 0; i < mergedArray.size(); i++) {
		if (i > 0) cout << ' ';
		cout << mergedArray[i];
	}
	cout << endl;
	return 0;
}
