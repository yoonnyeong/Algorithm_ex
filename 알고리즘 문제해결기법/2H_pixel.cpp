 #include<cstdio>
#include<iostream>

using namespace std;

/**
* ���� �Ʒ� ��ǥ�� (x,y)�� �ȼ��� ������ R�� ���� ���ԵǴ°�?
* @param x
* @param y
* @param R
* @return  ���Եȴٸ� true, else false
*/
bool isInside(long long x, long long y, long long R)
{
		long long result = x*x + y*y;
	  if(result < R*R){ // ��ǥ�� ���ȿ� �־�� �ϹǷ� = �� �������
			return true;
		}
	//���ȿ� ���ԵǾ��ִ� ���� �ƴ϶��
	return false;
	
}
void testcase(int caseIndex) {
	long long R; //������
	scanf("%lld", &R);
	long long sum = 0 ; //���ԵǴ� �ȼ� �� ����
	long long y = R; //y��ǥ�� ������ -> ���������� ���ʴ�� 
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
	//����� ���
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