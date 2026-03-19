#include <bits/stdc++.h>

#define x first 
#define y second 

// #define double long double

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const int N = 1e5 + 5;
const double eps = 1e-12;

vector<int> P, S(N, 0);

void Euler() {
    for (int i = 2;i < N;i ++) {
        if (!S[i]) P.push_back(i);
        for (int j = 0;j < siz(P) && P[j] * i < N;j ++) {
            S[P[j] * i] = 1;
            if (i % P[j] == 0) break;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    auto cal = [&](char c) -> int {
        int Mi = n;
        vector<int> bad, use;
        for (int i = 0;i < n;i ++) {
            if ((i & 1) && s[i] == c) {
                bad.push_back(s[i]);
            } else if (!(i & 1) && s[i] != c) {
                bad.push_back(s[i]);
            }
        }
        // cout << "ok\n";
        for (int i = 0;i < siz(bad);) {
            int p = i, v = 0;
            while (i < siz(bad) && bad[i] == bad[p]) {
                i ++, v ++;
            }
            Mi = min(Mi, v);
            use.push_back(v);
        }
        queue<int> q;
        q.push(Mi);
        int ret = 0;
        while (siz(q)) {
            int v = q.front();
            // cout << v << '\n';
            q.pop();
            ret += v;
            // cout << "use : ";
            // for (int j = 0;j < siz(use);j ++) cout << use[j] << ' ';
            // cout << '\n';
            for (int j = 0;j < siz(use);j ++) {
                use[j] -= v;
            }
            int lst = -1, Mi = n;
            vector<int> newUse;
            for (int j = 0;j < siz(use);j ++) {
                if (use[j] != 0) {
                    if (lst == -1 || (lst & 1) != (j & 1)) {
                        newUse.push_back(use[j]);
                        lst = j;
                    } else if ((lst & 1) == (j & 1)) {
                        newUse.back() += use[j];
                    }
                }
            }
            use = newUse;
            if (siz(use)) {
                Mi = *min_element(all(use));
                q.push(Mi);
            }
        }

        // vector<int> f(m + 2, 0), nxt(m + 1, 0), pre(m + 1, 0);
        // for (int i = 1;i <= m;i ++) f[i] = i, nxt[i] = i + 1, pre[i] = i - 1;
        // auto find = [&](auto find, int x) -> int {
        //     if (f[x] == x) {
        //         f[x] = find(find, f[x]);
        //     }
        //     return f[x];
        // };
        // auto merge = [&](int u, int v) -> void {
        //     u = find(find, u);
        //     v = find(find, v);
        //     if (u == v) return;
        //     if (u > v) swap(u, v);
        //     f[u] = v, nxt[v] = nxt[u], pre[u] = pre[v];
        // };
        // queue<int> q;
        // q.push_back(Mi);
        // int ret = 0;
        // while (siz(q)) {
        //     int v = q.front();
        //     q.pop();
        //     ret += v;
        //     Mi = n;
        //     vector<int> ers;
        //     int j = 1;
        //     while (j <= m) {
        //         use[j] -= v;
        //         if (use[j] == 0) ers.push_back(j);
        //         j = nxt[j];
        //     }
        //     for (int i = 0;i < siz(ers);i ++) {
        //         merge(pre[ers[i]], nxt[ers[i]]);
        //         use[pre[ers[i]]] += use[nxt[ers[i]]];
        //     }
        //     j = 1;
        //     while (j <= m) {
        //         Mi = min(Mi, use[j]);
        //         j = nxt[j];
        //     }

        // }
        return ret;
    };

    cout << min(cal('0'), cal('1')) << '\n';
    // s = ' ' + s;
    // string t1 = " ", t2 = " ";
    // for (int i = 1;i <= n;i ++) {
    //     if (i & 1) t1 += '1', t2 += '0';
    //     else       t1 += '0', t2 += '1';
    // }
    // vector<int> s1, s2;
    // for (int i = 1;i <= n;i ++) {
    //     if (s[i] != t1[i]) s1.push_back(s[i] - '0');
    //     if (s[i] != t2[i]) s2.push_back(s[i] - '0');
    // }
    // // LL Mx1 = 0, Mx2 = 0, Mi = n;
    // // vector<int> vals;
    // // for (int i = 0;i < siz(s1);) {
    // //     LL v = 0, p = i;
    // //     while (i < siz(s1) && s1[i] == s1[p]) {
    // //         v ++, i ++;
    // //     }
    // //     Mi = min(Mi, v);
    // //     Mx1 = max(Mx1, v);
    // // }
    // // for (int i = 0;i < siz(s2);) {
    // //     LL v = 0, p = i;
    // //     while (i < siz(s2) && s2[i] == s2[p]) {
    // //         v ++, i ++;
    // //     }
    // //     Mx2 = max(Mx2, v);
    // // }
    // cout << min(Mx1, Mx2) << '\n';
}

int main() {
    // Euler();
    // cout << siz(P) << '\n';
    // cout << fixed << setprecision(10);
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}