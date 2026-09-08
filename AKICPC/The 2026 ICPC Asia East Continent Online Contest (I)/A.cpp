#include <bits/stdc++.h>

#define all(x) begin(x),end(x)

#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

const int inf = 1e8;

struct node
{
    char op;
    int x;
};

void solve() {
    int n;
    cin >> n;
    vector<node> p(n + 1);
    vector<char> a;
    map<int, vector<int>> mp;
    map<int, int> pos, have, posv;
    for (int i = 1;i <= n;i ++) {
        cin >> p[i].op >> p[i].x;
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
        posv[p[i].x] = inf;
    }
    for (auto &[k, v] : pos) v = 0;
    vector<int> stk(2 * n + 1, 0);
    int top = 0;
    for (int i = 1;i <= n;i ++) {
        // cout << "OK : " << i << '\n';
        if (posv[p[i].x] == inf && p[i].op == '+') {
            stk[++ top] = p[i].x;
            posv[p[i].x] = top;
            a.push_back(p[i].op);
            if (pos[p[i].x] + 1 < siz(mp[p[i].x])) {
                if (mp[p[i].x][pos[p[i].x] + 1] == 0 && mp[p[i].x][pos[p[i].x]] == 1) {
                    if (stk[top] == p[i].x) {
                        a.push_back('-');
                        top --;
                        posv[p[i].x] = inf;
                    }
                }
            } else if (stk[top] == p[i].x) {
                a.push_back('-');
                top --;
                posv[p[i].x] = inf;
            }
        } else if (p[i].op == '+') {
            while (posv[p[i].x] <= top) {
                a.push_back('-');
                top --;
            }
            posv[p[i].x] = inf;
            a.push_back(p[i].op);
            stk[++ top] = p[i].x;
            posv[p[i].x] = top;
        } else {
            if (p[i].op == 'T') {
                a.push_back('?');
                if (pos[p[i].x] + 1 < siz(mp[p[i].x])) {
                    if (mp[p[i].x][pos[p[i].x] + 1] == 0 && mp[p[i].x][pos[p[i].x]] == 1) {
                        if (stk[top] == p[i].x) {
                            a.push_back('-');
                            top --;
                            posv[p[i].x] = inf;
                        }
                    }
                } else if (stk[top] == p[i].x) {
                    a.push_back('-');
                    top --;
                    posv[p[i].x] = inf;
                }
            } else {
                while (posv[p[i].x] <= top) {
                    a.push_back('-');
                    top --;
                }
                posv[p[i].x] = inf;
                a.push_back('?');
            }
        }
        pos[p[i].x] ++;
    }
    for (char c : a) cout << c;
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}