#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

struct node
{
    string s;
    int x;
};

void solve() {
    int n;
    cin >> n;
    vector<node> p(n);
    int mx = 0;
    string use;
    for (int i = 0;i < n;i ++) {
        cin >> p[i].s >> p[i].x;
        if (p[i].x > mx) {
            mx = p[i].x;
            use = p[i].s;
        }
    }
    if (mx == 4) {
        cout << use << '\n';
        return;
    } else if (mx == 3) {
        for (int x = 0;x < 4;x ++) {
            string used = use;
            for (int j = 0;j < 10;j ++) {
                used[x] = j + '0';
                int ok = 1;
                for (int t = 0;t < n;t ++) {
                    int cnt = 0;
                    for (int jj = 0;jj < 4;jj ++) {
                        if (p[t].s[jj] == used[jj]) cnt ++;
                    }
                    if (cnt != p[t].x) ok = 0;
                    if (!ok) break;
                }
                if (ok) {
                    cout << used << '\n';
                    return;
                }
            }
        }
    } else if (mx == 2) {
        for (int x = 1;x < 4;x ++) {
            for (int y = 0;y < x;y ++) {
                string used = use;
                for (int j = 0;j < 100;j ++) {
                    used[x] = j / 10 % 10 + '0';
                    used[y] = j % 10 + '0';
                    int ok = 1;
                    for (int t = 0;t < n;t ++) {
                        int cnt = 0;
                        for (int jj = 0;jj < 4;jj ++) {
                            if (p[t].s[jj] == used[jj]) cnt ++;
                        }
                        if (cnt != p[t].x) ok = 0;
                        if (!ok) break;
                    }
                    if (ok) {
                        cout << used << '\n';
                        return;
                    }
                }
            }
        }
    } else if (mx == 1) {
        for (int i = 0;i < 10000;i ++) {
            int ok = 1;
            for (int j = 0;j < n;j ++) {
                int cnt = 0;
                if (i / 1000 % 10 + '0' == p[j].s[0]) cnt ++;
                if (i / 100 % 10 + '0' == p[j].s[1]) cnt ++;
                if (i / 10 % 10 + '0' == p[j].s[2]) cnt ++;
                if (i / 1 % 10 + '0' == p[j].s[3]) cnt ++;
                if (cnt != p[j].x) {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                string used = to_string(i);
                while (siz(used) < 4) used = '0' + used;
                cout << used << '\n';
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}