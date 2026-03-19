#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define x first
#define y second
using namespace std;
using LL = long long;

const LL inf = 1e15;
const int N = 2e5;

const char d[] = {'N', 'E', 'S', 'W'};
map<char, int> mp;

/*
1
2
S 2
E 1
*/

void solve() {
    mp['N'] = 0, mp['E'] = 1, mp['S'] = 2, mp['W'] = 3;
    int n;
    cin >> n;
    vector<pair<char, int>> p;
    for (int i = 0;i < n;i ++) {
        char c;
        int x;
        cin >> c >> x;
        p.push_back({c, x});
    }
    int cur = mp[p[0].x];
    int beg = cur;
    vector<pair<char, int>> ans;
    for (int i = 0;i < n;i ++) {
        // while (cur != mp[p[i].x]) {
        //     cur ++;
        //     cur %= 4;
        //     ans.push_back({'R', -1});
        //     // cout << 1 << '\n';
        // }
        if ((cur + 1) % 4 == mp[p[i].x]) {
            cur = (cur + 1) % 4;
            ans.push_back({'R', -1});
        }
        if ((cur + 3) % 4 == mp[p[i].x]) {
            cur = (cur + 3) % 4;
            ans.push_back({'L', -1});
        }
        // cout << cur << ' ' << mp[p[i].x] << '\n';
        if (cur == mp[p[i].x]) {
            ans.push_back({'Z', p[i].y});
        }
    }
    cout << siz(ans) << ' ' << d[beg] << '\n';
    for (auto [k, v] : ans) {
        if (k == 'R' || k == 'L') {
            cout << k << '\n';
        } else {
            cout << k << ' ' << v << '\n';
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        solve();
    }
}