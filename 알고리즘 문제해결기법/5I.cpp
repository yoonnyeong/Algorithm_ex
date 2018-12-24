#include <iostream>
#include <stdio.h>
#include <algorithm> //max, min을 사용하기 위해 
using namespace std;
bool check(int la, int ra, int ta, int ba, int lb, int rb, int tb, int bb){
	int lr, rr, tr,br; //겹치는 영역의 좌표들 
	lr = max(la, lb);
	rr = min(ra, rb);
	tr = min(ta, tb);
	br = max(ba, bb);
	// 두 선분이 겹칠 때
	if( lr <= rr && br <= tr)
		return true;
 // 두선분이 겹치는 경우가 없을때
	return false;

}

void test_case(){
	int ax, ay, bx, by;
	int px, py, qx, qy;
	scanf("%d %d %d %d %d %d %d %d",&ax, &ay, &bx, &by, &px, &py, &qx, &qy);
	// 좌표가 어떤 순서로 들어오는 지 모르기 때문에 대소관계를 비교 후, 좌표를 재설정
	int la, ra, ta, ba, lb, rb, tb, bb; 
	la = min(ax, bx);
	ra = max(ax, bx);
	ta = max(ay, by);
	ba = min(ay, by);
	
	lb = min(px, qx);
	rb = max(px, qx);
	tb = max(py, qy);
	bb = min(py, qy);
 //선분의 교차여부를 판단
 bool value =	check(la,ra,ta,ba, lb, rb, tb, bb);
 if(value)
	 printf("YES\n");
	else
		printf("NO\n");
}
int main() {
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		test_case();
	}
  return 0;
}
