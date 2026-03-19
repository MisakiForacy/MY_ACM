#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
typedef long long ll;

int prime[N];
bool sieve[N];

ll qpower(ll a,ll k){
    ll res = 1;
    while (k){
        if (k&1) res = res * a;
        a = a * a;
        k >>= 1;
    }
    return res;
}

int Euler(int n){
    int k = 0;
    for (int i=2;i<=n;i++){
        if (!sieve[i]){
            prime[k++] = i;
        }
        for (int j=0;j<k;j++){
            if (i * prime[j] > n) break;
            sieve[i * prime[j]] = 1;
            if (! (i % prime[j])) break;
        }
    }
    return k;
}

int main(){
    int n;
    cin >> n;
    int len = Euler(n);
    map<int,int>mp;
    for (int i=0;i<len;i++){
        int cnt = 0;
        for (int j=1;qpower(prime[i],j)<=n;j++){
            cnt += n/qpower(prime[i],j);
        }
        cout << prime[i] << ' ' << cnt << '\n';
    }
}