#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int len = s.length();
    int ok = 1;
    for (int i=len-1;i>len/2;i--){
        string s1 = s.substr(0,i);
        string s2 = s.substr(len-i,i);
        if (s1 == s2){
            cout << "YES\n";
            cout << s.substr(0,i) << '\n';
            ok = 0;
            break;
        }
    }
    if (ok){
        cout << "NO\n";
    }
}