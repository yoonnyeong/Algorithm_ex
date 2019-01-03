#include <bits/stdc++.h>

using namespace std;

// 기준함수를 정의
bool compare(string a, string b){
    // 두 문자열의 길이가 다르다면
    if(a.length() != b.length())
        //짧은 것을
        return a.length() < b.length();
    else
        // 
        return a < b;    
}
int main(){
    int n;
    scanf("%d", &n);
    vector<string> arr(n);
    for(int i=0; i <n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end(), compare);
    for(int i=0; i <n; i++)
        cout << arr[i] << endl;
    return 0;
}
