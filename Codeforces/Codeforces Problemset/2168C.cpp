#include <bits/stdc++.h>
using namespace std;
using LL = long long;

void runA() {
    int x;
    cin >> x;
    vector<int> use, p(21, 0), s(16, 0);
    x -= 1;
    for (int i = 0;i < 15;i ++) {
        s[i] = (x >> i & 1);
    }
    int px = 1;
    for (int i = 0;i < 15;i ++) {
        while (__builtin_popcount(px) == 1) px ++;
        p[px] = s[i];
        px ++;
    }
    for (int i = 1;i <= 20;i ++) {
        if (__builtin_popcount(i) == 1) {
            for (int j = 1;j <= 20;j ++) {
                if (j & i) {
                    p[i] ^= p[j];
                }
            }
        }
    }
    for (int i = 1;i <= 20;i ++) if (p[i]) use.push_back(i);
    cout << use.size() << '\n';
    for (int x : use) cout << x << ' ';
    cout << '\n';
}

void runB() {
    int n;
    cin >> n;
    vector<int> a(n + 1), p(21, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i], p[a[i]] = 1;
    int bad = 0;
    for (int i = 1;i <= 20;i ++) {
        if (__builtin_popcount(i) == 1) {
            int use = 0;
            for (int j = 1;j <= 20;j ++) {
                if (j & i) {
                    use ^= p[j];
                }
            }
            if (use) bad += i;
        }
    }
    p[bad] = !p[bad];
    int px = 0;
    int ret = 0;
    for (int i = 1;i <= 20;i ++) {
        if (__builtin_popcount(i) == 1) continue;
        if (p[i]) ret += 1LL << px;
        px ++;
    }
    ret += 1;
    cout << ret << '\n';
}

int main() {
    int x = -3, y = 2;
    cout << ~x << ' ' << ~y << '\n';
    string R;
    int T;
    cin >> R >> T;
    while (T --) {
        if (R == "first") {
            runA();
        } else {
            runB();
        }
    }
}