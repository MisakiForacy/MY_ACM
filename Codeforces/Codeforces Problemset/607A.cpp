#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
using namespace std;
using LL = long long;
int main(){
    int n,b;
    cin >> n;
    vector<int> a(n,0);
    vector<int> dp(n,0);
    map<int,int> mp;
    for (int i=0;i<n;i++){
        cin >> a[i] >> b;
        mp[a[i]] = b;
    }
    sort(a.begin(),a.end());
    for (int i=0;i<n;i++){
        int pos = lower_bound(all(a),a[i]-mp[a[i]])-begin(a);
        if (pos == 0){
            dp[i] = 1;
        } else{
            dp[i] = dp[pos-1] + 1;
        }
    }
    int Min = INT_MAX;
    for (int i=0;i<n;i++){
        Min = min(Min,n-dp[i]);
        // cout << dp[i] << " \n"[i==n-1];
    }
    cout << Min << '\n';
}