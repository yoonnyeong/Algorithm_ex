#include <iostream>
#include <string>
using namespace std;

// 재귀함수를 이용해서 문자열의 길이를 계산  
int length(string str){
	if(str=="") return 0;
	else{
		//앞글자를 제외하고 나머지 문자열에 대해 계산  
		return 1 +  length(str.substr(1));
	}
} 
int main(){
	// 길이를 계산할 문자열
	string str;
	cin >> str;
	cout << "문자열의 길이는 : " << length(str); 
	
}
