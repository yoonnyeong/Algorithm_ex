#include <cstdio>

using namespace std;

//최대공약수 -> 유클리드 호제법
long long getGCD(long long a, long long b) {
	while( a % b !=0){
			long long c = a % b;
			a = b;
			b = c;
	}
	return b;
}

//최대공배수
long long getLCM(long long a, long long b) {
	// 두 수의 곱에서 최대 공약수를 나누면 최소 공배수다
	return a * b / getGCD(a, b);
}

void process(int caseIndex) {
	int num1, num2;
	scanf("%d%d", &num1, &num2);

	long long gcd =  getGCD(num1, num2);
	long long lcm =  getLCM(num1, num2);

	printf("Case #%d:\n", caseIndex);
	printf("%lld %lld\n", gcd, lcm);
}

int main() {
	int caseSize;
	scanf("%d", &caseSize);

	for (int caseIndex = 1; caseIndex <= caseSize; ++caseIndex) {
		process(caseIndex);
	}
}
