#include <bits/stdc++.h>

using namespace std;
using LL = long long;

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> m >> n;
    vector<int> p(n + 1);
    auto ask = [&](int x) -> int {
        cout << x << '\n';
        int ret; cin >> ret;
        if (ret == 0) exit(0);
        return ret;
    };
    for (int i = 1;i <= n;i ++) p[i] = (ask(1) == -1);
    for (int i = 1;i <= n;i ++) if (!p[i]) p[i] = -1;
    int Lo = 1, Hi = m, Step = 1, Ans;
    while (Lo <= Hi) {
        int Mid = Lo + Hi >> 1;
        int ret = ask(Mid) * p[Step];
        if (ret == 0) {
            Ans = Mid;
            break;
        } else if (ret ==  1) {
            Hi = Mid - 1;
        } else if (ret == -1) {
            Lo = Mid + 1;
        }
        Step += 1;
        if (Step > n) Step -= n;
    }
    cout << Ans << '\n';
}