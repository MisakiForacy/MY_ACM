#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXA = 5e5 + 10;

vector<int> primes;
int spf[MAXA]; // smallest prime factor

void sieve() {
    for (int i = 2; i < MAXA; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > spf[i] || 1LL * i * p >= MAXA) break;
            spf[i * p] = p;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    sieve();
    
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        
        // 对于每个质数 p，记录 (位置, 指数) 的列表，但我们只需要每个位置的指数和总和
        // 由于 n 总和 1e5，a_i <= 5e5，可以用 map 或数组
        // 但更好的方法：对每个 a_i 分解，然后累加到质数上
        
        unordered_map<int, long long> sum_e; // p -> sum of exponents
        
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            
            // 分解 a
            while (a > 1) {
                int p = spf[a];
                int e = 0;
                while (a % p == 0) {
                    a /= p;
                    e++;
                }
                sum_e[p] += e;
            }
        }
        
        long long ans = 1;
        for (auto& [p, s] : sum_e) {
            ans = ans * (1 + s) % MOD;
        }
        
        cout << ans << "\n";
    }
    return 0;
}