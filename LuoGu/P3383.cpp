#include <bits/stdc++.h>
using namespace std;
vector<int> sieve(1e8+5,0);
vector<int> pri;
void Era(int n){
    sieve[1] = 1;
    for (int i=2;i*i<=n;i++){
        if (!sieve[i]){
            for (int j=i*i;j<=n;j+=i){
                sieve[j] = 1;
            }
        }
    }
    for (int i=2;i<=n;i++){
        if (!sieve[i]){
            pri.push_back(i);
        }
    }
}
void Euler(int n){
    for (int i=2;i<=n;i++){
        if (!sieve[i]){
            pri.push_back(i);
            
        }
        for (auto j:pri){
            if (j * i > n) break;
            sieve[i * j] = 1;
            if (i % j == 0){
                break;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n,q,x;
    cin >> n >> q;
    // Era(n);
    Euler(n);
    while (q--){
        cin >> x;
        cout << pri[x-1] << '\n';
    }
}