#include <bits/stdc++.h>

#define x first 
#define y second 

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

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
    string s, t;
    cin >> s >> t;
    int n = siz(s);
    init_strhash(n);
    Str_hash hs, ht;
    hs.init(s);
    ht.init(t);
    vector<vector<LL>> f(n + 1, vector<LL> (n + 1, 0));
    
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}