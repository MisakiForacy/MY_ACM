#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ok = 0;
        if (s[0]=='1' || s[n-1]=='1'){
            ok = 1;
        } else{
            for (int i=1;i<n-1;i++){
                if (s[i]=='1' && s[i+1]=='1'){
                    ok = 1;
                }
            }
        }
        cout << (ok?"Yes\n":"No\n");
    }
}