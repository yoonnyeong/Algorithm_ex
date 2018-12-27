#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;


class Parenthesis {
public:
	bool type;  // 열린 괄호면 true, 닫힌 괄호면 false
	int index;  // 해당 괄호의 인덱스

	Parenthesis(int index, bool type) {
		this->index = index;
		this->type = type;
	}

	Parenthesis(int index, char c) {
		this->index = index;
		if (c == '(') {
			this->type = true;
		} else {
			this->type = false;
		}
	}
};


bool isValidParentheses(const vector<Parenthesis>& parentheses) {
	// 현재 짝을 찾지 못한 열린 괄호들
	stack<Parenthesis> myStack;
	for(int i = 0; i < parentheses.size(); i++){
			//입력된 정보들을 차례대로 살펴보면서
			Parenthesis p = parentheses[i];
			// 괄호가 열린괄호일때만 스택에 넣어준다.
		  if(p.type == true)
				myStack.push(p);
		 //닫힌 괄호 일때, 스택에 데이터가 있어야 한다. -> 짝을 맞춰야 하기 때문에
		  else if(p.type == false){
				// 1.스택에 데이터가 있고, 스택 맨위가 열린괄호일때
				if(myStack.size() > 0 && myStack.top().type==true){
						myStack.pop(); //짝을 맞출 수 있으므로 꺼내준다. ->제거
				}
				// 2. 스택에 데이터가 없고, 맨 위 데이터도 열린 괄호가 아닐때
				else{
					return false;
				}
			} 
		}
	
	// 전체 입력된 데이터를 다 처리했는데, 스택이 비어있지 않다면, 짝이 맞지 않는다는 뜻
	if(myStack.size() > 0) {
		// 아직 스택에 짝을 찾지 못한 열린 괄호가 남아있다.
		return false;
	}
	return true;
}

void process(int caseIndex) {
	string str;
	cin >> str;

	vector<Parenthesis> parentheses;
	for (int i = 0; i < str.length(); ++i) {
		//인덱스와 문자로 입력
		parentheses.push_back(Parenthesis(i,str[i]));
	}

	bool isValid = isValidParentheses(parentheses);

	if (isValid) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}

int main() {
	int caseSize;
	cin >> caseSize;

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
		process(caseIndex);
	}
}
