#include<stdio.h>
#include<vector>
#include<queue>
#include<functional>
using namespace std;

template<typename T>
//중앙값 큐
class MidianQueue {
private:
	priority_queue<T>maxQ; //최대값 우선순위 큐
	priority_queue<T, vector<T>, greater<T>>minQ; //최소값 우선순위 큐
	//균형 맞추기
	void balancing() {
		// 최소값 우선순위 큐가 최대값 우선순위 큐의 크기보다 크다면, 
		while (minQ.size() > maxQ.size()) {
			// 최대값 우선순위 큐에 , 최소값 우선순위의 값을 추가
			maxQ.push(minQ.top());
			//minQ에서는 그 값을제거
			minQ.pop();
		}
		while (minQ.size() + 1 < maxQ.size()) {
			minQ.push(maxQ.top());
			maxQ.pop();
		}
	}
public:
	size_t size() {
		return maxQ.size() + minQ.size();
	}
	bool empty() {
		return size() == 0;
	}
	//원소추가
	void push(T value) {
		if (maxQ.empty() == false && maxQ.top() >= value) {
			maxQ.push(value);
		}
		
		else {
			minQ.push(value);
		}
		balancing();
	}
	
	void pop() {
		maxQ.pop();
		balancing();
	}
	
	T findMidVal() {
		T retVal = maxQ.top();
		return retVal;
	}
};

int main() {
	int n; scanf("%d", &n);
	//중앙값 큐
	MidianQueue<int>queue;
	for (int i = 0; i < n; i++) {
		char c; scanf(" %c", &c);
		if (c == 'I') { //x를 삽입, 중앙값 출력
			int x; scanf("%d", &x);
			queue.push(x);
			printf("%d\n", queue.findMidVal());
		}
		else if (c == 'P') { //현재 큐에서 중앙값 삭제 후, 출력
			if (queue.empty() == false) {
				queue.pop();
			}
			if (queue.empty() == false) { 
				printf("%d\n", queue.findMidVal());
			}
			else { //아무원소도 남아있지 않는 경우
				printf("ERROR\n");
			}
		}
		else if (c == 'S') {//현재큐에 저장된 원소의 수를 정수로 출력
			printf("%d\n", queue.size());
		}
	}
	return 0;
}
