#include <stdio.h> 

using namespace std;
// quick sort로 구현해보기  
int data[1000001];

void swap(int &x, int &y){
	int z = x;
	x = y;
	y = z;
}
int choosePivot(int low, int high){
	return low+ (high+low)/2;
}
int partition(int low, int high){
	int pivotIndex = choosePivot(low, high);
	int pivotValue = data[pivotIndex];
	
	swap(data[pivotIndex], data[high]);
	int storeIndex = low;
	for(int i = low;  i< high; i++){
		if ( data[i] < pivotValue){
			swap(data[i] , data[storeIndex]);
			storeIndex += 1;
		}
	}
}
void quicksort(int low, int high){
	if(low < high){
		int pivot = partition(low, high);
		quicksort(low, pivot-1);
		quicksort(pivot + 1, high);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++){
		scanf("%d",&data[i]);
	}
	quicksort(0, n-1);
	for(int i =0; i< n; i++)
		printf("%d\n", data[i]);
	
	return 0;
}
