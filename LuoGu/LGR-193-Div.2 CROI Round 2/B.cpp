#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        int ans = 0;
        string s,t;
        cin >> s >> t;
        s += '0';
        t += '0';
        int len = s.length();
        lo = -1, hi = -1;
        for (int i=0;i<=len;i++){
            if (s[i]!=t[i]){
                if (lo==-1) lo = i;
                hi = i;
            }
        }
        for (int i=lo;i<=hi;i++){
            
        }
        cout << ans << '\n';
    }
}