#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define debug(x) cerr << #x << ": " << x << '\n'
using namespace std;
typedef long long ll;
int main(){
    ll n,ans=0;
    cin >> n;
    vector<ll>ar(n),br(1e5+10,0);
    for (int i=0;i<n;i++){
        cin >> ar[i];
        br[ar[i]] += ar[i];
    }
    sort(all(ar));
    ll l = unique(all(ar)) - ar.begin();
    for (int i=0;i<l;i++){
        if (br[ar[i]]+br[ar[i]+2]>br[ar[i]+1]){
            ans += br[ar[i]];
            br[ar[i]] = 0;
            br[ar[i]-1] = 0;
            br[ar[i]+1] = 0;
        }
        debug(ans);
    }
    cout << ans << '\n';
}