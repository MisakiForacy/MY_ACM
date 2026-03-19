#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e6 + 10;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    LL n,m,q,x;
    cin >> n >> m >> q;
    vector<LL> a(n),b(m);
    map<LL,int> posa, posb, nega, negb;
    LL sa,sb;
    sa = sb = 0;
    for (int i=0;i<n;i++) cin >> a[i], sa += a[i];
    for (int i=0;i<m;i++) cin >> b[i], sb += b[i];
    for (int i=0;i<n;i++) a[i] = sa - a[i];
    for (int i=0;i<m;i++) b[i] = sb - b[i];
    for (int i=0;i<n;i++){
        if (a[i] < 0){
            nega[-a[i]] = 1;
        } else{
            posa[a[i]] = 1;
        }
    }
    for (int i=0;i<m;i++){
        if (b[i] < 0){
            negb[-b[i]] = 1;
        } else{
            posb[b[i]] = 1;
        }
    }
    while (q--){
        int ok = 0;
        cin >> x;
        int xx = abs(x);
        for (int i=1;i*i<=abs(x);i++){
            if (x > 0 && x%i == 0){
                ok |= (posa[i] && posb[xx/i]);
                ok |= (nega[i] && negb[xx/i]);
                ok |= (posb[i] && posa[xx/i]);
                ok |= (negb[i] && nega[xx/i]);
            } else if (x%i == 0){
                ok |= (posa[i] && negb[xx/i]);
                ok |= (nega[i] && posb[xx/i]);
                ok |= (posb[i] && nega[xx/i]);
                ok |= (negb[i] && posa[xx/i]);
            }
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
}