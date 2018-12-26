#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;
/*그 문자열이 나오면, 갯수를 세다가 맨처음 인덱스만 출력*/
int main() {
	// 기준 문자열
	string sentence;
	// 검색할 문자열
	string pattern;
	cin >> sentence;
	cin >> pattern;

	int n = sentence.length();
	int m = pattern.length();
	
	for(int i = 0; i  + m - 1 < n; i += 1){
		bool check = true;
		//패턴 길이가 반복되어야한다. * 중요한 포인트 : 인덱스 조절을 잘 해야함		
		 		for(int j = 0; j < m; j++){
							// 기준문자열과 패턴의 문자열이 다르다면, false처리후, 가장 가까운 반복문을 빠져나옴
							if(sentence[i+j] != pattern[j]){
								check = false;
								break;
							}	
				}
			    // 패턴의 길이만큼 비교 후, 모두 일치 한다면 인덱스를 출력
			 		if(check==true){
							printf("%d\n", i);
					}				
			}	
  return 0;
}
