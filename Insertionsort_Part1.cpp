#include <bits/stdc++.h>

using namespace std;
int data[1001];

void printArray(int n,int arr[]){
    for(int i = 0; i <n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void insertionSort1(int n, int ar[]) {
//temp에 배열의 맨 마지막 원소를 저장
  int temp = ar[n-1];
        //n-2부터 시작해서 
        for(int i = n-2; i >= -1; i--){
            if(i == -1){
                ar[0] = temp;
                printArray(n, ar);
                break;
            }
            // 맨뒤의 원소보다 ar[i]이 더 크다면, 옆으로 옮김 ->
            else if(ar[i] > temp){
                ar[i+1] = ar[i];
                printArray(n, ar);
                continue;
            }
            // temp가 더 크다면, temp를 ar[i+1]에 저장
            else{
                ar[i+1] = temp;
                printArray(n, ar);
                break;
            }
        }

}

int main()
{
   
    int n;
    scanf("%d", &n);
    for(int i =0; i<n; i++){
        scanf("%d", &data[i]);
    }
    insertionSort1(n, data);
    return 0;
}

