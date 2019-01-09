#include <iostream>
#include <vector>
using namespace std;

vector<int> list;

int main(){
    int n;
    cin >> n;
    list.resize(100,0);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        list[a]++;
    }
    // list의 size만큼
    for(int i = 0; i < list.size(); i++){
        // 크기가 0이상일때, 
        if(list[i]>0){
            // 그 크기 만큼 i를 출력
            for(int j =0; j<list[i]; j++)
                cout << i << " ";
        }
    }
    
    return 0;
} 
