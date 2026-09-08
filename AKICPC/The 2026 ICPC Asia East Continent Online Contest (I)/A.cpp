#include <bits/stdc++.h>

#define all(x) begin(x),end(x)

#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

struct node
{
    char op;
    int x;
};

void solve() {
    int n;
    cin >> n;
    vector<node> p(n + 1);
    vector<char> a(2 * n + 1, ' ');
    map<int, vector<int>> mp;
    map<int, int> pos, have;
    for (int i = 1;i <= n;i ++) {
        cin >> p[i].op >> p[i].x;
        a[i * 2 - 1] = (p[i].op == '+' ? '+' : '?');
        if (p[i].op == 'T' || (p[i].op != 'F' && mp[p[i].x].empty()))
            mp[p[i].x].push_back(1);
        else {
            if (p[i].op == '+' && mp[p[i].x][pos[p[i].x] - 1] == 0) {
                mp[p[i].x].push_back(1);
            } else {
                mp[p[i].x].push_back(0);
            }
        }
        pos[p[i].x] ++;
    }
    for (auto &[k, v] : pos) v = 0;
    for (int i = 1;i <= n;i ++) {
        int cur = p[i].x;
        if (pos[cur] + 1 < siz(mp[cur])) {
            int x = 2 * mp[cur][pos[cur] + 1];
            int y = mp[cur][pos[cur]];
            int res = x + y;
            if (res == 1) {
                a[2 * i] = '-';
            }
            pos[cur] ++;
        }
    }
    for (int i = 1;i <= 2 * n;i ++) {
        if (a[i] == ' ') continue;
        cout << a[i];
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}