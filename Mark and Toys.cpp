#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int num, money,i,sum=0;
    cin>>num>>money;
    int cost[num];
    
    for (i=0;i<num;i++){
        cin>>cost[i];
    }
    sort(cost,cost+num);
    i=0;
    while(cost[i]<money){ //들어온 배열의 값이 나의 예산보다 작은 동안에만
        //sum에 더해가며
        sum=sum+cost[i];
        // 내가 구하고자하는 총 money의 값보다 sum이 더 크다면 반복문 탈출
        if(sum>money) break;
        //그게 아니라면, 하나를 넣어준다.
        i++;
        
    }
    cout<<i;
    return 0;
}
