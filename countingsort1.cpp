#include <iostream>
#include <vector>
using namespace std;

vector<int> count;
int main(){
    int n;
    cin >> n;
    // count라는 배열 100개를 0으로 전부 초기화
    count.resize(100, 0);

    for(int i =0; i < n; i++){
        int a; // 입력받을 숫자
        cin >> a;
        count[a] +=1;
    }
    // count  배열은  n과 다를 수 있음 
    for(int i =0; i < count.size(); i++){
       cout << count[i] << " ";
    }
    return 0;
}
