#include <bits/stdc++.h>

#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void solve() {
    int n;
    cin >> n;
    deque<int> p(n, 0), a, b, ans, pp;
    for (int i = 0;i < n;i ++) cin >> p[i];
    pp = p;
    if (p.back() > p.front()) {
        a.push_back(p.back());
        p.pop_back();
    } else {
        a.push_front(p.front());
        p.pop_front();
    }
    while (siz(p)) {
        if (p.back() > p.front()) {
            a.push_front(p.front());
            p.pop_front();
        } else {
            a.push_back(p.back());
            p.pop_back();
        }
    }
    b = a, ans = a;
    deque<int> ta, tb;
    while (siz(a) > 1) {
        if (a.back() < a.front()) {
            ta.push_back(a.back());
            a.pop_back();
        } else {
            ta.push_front(a.front());
            a.pop_front();
        }
    }
    ta.push_back(a.back());
    while (siz(b) > 1) {
        if (b.back() < b.front()) {
            tb.push_back(b.back());
            b.pop_back();
        } else {
            tb.push_front(b.front());
            b.pop_front();
        }
    }
    tb.push_front(b.back());
    // for (int x : ta) cout << x << ' ';
    // cout << '\n';
    // for (int x : tb) cout << x << ' ';
    // cout << '\n';
    if (ta == pp || tb == pp) {
        for (int x : ans) cout << x << ' ';
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}