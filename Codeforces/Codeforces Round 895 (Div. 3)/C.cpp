#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define debug(x) cerr << #x << ':' << x << ' '
using namespace std;
using LL = long long;
const LL inf = LLONG_MAX;
const int N = 1e7 + 1;

int sieve[N];
int prime[N];
map<int,int> mp;
int Euler(int n){
    int k = 0;
    for (int i=2;i<=n;i++){
        if (!sieve[i]){
            prime[k++] = i;
            mp[i] = 1;
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
    int k = Euler(1e7);
    int T = 1;
    cin >> T;
    while (T --){
        int l,r;
        cin >> l >> r;
        int ok = 0;
        if (l != r){
            if (l % 2 == 0 && l - 2 > 0){
                ok = 1;
                cout << 2 << ' ' << l - 2 << '\n';
            } else if (l % 2 == 1 && l - 1 > 0){
                ok = 1;
                cout << 2 << ' ' << l - 1 << '\n';
            } else if (r % 2 == 0 && r - 2 > 0){
                ok = 1;
                cout << 2 << ' ' << r - 2 << '\n';
            } else if (r % 2 == 1 && r - 3 > 0){
                ok = 1;
                cout << 2 << ' ' << r - 3 << '\n';
            }
        } else{
            if (!mp[l]){
                for (int i = 0;prime[i] <= l;i ++){
                    if (l % prime[i] == 0){
                        cout << prime[i] << ' ' << l - prime[i] << '\n';
                        ok = 1;
                        break;
                    }
                }
            }
        }
        if (!ok){
            cout << -1 << '\n';
        }
   }
}