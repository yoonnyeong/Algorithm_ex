#include <cstdio>
#include <vector>

using namespace std;

//소인수 분해를 빠르게
class Sieve {
public:
	int maximumValue;     // 에라토스테네스의 체에서 다룰 가장 큰 범위의 값
	vector<bool> isPrime; // 각 숫자별 소수 여부
	Sieve(int maximumValue) {
		this->maximumValue = maximumValue;
		this->isPrime.assign(maximumValue + 1, false);
		this->fillSieve();
	}

	/**
	 *
	 * @param num
	 * @return 'num'이 소수라면 true, 그렇지 않으면 false
	 */
	bool isPrimeNumber(int num) const {
		return this->isPrime[num];
	}

	/**
	 * isPrime 배열의 값을 채우는 함수
	 */
	void fillSieve() {
		//isPrime을 모두 소수라고 가정하고 TRUE로	
		isPrime.assign(this->maximumValue, true);
		isPrime[0] = isPrime[1] = false; // 0,1은 false
		//2부터 maximumValue까지 isPrime배열을 채워나감
		for(int num =2; num <= maximumValue; num++){
			// 이미 소수가 아니라면, 볼 필요 없음
				if(isPrime[num] == false){
					continue;
				}
			// num이 소수라면, 그 수의 배수는 모두 false로 처리 
			 for(long long mul = (long long) num * num; mul <= maximumValue; mul+=num){
					int index = (int)mul;
			  	isPrime[index] = false;
			}
		}
		
	}
};

vector<int> getAllPrimeNumbers(int from, int to, const Sieve& sieve) {
	vector<int> primes;

	for(int num = from; num <= to; num += 1) {
		if(sieve.isPrimeNumber(num)) {
			primes.push_back(num);
		}
	}

	return primes;
}

void process(int caseIndex, const Sieve& sieve) {
	int L, R;
	scanf("%d%d", &L, &R);

	vector<int> allPrimeNumbers = getAllPrimeNumbers(L, R, sieve);

	printf("Case #%d:\n", caseIndex);
	printf("%d\n", (int)allPrimeNumbers.size());
}

int main() {
	const int MAX_VALUE = 1000000;
	Sieve sieve = Sieve(MAX_VALUE);

	int caseSize;
	scanf("%d", &caseSize);

	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
		process(caseIndex, sieve);
	}
}
