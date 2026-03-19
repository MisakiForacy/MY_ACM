#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e6+10;
int sieve[N];
int prime[N];
int Eular(int n){
    int k = 0;
    for (int i=2;i<=n;i++){
        if (!sieve[i]){
            prime[k++] = i;
        }   
        for (int j=0;j<k;j++){
            if (i * prime[j] > n) break;
            sieve[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }
    return k;
}
int main(){
    int T;
    cin >> T;
    Eular(1e6);
    while (T--){
        int n;
        cin >> n;
        vector<int> a(n+1,0),pre(n+1,0);
        for (int i=1;i<=n;i++){
            cin >> a[i];
            pre[i] = pre[i-1] + a[i];
        }
        int ans = INT_MAX;
        for (int i=0;i<=n;i++){
            for (int j=i+1;j<=n;j++){
                if (sieve[pre[j]-pre[i]]){
                    ans = min(ans,j-i-1);
                }
            }
        }
        cout << (ans == INT_MAX?-1:ans) << '\n';
    }
}