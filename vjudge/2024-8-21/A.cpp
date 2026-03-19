#include <bits/stdc++.h>
using namespace std;
const int N = 1e8+5;
int sieve[N];
int prime[N];
void Euler(int n){
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
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,q,x;
    cin >> n >> q;
    Euler(n);
    while (q--){
        cin >> x;
        cout << prime[x-1] << '\n';
    }
}