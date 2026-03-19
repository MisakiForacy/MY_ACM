#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        ll n, m;
        cin >> n >> m;
        vector<ll>ar(n+1),pre(n+1,0);
        for (int i=1;i<=n;i++){
            cin >> ar[i];
        }
        sort(ar.begin(),ar.end());
        for (int i=1;i<=n;i++){
            pre[i] = pre[i-1] + ar[i];
        }
        ll lo = 1,hi = 1, mx = 0;
        for (hi = 1; hi <= n;hi ++){
            while (ar[hi] - ar[lo] > 1) lo ++;
            while (pre[hi] - pre[lo-1] > m) lo ++;
            mx = max(mx,pre[hi]-pre[lo-1]);
        }
        cout << mx << '\n';
    }
}