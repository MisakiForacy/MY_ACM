#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int sieve[N];
int prime[N];
int Euler(int n){
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
    Euler(2e6+5);
    while (T--){
        int n;
        cin >> n;
        if (n!=1){
            int lo = 0, hi = 148934;
            while (lo <= hi){
                int mid = (lo + hi) / 2;
                if (prime[mid] <= n) lo = mid + 1;
                else hi = mid - 1;
            }
            cout << prime[lo-1] << '\n';
        } else{
            cout << 1 << '\n';
        }
    }
}