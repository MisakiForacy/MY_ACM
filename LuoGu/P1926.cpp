#include <bits/stdc++.h>
using namespace std;
const int N = 500;
int main(){
    int n,m,k,r;
    cin >> n >> m >> k >> r;
    vector<int> extra(n);
    int w[N],v[N];
    int dp[N],f[N];
    for (int i=0;i<n;i++) cin >> extra[i];
    for (int i=0;i<m;i++) cin >> w[i];
    for (int i=0;i<m;i++) cin >> v[i];
    for (int i=0;i<=r;i++) dp[i] = 0;
    for (int i=0;i<m;i++){
        for (int j=r;j>=w[i];j--){
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    for (int i=0;i<=r;i++){
        if (dp[i] >= k){
            r -= i;
            break;
        }
    }
    int cnt = 0;
    std::sort(extra.begin(),extra.end());
    for (int i=0;i<n;i++){
        if (extra[i] <= r){
            r -= extra[i];
            cnt ++;
        }
    }
    cout << cnt << '\n';
}