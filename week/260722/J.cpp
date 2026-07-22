#include <bits/stdc++.h>

#define x first 
#define y second

using namespace std;

using LL = long long;

typedef pair<int, int> pii;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
vector<pii> pw;
pii base;
mt19937 rnd(time(0));
pii operator+(const pii& a, const pii& b) {
    int c1 = a.x + b.x, c2 = a.y + b.y;
    if (c1 >= mod1) c1 -= mod1;
    if (c2 >= mod2) c2 -= mod2;
    return { c1, c2 };
}
pii operator-(const pii& a, const pii& b) {
    int c1 = a.x - b.x, c2 = a.y - b.y;
    if (c1 < 0) c1 += mod1;
    if (c2 < 0) c2 += mod2;
    return { c1, c2 };
}
pii operator*(const pii& a, const pii& b) {
    return { 1LL * a.x * b.x % mod1, 1LL * a.y * b.y % mod2 };
}
void init_strhash(int lim = 0) {
    pw = vector<pii>(lim + 1);
    base = { rnd() % mod1, rnd() % mod2 };
    pw[0] = { 1, 1 };
    for (int i = 1; i <= lim; i++) pw[i] = pw[i - 1] * base;
}
struct Str_hash {
    vector<pii> v;
    Str_hash() {}
    void init(const string& s) {
        int m = s.size();
        v.resize(m + 1);
        for (int j = 1; j <= m; j++) {
            char ch = s[j - 1];
            v[j] = v[j - 1] * base + make_pair(ch, ch);
        }
    }
    pii get(int L, int R) {
        return v[R] - (v[L - 1] * pw[R - L + 1]);
    }
};

void solve() {
    int n;
    cin >> n;
    map<pii, int> mp;
    vector<string> p(n);
    for (int i = 0;i < n;i ++) {   
        cin >> p[i];
        Str_hash x;
        x.init(p[i]);
        mp[x.get(1, p[i].size())] ++;
    }
    for (int i = 0;i < n;i ++) {
        Str_hash x;
        x.init(p[i]);
        int ok = 0;
        for (int j = 0;j < p[i].size() - 1;j ++) {
            pii L = x.get(i + 1, j + 1);
            pii R = x.get(j + 2, p[i].size());
            if (mp.count(L) && mp.count(R)) {
                ok = 1;
                break;
            }
        }
        cout << (ok ? "1" : "0");
    }
    cout << '\n';
}

int main() {
    init_strhash(10);
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}
