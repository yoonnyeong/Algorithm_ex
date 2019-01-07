#include <bits/stdc++.h>

using namespace std;
int ar[1002];

int main(){
    int n;
    scanf("%d", &n);

    for(int i  =0 ; i <n; i++){
        scanf("%d", &ar[i]);
    }
    // 삽입정렬을 하기 위해 이동한 총 횟수
    int count = 0;
      for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(ar[i] < ar[j]){
                    int temp = ar[i];
                    for(int k = i; k > j; k--){
                        ar[k] = ar[k-1];
                        count++;
                    }
                    ar[j] = temp;     
                    //count += i-j;
                    break;
                }
            }
        }
    printf("%d", count);

    return 0;
}

