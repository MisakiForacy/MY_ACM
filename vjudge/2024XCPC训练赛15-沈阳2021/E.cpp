#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    string s;
    cin >> s;
    int cnt = 0;
    for (int i=4;i<s.length();i++){
        if (s.substr(i-4,5) == "edgnb"){
            cnt ++;
        }
    }
    cout << cnt << '\n';
}