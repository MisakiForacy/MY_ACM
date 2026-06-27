#include <bits/stdc++.h>

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

const LL inf = 1e15;

struct node
{
    int x, y;
    char c;
};

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<char>> mp(n, vector<char> (m, ' '));
    vector<node> p(q);
    for (int i = 0;i < q;i ++) {
        cin >> p[i].x >> p[i].y >> p[i].c;
        p[i].x --;
        p[i].y --;
    }
    reverse(all(p));
    for (int t = 0;t < q;t ++) {
        for (int i = p[t].x;i >= 0;i --) {
            if (mp[i][p[t].y] != ' ') break;
            for (int j = p[t].y;j >= 0;j --) {
                if (mp[i][j] != ' ') break;
                mp[i][j] = p[t].c;
            }
        }
    }
    for (int i =  0;i < n;i ++) {
        for (int j = 0;j < m;j ++) {
            if (mp[i][j] == ' ') mp[i][j] = 'A';
        }
    }
    for (int i = 0;i < n;i ++) {
        for (int j = 0;j < m;j ++) {
            cout << mp[i][j];
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}