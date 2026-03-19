#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    int T;
    cin >> T;
    while (T--){
        int n,q;
        string s;
        cin >> n >> q;
        cin >> s;
        vector<int> a(n+1);
        vector<int> b(n+1,0);
        vector<int> pre(n+1,0);
        vector<int> p(n+1,0);
        for (int i=1;i<=n;i++){
            cin >> a[i];
        }
        s = ' ' + s;
        for (int i=1;i<=n;i++){
            pre[i] = pre[i-1] + a[i];
            p[i] = p[i-1] + i;
            b[i] = (s[i]=='R');
        }
        int j = 0;
        vector<int> seg(n+1,0);
        vector<int> chg(n+1,0);
        seg[0] = 1;
        for (int i=1;i<=n;i++){
            if (pre[i]-pre[j] == p[i]-p[j]){
                seg[i] = 1;
                j = i-1;
            }
        }
        map<int,int> mp;
        for (int i=1;i<n;i++){
            if (!b[i] && b[i]){
                chg[i] = 1;
                mp[i] = 1;
            }
        }
        int ok = 1;
        int x;
        for (int i=0;i<q;i++){
            cin >> x;
            b[i] = !b[i];
            if (!b[i] && b[i]){
                chg[i] = 1;
                mp[i] = 1;
            } else{
                chg[i] = 0;
                mp[i] = 0;
            }
            for (auto [k,v]:mp){
                if (v && !seg[k]){
                    ok = 0;
                }
            }
        }
        cout << (ok?"Yes\n":"No\n");
    }
}