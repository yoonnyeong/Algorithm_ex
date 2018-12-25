#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
/*
char* 형은 한번 대입 후, 수정할 수 없음
*/
int main() {
	int n;
	scanf("%d", &n);
	//비교할 문자열을 입력받는다
	char* answer;
	scanf("%s", answer);
	int count = strlen(answer);

	
	for(int i = 0; i < n; i++){
	  	bool check = true;
		char compare[100];
		 scanf("%s", compare);
	
	 for(int j=0; j < count; j++){
				if(answer[0]!=compare[0]) check= false;
				if(answer[j]!=compare[j]){
				
						if(answer[j]=='?')
							 check= true;
						else
							check = false;
			
				}
		 }
		
		if(check)
			printf("%s\n", compare);
	}
	
  return 0;
}
