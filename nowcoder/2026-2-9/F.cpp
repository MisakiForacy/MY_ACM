#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
 
using namespace std;
using LL = long long;

const LL inf = 1e15;

void solve() {
    int a, b;
    cin >> a >> b;
    auto check = [&](string t) -> LL {
        LL S = 0;
        for (int i = 1;i <= siz(t);i ++) {
            for (int j = 0;j < siz(t) - i + 1;j ++) {
                string ss = t.substr(j, i);
                // cout << ss << '\n';
                if (ss.find('1') == -1) {
                    S += 1;
                } else if (ss.find('0') == -1) {
                    S += 0;
                } else {
                    S += 2;
                }
            }
        }
        // cout << S << '\n';
        return S;
    };
    // cout << "Dbg : \n";
    // cout << check("001001010") << ' ' << check("001010100") << '\n';
    int k1 = min(b, a + 1);
    int k2 = min(a, k1 + 1);
    auto split = [&](int cnt, int runs) {
        vector<int> use(runs, 0);
        if (runs == 0) return use;
        int base = cnt / runs;
        int rem = cnt % runs;
        for (int i = 0; i < runs; i++) {
            use[i] = base + (i < rem ? 1 : 0);
        }
        return use;
    };
    vector<int> x = split(a, k2), y = split(b, k1);
    char c;
    if (k2 == k1 + 1) c = '0';
    else if (k1 == k2 + 1) c = '1';
    else c = '0';
    string s;
    s.reserve(a + b);
    int m = max(k2, k1);
    for (int i = 0;i < m;i ++) {
        if (c == '0') {
            if (i < k2) s.append(x[i], '0');
            if (i < k1) s.append(y[i], '1');
        } else {
            if (i < k1) s.append(y[i], '1');
            if (i < k2) s.append(x[i], '0');
        }
    }
    cout << check(s) << '\n';
    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}