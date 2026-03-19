#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+5;
int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    ll dp[N];
    dp[0] = 0;
    for (int i=1;i<=2e5;i++){
        if ((i-1)%10==9){
            int len = to_string(i).length()-2;
            dp[i] = dp[i-int(9*pow(10,len))];
        }
        else dp[i] = dp[i-1] + 1;
    }
    // for (int i=1;i<=2e5;i++){
    //     dp[i] = dp[i-1] + dp[i];
    // }
    while (T--){
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
}