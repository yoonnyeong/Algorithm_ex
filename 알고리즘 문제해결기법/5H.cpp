#include <iostream>
#include <stdio.h>
#include <algorithm> //max, min을 사용하기 위해 
using namespace std;
int getArea(int la, int ra, int ta, int ba, int lb, int rb, int tb, int bb){
	int lr, rr, tr,br; //겹치는 영역의 좌표들 
	lr = max(la, lb);
	rr = min(ra, rb);
	tr = min(ta, tb);
	br = max(ba, bb);
	// 둘이 겹치는 영역이 있을 때
	if( lr <= rr && br <= tr)
		return (rr-lr)*(tr-br);
  // 두 직사각형이 겹치는 영역이 없을 때
	return 0;

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
	//넓이를 구함
 int area =	getArea(la,ra,ta,ba, lb, rb, tb, bb);
 printf("%d\n", area);
}
int main() {
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		test_case();
	}
  return 0;
}
