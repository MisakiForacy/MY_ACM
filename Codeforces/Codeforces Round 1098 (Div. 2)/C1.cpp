#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

const LL inf = 1e18;

void solve() {
    LL a, Down = 0, Up = 0, ans = inf;
    int n;
    cin >> a >> n;
    vector<LL> d(n), p10(19);
    p10[0] = 1;
    for (int i = 0;i < n;i ++) cin >> d[i];
    for (int i = 1;i <= 18;i ++) p10[i] = p10[i - 1] * 10;
    sort(all(d));
    string sa = to_string(a);
    int id1 = upper_bound(all(d), sa[0] - '0') - d.begin() - 1; 
    int id2 = lower_bound(all(d), sa[0] - '0') - d.begin(); 
    id1 = max(0, id1);
    id2 = min(n - 1, id2);
    // cout << id1 << ' ' << id2 << '\n';
    // cout << d[id1] << ' ' << p10[siz(sa) - 1] << ' ';
    Down += d[id1] * p10[siz(sa) - 1], Up += d[id2] * p10[siz(sa) - 1];
    // cout << Down << ' ' << Up << '\n';
    int f1 = 0, f11 = 1, f2 = 0, f22 = 1;
    if (d[id1] < sa[0] - '0') f1 = 1;
    if (d[id2] > sa[0] - '0') f2 = 1;
    if (d[id1] > sa[0] - '0') f11 = 0;
    if (d[id1] < sa[0] - '0') f22 = 0;
    cout << f1 << ' ' << f2 << ' ' << f11 << ' ' << f22 << '\n';
    for (int i = 1;i < siz(sa);i ++) {
        int j = siz(sa) - i - 1;
        if (f1 && f11) {
            Down += d[n - 1] * p10[j];
        } else if (!f11) {
            int id = lower_bound(all(d), sa[i] - '0') - d.begin();
            id = min(n - 1, id);
            Down += d[id] * p10[j];
        } else {
            int id = upper_bound(all(d), sa[i] - '0') - d.begin() - 1;
            id = max(0, id);
            Down += d[id] * p10[j];
            if (d[id] < sa[i] - '0') f1 = 1;
            if (d[id] > sa[i] - '0') f11 = 0;
        }
        if (f2 && f22) {
            Up += d[0] * p10[j];
        } else if (!f22) {
            int id = upper_bound(all(d), sa[i] - '0') - d.begin() - 1;
            id = max(0, id);
            Up += d[id] * p10[j];
        } else {
            int id = lower_bound(all(d), sa[i] - '0') - d.begin();
            // cout << id << ' ';
            id = min(n - 1, id);
            Up += d[id] * p10[j];
            if (d[id] > sa[i] - '0') f2 = 1;
            if (d[id] < sa[i] - '0') f22 = 0;
        }
        // cout << '\n';
        // cout << Down << ' ' << Up << '\n';
    }
    ans = min(ans, abs(Down - a));
    ans = min(ans, abs(Up - a));
    // cout << "ok\n";
    LL Up1 = 0, Down1 = 0;
    for (int i = 0;i < siz(sa);i ++) {
        Down1 *= 10;
        Down1 += d[n - 1];
        ans = min(ans, abs(Down1 - a));
    }
    for (int i = 0;i <= siz(sa);i ++) {
        if (i == 0 && d[0] == 0) {
            Up1 += d[min(n - 1, 1)];
        } else {
            Up1 *= 10;
            Up1 += d[0];
        }
        ans = min(ans, abs(Up1 - a));
    }
    // cout << Down << ' ' << Up << ' ' << Down1 << ' ' << Up1 << '\n';
    cout << ans << '\n';
    // cout << min({abs(Down - a), abs(Up - a), abs(Down1 - a), abs(Up1 - a)}) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}