#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while (T--){
        string s,t;
        int n,flg = 1,ans;
        cin >> n >> s >> t;
        for (int i=0;i<n;i++){
            if (s[i]=='0'&&t[i]=='1'){
                if (flg){
                    ans = 0;
                    break;
                }
            }
            if (s[i]=='1'){
                ans = 1;
                break;
            }
        }
        cout << (ans?"YES\n":"NO\n");
    }
}