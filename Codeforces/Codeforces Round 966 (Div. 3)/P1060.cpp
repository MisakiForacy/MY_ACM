#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct haha{
    ll v,w;
};
int main(){
    int n,m;
    cin >> n >> m;
    vector<haha>a(m);
    for (int i=0;i<m;i++){
        cin >> a[i].v >> a[i].w;
    }
    vector<ll> dp(n+1,0);
    for (int i=0;i<m;i++){
        for (int j=n;j>=a[i].v;j--){
            dp[j] = max(dp[j],dp[j-a[i].v] + a[i].v * a[i].w);
        }
    }
    cout << dp[n] << '\n';
}