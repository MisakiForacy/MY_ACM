#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,ok = 1;
        cin >> n;
        string s,t;
        cin >> s >> t;
        for (int i=0;i<n;i++){
            if (s[i]=='1'){
                break;
            } else if (t[i]=='1'){
                ok = 0;
                cout << "NO\n";
                break;
            }
        }
        if (ok) cout << "YES\n";
    }
}