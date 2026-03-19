#include <bits/stdc++.h>
using namespace std;
int main(){
    int v,n,x;
    cin >> v >> n;
    vector<int> dp(v+1,v);
    for (int i=0;i<n;i++){
        cin >> x;
        for (int j=v;j>=x;j--){
            dp[j] = min(dp[j],dp[j-x]-x);
        }
    }
    cout << dp[v] << '\n';
}