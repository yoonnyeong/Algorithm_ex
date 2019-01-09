#include <iostream>
#include <string>
using namespace std;

// 문자열을 재귀함수를 이용해서 출력 
void printChars(string str){
	if(str.length()==0) return;
	else{
		// 첫번째 문자를 출력
		cout << str.at(0);
		// 첫번째 문자를 제외하고함수를 다시 호출
		printChars(str.substr(1)); 
	}
} 
int main(){
	string str = "hello";
	printChars(str);
	
}
