#include <bits/stdc++.h>
#define debug(x) cerr << #x << ":" << x << '\n'
using namespace std;
typedef long long ll;
const ll inf = 0x3f3f3f3f3f3f3f;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    ll n,k,idx,cnt=0,mi=inf;
    cin >> n >> k;
    vector<ll>ar(n+1);
    queue<ll>Q;
    for (ll i=1;i<=k;i++){
        cin >> ar[i];
        Q.push(ar[i]);
        cnt += ar[i];
    }
    mi = cnt, idx = 1;
    for (ll i=k+1;i<=n;i++){
        cin >> ar[i];
        cnt -= Q.front();
        cnt += ar[i];
        Q.pop();
        Q.push(ar[i]);
        if (cnt < mi){
            // debug(cnt);
            idx = i - k + 1;
            mi = cnt;
        }
    }
    cout << idx << '\n';
}