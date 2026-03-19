#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
using LL = long long;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    LL n,k,q;
    cin >> n >> k >> q;
    vector<vector<LL>> b(n+1,vector<LL> (k+1,0));
    vector<vector<LL>> a(k+1);
    for (LL i=1;i<=n;i++){
        for (LL j=1;j<=k;j++){
            cin >> b[i][j];
            b[i][j] = b[i][j] | b[i-1][j];
        }
    }
    for (LL j=1;j<=k;j++){
        for (LL i=1;i<=n;i++){
            a[j].push_back(b[i][j]);
        }
    }
    while (q--){
        LL m,r,c;
        char o;
        cin >> m;
        LL lo = 0, hi = n;
        for (LL i=0;i<m;i++){
            cin >> r >> o >> c;
            if (o == '>'){
                lo = max(lo,LL(upper_bound(all(a[r]),c)-begin(a[r])));
            } else{
                hi = min(hi,LL(lower_bound(all(a[r]),c)-begin(a[r])));
            }
        }
        if (lo < hi){
            cout << lo + 1 << '\n';
        } else{
            cout << -1 << '\n';
        }
    }
}