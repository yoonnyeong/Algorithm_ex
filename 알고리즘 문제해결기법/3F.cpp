#include <cstdio>
#include <vector>

using namespace std;

class Range {
public:
	int index; //순서
	int left; // 시작지점
	int right; // 종료지점
	long long totalPoint; //얻은 점수
	Range(int index, int left, int right) {
		this->index = index;
		this->left = left;
		this->right = right;
		this->totalPoint = 0;
	}
};

/**
*
* @param n   카드의 수
* @param m   앨범을 구매한 팬의 수
* @param cards   각 카드에 적힌 숫자의 리스트 (cards[1] ~ card[n])
* @param ranges  각 팬이 선택한 범위의 리스트 (ranges[0] ~ ranges[m-1])
* @return        총 점수의 합이 가장 큰 범위 객체
*/
Range getBestRange(int n, int m, const vector<int>& cards, const vector<Range>& ranges) {
	//합을 계산해서 미리 저장해둘 배열
	vector<long long> rangeSum(n+1, 0);
	for(int i = 1; i <= n; i++){
		rangeSum[i] = rangeSum[i-1] + cards[i];
	}
	Range answer = ranges[0]; //제일 큰거를 첫번째원소라고 가정
	//다 toalPoint값을 바꿔줘야함 
	for(int i = 0; i < m; i++){
	 //들어온 range만큼 각각 꺼내옴
	 	Range r = ranges[i];
		
		r.totalPoint = rangeSum[r.right] - rangeSum[r.left-1];
 		//최대값을 찾아준다
		if(answer.totalPoint < r.totalPoint)
			 answer = r;
	}



	return answer;
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	vector<int> cards(n + 1);
	vector<Range> ranges;

	// 각 카드의 정보를 입력받는다.
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &cards[i]);
	}

	// 팬들의 정보를 입력받는다.
	for (int i = 1; i <= m; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		ranges.push_back(Range(i, l, r));
	}

	// 범위의 합이 가장 큰 범위를 계산한다.
	Range answer = getBestRange(n, m, cards, ranges);
	printf("%d %lld\n", answer.index, answer.totalPoint);
  
  return 0;
}
