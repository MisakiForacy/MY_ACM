#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n,m;
        cin >> n;
        vector<ll>a(n);
        for (int i=0;i<n;i++) cin >> a[i];
        cin >> m;
        string s;
        for (int i=0;i<m;i++){
            map<char,ll>mpc;
            map<ll,char>mpn;
            cin >> s;
            if (s.length()!=n){
                cout << "NO\n";
                continue;
            }
            int ok = 1;
            for (int i=0;i<n;i++){
                if (mpc.count(s[i]) && mpc[s[i]]!=a[i] ){
                    ok = 0;
                } else if (mpn.count(a[i]) && mpn[a[i]]!=s[i]){
                    ok = 0;
                } else{
                    mpc[s[i]] = a[i];
                    mpn[a[i]] = s[i];
                }
            }
            cout << (ok?"YES\n":"NO\n");
        }
    }
}