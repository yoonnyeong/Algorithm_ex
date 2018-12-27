 #include <cstring>
#include <cstdio>

char s[101]; //원본문자열
char p[101][101];
int plen[101]; //패턴 문자열의 길이
bool chk[301][101]; //전처리 계산한 것을 넣은 공간 -> 패턴이 일치하는지 미리 계산된 공간
int slen; //원본문자열의 길이

void test_case(){
	int n;
	scanf("%d", &n);
	scanf("%s", s); 
	//원본 문자열의 길이를 계산
	slen = strlen(s);
	
	for(int i = 0; i < n; i++){
			scanf("%s", p[i]);
			// 패턴의 문자열 길이를 담아두기
		  plen[i] = strlen(p[i]);
	}
	
	//전처리
	for(int i = 0; i < slen; i++){
			for(int pi = 0; pi < n; pi++){
				int flag =1;
				for(int j = 0; j < plen[pi]; j++){
						if(s[i+j] != p[pi][j] || i+j >= slen){
								flag = 0;
								break;
						}
				}
				//flag가 참이면 1이, 거짓이면 0이 들어감
				chk[i][pi] = (flag == 1);
			}
	}
	
	bool cnt = false;
	for(int i = 0; i < n; i++){
		for(int j =0; j <n; j++){
				if( i == j) continue; // 중복되면 안되므로
				for(int k=0; k <n; k++){
					if( j == k || i == k) continue;
					int li = plen[i];
					int lj = plen[j];
					int lk = plen[k];
					if(li+lj+lk != slen) continue;
					if(chk[0][i] && chk[li][j] && chk[li+lj][k]){
						cnt = true;
					}
						
				}
		}
	}
	if(cnt) printf("YES\n");
	else printf("NO\n");

}
int main(){
	int t;
	scanf("%d", &t);
	
	for(int i = 0; i < t; i++){
			test_case();
	}
	
	return 0;
}
