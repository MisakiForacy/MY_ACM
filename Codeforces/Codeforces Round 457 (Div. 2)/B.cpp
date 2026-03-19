#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

using PII = pair<LL, LL>;

int popcount(LL n) {
    int cnt = 0;
    while (n) {
        if (n & 1) cnt ++;
        n /= 2;
    }
    return cnt;
}

void solve() {
    LL n, k;
    cin >> n >> k;
    int m = popcount(n);
    if (m > k) {
        cout << "No\n";
        return;
    } else {
        for (int Up = -30;Up <= 60;Up ++) {
            int Mx;
            for (int j = 0;j <= 60;j ++) if (n >> j & 1) Mx = j;
            if (Up > Mx) break;
            int M = m, K = k;
            if (Up < 0) {
                LL Tmp = Up, bad = 0, N = n;
                while (Tmp ++) {
                    N *= 2;
                    if (K < N) {
                        bad = 1;
                        break;
                    }
                }
                if (bad) continue;
                cout << "Yes\n";
                if (K == n * (1LL << -Up)) {
                    for (int i = 1;i <= K;i ++) cout << Up << ' ';
                    cout << '\n';
                } else {
                    // cout << "ok\n";
                    // cout << K << '\n';
                    int At_MOST_Need = (1ll << (-Up)) * n;
                    for (int i = 1;i < At_MOST_Need;i ++) {
                        cout << Up << ' ';
                        K --;
                    }
                    Up --;
                    while (K > 2) {
                        cout << Up << ' ';
                        K --, Up --;
                    }
                    cout << Up << ' ' << Up << '\n';
                }
            } else {
                LL Upper = 0;
                for (int j = 60;j >= Up;j --) if (n >> j & 1) {
                    Upper += 1LL << j;
                    M --;
                }
                LL Need = Upper / (1LL << Up);
                /* LL Need = n / (1LL << Up); M -= __builtin_popcountll(Need); */
                
                // cout << Up << ' ' << Need << ' ' << M << '\n';
                if (K - Need < M || Need > K) continue;
                vector<LL> Ans;
                // cout << K - Need << ' ' << M << '\n';
                if (K - Need == M) {
                    for (int i = 1;i <= Need;i ++) Ans.push_back(Up);
                    for (int j = Up - 1;j >= 0;j --) if (n >> j & 1) Ans.push_back(j);
                    if (siz(Ans) != k) continue;
                } else {
                    // cout << Up << ' ';
                    if (M) {
                        for (int i = 1;i <= Need;i ++) Ans.push_back(Up);
                        K -= Need;
                        // cout << Need << '\n';
                        int Low;
                        for (int j = 60;j >= 0;j --) if (n >> j & 1) Low = j;
                        for (int j = Up - 1;j >= 0;j --) {
                            if (j == Low) break;
                            if (n >> j & 1){
                                Ans.push_back(j);
                                K --, M --;
                            }
                        }
                        Low -= 1;
                        // cout << Low << '\n';
                        while (K > 2) {
                            Ans.push_back(Low);
                            K --, Low --;
                        }
                        Ans.push_back(Low), Ans.push_back(Low);
                        cout << "Yes\n";
                        for (int x : Ans) cout << x << ' ';
                        cout << '\n';
                        return;
                    } else {
                        for (int i = 1;i <= Need - 1;i ++) Ans.push_back(Up);
                        K -= Need - 1, Up -= 1;
                        while (K > 2) {
                            Ans.push_back(Up);
                            K --, Up --;
                        }
                        Ans.push_back(Up), Ans.push_back(Up);
                    }
                    if (siz(Ans) != k) continue;
                    // cout << "ok\n";
                }
                cout << "Yes\n";
                for (LL x : Ans) cout << x << ' ';
                cout << '\n';
                return;
                // cout << Ans[56843] << '\n';
            }
            return;
        }
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}