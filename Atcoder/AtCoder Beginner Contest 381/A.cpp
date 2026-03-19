#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s1,s2;
    int ok = 0;
    for (int i=0;i<n;i++){
        if (s[i] == '/'){
            ok = 1;
            s1 = s.substr(0,i);
            s2 = s.substr(i+1,n-i);
        }
    }
    if (s1.length() != s2.length()){
        ok = 0;
    }
    for (int i=0;i<s1.length();i++){
        if (s1[i] != '1'){
            ok = 0;
        }
    }
    for (int i=0;i<s2.length();i++){
        if (s2[i] != '2'){
            ok = 0;
        }
    }
    cout << (ok ? "Yes\n":"No\n");
}