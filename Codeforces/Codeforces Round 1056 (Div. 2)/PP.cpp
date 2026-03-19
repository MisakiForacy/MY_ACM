#include <bits/stdc++.h>
using namespace std;

const int MOD = 676767677;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        int ans = 0;
        // candidate k values
        vector<int> k_candidates = {a[1] - 1, a[1]};
        for (int k : k_candidates) {
            if (k < 0 || k > n) continue;
            int S_prev = 0;
            bool valid = true;
            for (int i = 1; i <= n; i++) {
                int T_i = i + k - a[i];
                int S_i = T_i - S_prev;
                if (S_i < S_prev || S_i > S_prev + 1 || S_i < 0 || S_i > n) {
                    valid = false;
                    break;
                }
                S_prev = S_i;
            }
            if (valid && S_prev == k) {
                ans = (ans + 1) % MOD;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}