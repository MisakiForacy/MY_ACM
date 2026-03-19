#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((LL)x.size())
#define lowbit(x) ((x) & (-x))
#define nl cout << '\n';
#define debug(x) cerr << #x << ':' << x << ' '
#define x first
#define y second
using namespace std;
using LL = long long;

const LL N = 2e5 + 10;
const LL inf = 1e15;

mt19937_64 rng(time(0));

void fxy_ac() {
    int n;
    string s;
    cin >> n >> s;
    LL A = 0, B = 0;
    for (int i = 0;i < n;i ++) {
        if (s[i] == 'a') A ++;
        else B ++;
    }
    if (A == B) {
        cout << 0 << '\n';
        return;
    }
    LL d = A - B;
    map<LL, LL> mp;
    mp[0] = -1;
    LL cur = 0;
    LL Min = inf;
    for (int i = 0;i < n;i ++) {
        if (s[i] == 'a') cur += 1;
        else cur -= 1;
        LL val = cur - d;
        if (mp.count(val)) {
            LL len = i - mp[val];
            if (len < Min) {
                Min = len;
            }
        }
        mp[cur] = i;
    }
    if (Min != inf && Min != n) {
        cout << Min << '\n';
    } else {
        cout << -1 << '\n';
    }
}

void brute() {

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        fxy_ac();
        // brute();
    }
}