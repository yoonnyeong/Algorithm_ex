#include <cstdio>
#include <vector>

using namespace std;
// 최대 공약수
long long getGCD(long long a, long long b) {
		while( a % b != 0 ){
			long long c = a % b;
			a = b;
			b = c;
		}
	return b;
}
// 최소공배수
long long getLCM(long a, long b) {
	return a * b / getGCD(a, b);
}

/**
 * 여러 숫자에 대한 공통 최소 공배수를 계산하는 함수
 *
 * @param numbers
 * @return
 */
long long getLCM(vector<long long>& numbers) {
	 //수가 하나도 없는 배열이라면
	if(numbers.size() == 0 ){
		return 0;
	}

	long long lcm = numbers[0];
		for(int i = 1; i < numbers.size(); i++){
				lcm =  getLCM(lcm, numbers[i]);
		}
	
	return lcm;
}

/**
 * 모든 수열이 동시에 최초의 원소를 만나는 최소 주기를 계산하는 함수
 *
 * @param n     수열의 수
 * @param sizes 각 순환 수열의 길이(주기)
 * @return
 */
long long getGlobalPeriod(vector<long long>& sizes) {
		long long period = getLCM(sizes);
		return period;
}

int main() {
	int n;
	scanf("%d", &n);

	vector<long long> sizes(n);

	for (int i = 0; i < n ; i += 1) {
		scanf("%lld", &sizes[i]);
	}
	// 최소공배수에 더하기 1을 하면 다시 1부터 시작되는 위치를 반환
	long long answer = 1 + getGlobalPeriod(sizes);
	printf("%lld\n", answer);
}
