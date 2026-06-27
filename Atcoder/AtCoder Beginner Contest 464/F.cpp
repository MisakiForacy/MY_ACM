#include <bits/stdc++.h>

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

const LL inf = 1e15;

const LL mod = 998244353;

bitset<50> L, R;
map<LL, vector<bitset<50>>> mpl, mpr;

int li, ri;
vector<LL> a(50), cnt(50, 0);

void dfs1(int idx, int cnt, LL sum, bitset<50> cur) {
    if (cnt == li) {
        mpl[sum].push_back(cur);
        return;
    }
    bitset<50> tp = cur;
    tp.set(idx);
    dfs1(idx + 1, cnt + 1, sum + a[idx], tp);
    dfs1(idx + 1, cnt + 1, sum, cur);
}

void dfs2(int idx, int cnt, LL sum, bitset<50> cur) {
    if (cnt == ri) {
        mpl[sum].push_back(cur);
        return;
    }
    bitset<50> tp = cur;
    tp.set(idx);
    dfs2(idx - 1, cnt + 1, sum + a[idx], tp);
    dfs2(idx - 1, cnt + 1, sum, cur);
} 
    
LL inv(LL a, LL k = mod - 2) {
    LL res = 1;
    while (k) {
        if (k & 1) res = res * a % mod;
        a = a * a % mod;
        k >>= 1;
    }
    return res;
}

void solve() {
    LL n, x;
    cin >> n >> x;
    for (int i = 0;i < n;i ++) cin >> a[i];
    li = n / 2, ri = n - li;
    bitset<50> use;
    use.reset();
    dfs1(0, 0, 0, use);
    use.reset();
    dfs2(n - 1, 0, 0, use);
    LL ccnt = 0;
    for (auto [kl, vl] : mpl) {
        for (auto [kr, vr] : mpr) {
            if (kl + kr >= x) {
                for (bitset<50> t1 : vl) {
                    for (bitset<50> t2 : vr) {
                        bitset<50> tp = t1 | t2;
                        LL sum = 0;
                        for (int i = 0;i < n;i ++) {
                            if (tp[i]) {
                                sum += a[i];
                                cnt[i] ++;
                                if (sum >= x) break;
                            }
                        }
                        ccnt ++;
                    }
                }
            }
        }
    }
    LL Sum = 0;
    for (int i = 0;i < n;i ++) {
        Sum += cnt[i] * a[i] % mod;
        Sum %= mod;
    }  
    Sum *= inv(ccnt);
    Sum 
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}