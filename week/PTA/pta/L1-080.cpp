#include <bits/stdc++.h>
using namespace std;
int main(){
    int a1,a2,n;
    int i;
    cin >> a1 >> a2 >> n;
    string num = to_string(a1) + to_string(a2);
    for(i=1;i<n;i++){
        num.append(to_string((num[i]-'0')*(num[i-1]-'0')));
    }
    for(i=0;i<n;i++){
        cout << num[i] << " ";
    }
}