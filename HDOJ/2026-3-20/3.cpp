#include <bits/stdc++.h>

using namespace std;
using LL = long long;

typedef pair<int, int> pii;
const int mod1 = 1e9 + 7;
const int mod2 = 1e9 + 9;
vector<pii> pw;
pii base;
mt19937 rnd(time(0));
pii operator+(const pii& a, const pii& b) {
    int c1 = a.fi + b.fi, c2 = a.se + b.se;
    if (c1 >= mod1) c1 -= mod1;
    if (c2 >= mod2) c2 -= mod2;
    return { c1, c2 };
}
pii operator-(const pii& a, const pii& b) {
    int c1 = a.fi - b.fi, c2 = a.se - b.se;
    if (c1 < 0) c1 += mod1;
    if (c2 < 0) c2 += mod2;
    return { c1, c2 };
}
pii operator*(const pii& a, const pii& b) {
    return { 1LL * a.fi * b.fi % mod1, 1LL * a.se * b.se % mod2 };
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

int main() {
    
}