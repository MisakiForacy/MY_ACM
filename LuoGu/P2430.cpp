#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
int main(){
    int a,b,m,n,x;
    cin >> a >> b;
    cin >> m >> n;
    map<int,int> t;
    for (int i=1;i<=n;i++){
        cin >> x;
        t[i] = x * (b / a);
    }
    int w[N],v[N];
    for (int i=0;i<m;i++){
        cin >> w[i] >> v[i];
        w[i] = t[w[i]];
    }
    int c;
    cin >> c;
    int dp[N];
    for (int i=0;i<=c;i++) dp[i] = 0;
    for (int i=0;i<m;i++){
        for (int j=c;j>=w[i];j--){
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    cout << dp[c] << '\n';
}
