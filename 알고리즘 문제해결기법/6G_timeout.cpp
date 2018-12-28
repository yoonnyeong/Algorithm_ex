#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int income[200000];

void testcase(){
		int n, m;
	  scanf("%d %d", &n, &m);
		for(int i = 0;  i < n; i++){
				income[i] = 0;
		}

		for(int i = 0;  i < n; i++){
				scanf("%d", &income[i]);
		}
	
		//배열의 각각 k개에 대하여 최대, 최소값을 계산해야한다.
		int first = 0;
		int last = 999;
	
		priority_queue<int> q;
		for(int i = 0; i < n-m; i++){
				for(int j = i; j < i + m; j++){
						first = max(first, income[j]);
					  last = min(last, income[j]);
				}
				int answer = first - last;
				q.push(answer);
		}
		int a = q.top();
		printf("%d\n", a); 

}
int main() {
 int t;
 scanf("%d", &t);
	
 for(int i = 0; i < t; i++){
		testcase();
 }
}
