#include <bits/stdc++.h>
using namespace std;

using int64 = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    int64 w;
    cin >> n >> w;

    vector<long double> x(n), y(n);
    long double sumY = 0;
    for (int i = 0; i < n; ++i) {
        int64 xi, yi;
        cin >> xi >> yi;
        x[i] = (long double)xi;
        y[i] = (long double)yi;
        sumY += y[i];
    }

    // R = 需要保留的总“可磨边长度”之和
    long double R = sumY - (long double)w;
    if (R <= 0) {
        // 全部可磨到 0，斜边退化为 x
        long double ans = 0;
        for (int i = 0; i < n; ++i) ans += x[i];
        cout << fixed << setprecision(12) << (double)ans << '\n';
        return 0;
    }

    // 令 z_i = min(y_i, k * x_i), 需要 sum z_i = R，二分 k >= 0
    auto calcSumZ = [&](long double k) -> long double {
        long double s = 0;
        for (int i = 0; i < n; ++i) {
            long double zi = k * x[i];
            if (zi > y[i]) zi = y[i];
            s += zi;
        }
        return s;
    };

    long double lo = 0, hi = 1;
    while (calcSumZ(hi) < R) hi *= 2;  // 扩上界

    for (int it = 0; it < 100; ++it) {
        long double mid = (lo + hi) * 0.5L;
        if (calcSumZ(mid) >= R) hi = mid;
        else lo = mid;
    }

    long double k = hi;
    long double ans = 0;
    for (int i = 0; i < n; ++i) {
        long double zi = k * x[i];
        if (zi > y[i]) zi = y[i];
        ans += sqrtl(x[i] * x[i] + zi * zi);
    }

    cout << fixed << setprecision(12) << (double)ans << '\n';
    return 0;
}