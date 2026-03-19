#include <bits/stdc++.h>
using namespace std;
int main(){
    string s,t;
    cin >> s >> t;
    s = ' ' + s + ' ';
    t = ' ' + t + ' ';
    int ans = 0;
    for (int i=1;i<min(s.length(),t.length());i++){
        if (s[i] != t[i]){
            ans = i;
            break;
        }
    }
    cout << ans << '\n';
}