#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
#include<list>
using namespace std;


vector<string> a[100];
char str[100007];
int n,i,j,x;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    
    cin>>n;
    // 들어온 n개 중, 반 개는 -로
    for(i=0;i<n/2;i++)
    {
        cin>>x;
        cin>>str;
        a[x].push_back("-");
    
    }
    // 나머지 반은,입력받은 문자열 그대로 
    for(;i<n;i++)
    {
        cin>>x;
        cin>>str;
        a[x].push_back(str);
    
    }
    /*
     각 배열에 들어간 사이즈 만큼 출력
    */
    for(i=0;i<100;i++)
    {
        x=a[i].size();
        for(j=0;j<x;j++)
            cout<<a[i][j]<<" ";    
    }
    return 0;

}
