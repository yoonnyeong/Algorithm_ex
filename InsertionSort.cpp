#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int data[1001];

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    int n, temp, j;
    scanf("%d", &n);

    for(int i =0; i <n; i++){
        scanf("%d", &data[i]);
    } 

    for(int i=1; i<n; i++)
    {
       for(int j = 0; j < i; j++){
                if(data[i] < data[j]){
                    int temp = data[i];
                    for(int k = i; k > j; k--){
                        data[k] = data[k-1];
                    }
                    data[j] = temp;                    
                    break;
                }
            }
        }
    
    for(int i =0; i <n; i++){
       printf("%d ", data[i]);
    } 

    return 0;
}
