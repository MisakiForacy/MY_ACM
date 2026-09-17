#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

void solve() {
    int64 L, R, K;
    cin >> L >> R >> K;
    int64 maxN = 0;
    for (int64 t = K; t > 0; t >>= 1) {
        ++maxN;
    }

    vector<int64> ans;
    const int LIMIT = 100000;

    for (int64 l = 1; l <= R; ) {
        int64 a = R / l;
        int64 b = (L - 1) / l;

        int64 r = R / a;
        if (b > 0) {
            r = min(r, (L - 1) / b);
        }

        int64 n = a - b;

        if (1 <= n && n <= maxN) {
            int64 power = 1LL << (n - 1);

            if (K % power == 0) {
                int64 numerator = (int64)2 * (K / power);
                int64 denominator = ((int64)a + b + 1) * n;

                if (numerator % denominator == 0) {
                    int64 x = numerator / denominator;

                    if ((int64)l <= x && x <= (int64)r) {
                        ans.emplace_back((int64)x);

                        if (ans.size() > LIMIT) {
                            cout << "Too Many!\n";
                            return;
                        }
                    }
                }
            }
        }

        l = r + 1;
    }

    if (ans.empty()) {
        cout << "No Solution\n";
        return;
    }

    // 分块按从小到大遍历，答案天然递增。
    cout << ans.size() << '\n';
    for (size_t i = 0; i < ans.size(); ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) solve();

    return 0;
}