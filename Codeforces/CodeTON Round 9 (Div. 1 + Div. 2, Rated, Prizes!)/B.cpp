#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        string s;
        cin >> s;
        int ok = 1;
        for (int i=1;i<s.length();i++){
            if (s[i-1] == s[i]){
                cout << s[i-1] << s[i] << '\n';
                ok = 0;
                break;
            }
            if (i > 1 && s[i-2] != s[i-1] && s[i-1] != s[i] && s[i-2] != s[i]){
                cout << s[i-2] << s[i-1] << s[i] << '\n';
                ok = 0;
                break;
            }
        }
        if (ok){
            cout << -1 << '\n';
        }
    }
}