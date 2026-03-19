#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void runA() {
    int n;
    cin >> n;
    vector<LL> a(n + 1, 0), pos(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i], pos[a[i]] = i;
    if (pos[n] > pos[1]) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
}

void runB() {
    int n, x;
    cin >> n >> x;
    int l = 1, r = n;
    auto ask = [&](int l, int r) -> int {
        cout << "? " << l << ' ' << r << '\n';
        int ret; cin >> ret;
        return ret;
    };
    for (int j = 14;j >= 0;j --) {
        int tmp = l + (1LL << j);
        if (tmp >= r) continue;
        if (ask(tmp, r) != n - 1) continue;
        l = tmp;
    }
    for (int j = 14;j >= 0;j --) {
        int tmp = r - (1LL << j);
        if (tmp <= l) continue;
        if (ask(l, tmp) != n - 1) continue;
        r = tmp;
    }
    if (x == 1) {
        cout << "! " << r << '\n';
    } else {
        cout << "! " << l << '\n';
    }
}

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    string R;
    cin >> R;
    int T;
    cin >> T;
    while (T --) {
        if (R == "first") {
            runA();
        } else {
            runB();
        }
    }
}