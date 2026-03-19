#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1005;
ll sieve[N];
ll prime[N];
int Euler(int n){
    int k = 0;
    for (int i=2;i<=n;i++){
        if (!sieve[i]){
            prime[k++] = i;
        }
        for (int j=0;j<k;j++){
            if (i * prime[j] > n) break;
            sieve[i * prime[j]] = 1;
            if (i % prime[j]==0) break;
        }
    }
    return k;
}
int main(){
    int n;
    cin >> n;
    ll dp[n+1];
    for (int i=0;i<=n;i++) dp[i] = 0;
    ll m = Euler(n);
    dp[0] = 1;
    for (int i=0;i<m;i++){
        for (int j=prime[i];j<=n;j++){
            dp[j] += dp[j-prime[i]];
        }
    }
    cout << dp[n] << '\n';
}