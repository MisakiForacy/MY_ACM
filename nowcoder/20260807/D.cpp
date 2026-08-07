#include <bits/stdc++.h>

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

#define lowbit(x) ((x) & (-x))

using namespace std;

using LL = long long;

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> ans;
    vector<int> a(n + 1), b(n + 1), posa(n + 1), posb(n + 1), use(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i], posa[a[i]] = i;
    for (int i = 1;i <= n;i ++) cin >> b[i], posb[b[i]] = i;
    vector<int> f1(n + 1, 0), f2(n + 1, 0);
    auto upd1 = [&](int x) -> void {
        for (;x <= n;x += lowbit(x)) f1[x] ++;
    };
    auto upd2 = [&](int x) -> void {
        for (;x <= n;x += lowbit(x)) f2[x] ++;
    };
    auto qry1 = [&](int x) -> int {
        int sum = 0;
        for (;x;x -= lowbit(x)) sum += f1[x];
        return sum;
    };
    auto qry2 = [&](int x) -> int {
        int sum = 0;
        for (;x;x -= lowbit(x)) sum += f2[x];
        return sum;
    };
    auto case1 = [&](int i, int j) -> int {
        // 两者都在x前面
        // 去删相对位置差较小的那一项
        int pa_a = posa[a[i]] - qry1(posa[a[i]]);
        int pb_a = posb[a[i]] - qry2(posb[a[i]]);
        int pa_b = posa[b[j]] - qry1(posa[b[j]]);
        int pb_b = posb[b[j]] - qry2(posb[b[j]]);
        int pa_x = posa[x] - qry1(posa[x]);
        int pb_x = posb[x] - qry2(posb[x]);
        if (pa_a < pa_x && pb_a < pb_x && pa_b < pa_x && pb_b < pb_x) {
            if (abs(pa_a - pb_a) < abs(pa_b - pb_b) && a[i] != x) {
                // cout << "Erase : " << a[i] << '\n';
                // ans.push_back(a[i]);
                // use[a[i]] = 1;
                return 1;
            } else {
                // cout << "Erase : " << b[j] << '\n';
                // ans.push_back(b[j]);
                // use[b[j]] = 1;
                return 2;
            }
        }
        return 0; 
    };
    auto case2 = [&](int i, int j) -> int {
        // 假如其中某一项会在x后面出现，则删除均在x前方出现的那一项
        int pa_a = posa[a[i]] - qry1(posa[a[i]]);
        int pb_a = posb[a[i]] - qry2(posb[a[i]]);
        int pa_b = posa[b[j]] - qry1(posa[b[j]]);
        int pb_b = posb[b[j]] - qry2(posb[b[j]]);
        int pa_x = posa[x] - qry1(posa[x]);
        int pb_x = posb[x] - qry2(posb[x]);
        if (pa_a < pa_x && pb_a < pb_x && a[i] != x) {
            // cout << "Erase : " << a[i] << '\n';
            // ans.push_back(a[i]);
            // use[a[i]] = 1;
            return 1;
        }
        if (pa_b < pa_x && pb_b < pb_x) {
            // cout << "Erase : " << b[j] << '\n';
            // ans.push_back(b[j]);
            // use[b[j]] = 1;
            return 2;
        }
        return 0;
    };
    // auto case3 = [&](int i, int j) -> int {
        //     // 剩余情况即为两项都在x后面出现，则允许删除任意项，该操作都不会直接导致无解
        
        // };
    int i = 1, j = 1, cnt = 0, bad = 0;
    while (i <= n && j <= n) {
        if (bad) {
            cout << "NO\n";
            return;
        }
        while (i <= n && use[a[i]]) i ++;
        while (j <= n && use[b[j]]) j ++;
        // cout << i << ' ' << j << ' ' << a[i] << ' ' << b[j] << '\n';
        // if (a[i] == b[j] && a[i] != x || i != n || j != n) {
        //     cout << "NO\n";
        //     return;
        // }
        if (a[i] == b[j] && (a[i] != x || cnt != n - 1)) {
            cout << "NO\n";
            return;
        }
        if (cnt == n - 1) break;
        if (i == n && j == n && a[i] == x) break;
        if (case1(i, j)) {
            if (case1(i, j) == 1) {
                // cout << "Erase1 a : " << a[i] << '\n';
                if (a[i] == x) bad = 1;
                cnt ++;
                ans.push_back(a[i]);
                use[a[i]] = 1;
                upd1(posa[a[i]]);
                upd2(posb[a[i]]);
                i ++;
            } else {
                // cout << "Erase1 b : " << b[j] << '\n';
                if (b[j] == x) bad = 1;
                cnt ++;
                ans.push_back(b[j]);
                use[b[j]] = 1;
                upd1(posa[b[j]]);
                upd2(posb[b[j]]);
                j ++;
            }
        } else if (case2(i, j)) {
            if (case2(i, j) == 1) {
                // cout << "Erase2 a : " << a[i] << '\n';
                if (a[i] == x) bad = 1;
                cnt ++;
                ans.push_back(a[i]);
                use[a[i]] = 1;
                upd1(posa[a[i]]);
                upd2(posb[a[i]]);
                i ++;
            } else {
                // cout << "Erase2 b : " << b[j] << '\n';
                if (b[j] == x) bad = 1;
                cnt ++;
                ans.push_back(b[j]);
                use[b[j]] = 1;
                upd1(posa[b[j]]);
                upd2(posb[b[j]]);
                j ++;
            }
        } else {
            // 考虑两者都存在在x后面出现，那就随便删
            if (a[i] == x) {
                // cout << "Erase3 b : " << b[j] << '\n';
                if (b[j] == x) bad = 1;
                cnt ++;
                ans.push_back(b[j]);
                use[b[j]] = 1;
                upd1(posa[b[j]]);
                upd2(posb[b[j]]);
                j ++;
            } else {
                // cout << "Erase3 a : " << a[i] << '\n';
                if (a[i] == x) bad = 1;
                cnt ++;
                ans.push_back(a[i]);
                use[a[i]] = 1;
                upd1(posa[a[i]]);
                upd2(posb[a[i]]);
                i ++;
            }
        }
    }
    cout << "YES\n";
    for (auto x : ans) cout << x << ' ';
    cout << '\n';
}



int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}