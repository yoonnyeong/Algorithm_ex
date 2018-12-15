 #include<cstdio>
#include<iostream>

using namespace std;

/**
* 왼쪽 아래 좌표가 (x,y)인 픽셀이 반지름 R인 원에 포함되는가?
* @param x
* @param y
* @param R
* @return  포함된다면 true, else false
*/
bool isInside(long long x, long long y, long long R)
{
		long long result = x*x + y*y;
	  if(result < R*R){ // 좌표가 원안에 있어야 하므로 = 은 없어야함
			return true;
		}
	//원안에 포함되어있는 점이 아니라면
	return false;
	
}
void testcase(int caseIndex) {
	long long R; //반지름
	scanf("%lld", &R);
	long long sum = 0 ; //포함되는 픽셀 수 세기
	long long y = R; //y좌표에 반지름 -> 위에서부터 차례대로 
	for(int x = 0; x <= R; x++){
		long long height =0;
		for(; y>=0; y--){
			if(isInside(x,y,R)){
			   height = (y+1);
				 break;
			}
		}
		sum+= height;	 
	}
	printf("#%d\n", caseIndex);
	//몇개인지 출력
	printf("%lld\n", sum*4);
	
}

int main()
{
	int caseSize;
	scanf("%d", &caseSize);
	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1)
	{
		testcase(caseIndex);
	}
	return 0;
}