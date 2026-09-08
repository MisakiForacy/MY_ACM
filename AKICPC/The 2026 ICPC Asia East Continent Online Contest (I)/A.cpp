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
    map<int, int> pos, posv;
    for (int i = 1;i <= n;i ++) {
        cin >> p[i].op >> p[i].x;
        if (p[i].op == 'T' || (p[i].op == '+' && mp[p[i].x].empty()))
            mp[p[i].x].push_back(1);
        else {
            if (p[i].op == '+' && mp[p[i].x][pos[p[i].x] - 1] == 0) {
                mp[p[i].x].push_back(1);
            } else {
                if (p[i].op == '+') {
                    mp[p[i].x].push_back(2);
                } else {
                    mp[p[i].x].push_back(0);
                }
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
                if (mp[p[i].x][pos[p[i].x] + 1] != 1 && mp[p[i].x][pos[p[i].x]] >= 1) {
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
                posv[stk[top]] = inf;
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
                    if (mp[p[i].x][pos[p[i].x] + 1] != 1 && mp[p[i].x][pos[p[i].x]] >= 1) {
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
                    posv[stk[top]] = inf;
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

    // check

    auto check = [&]() -> void {
        stack<int> sk;
        map<int, int> have;
        int j = 1; 
        for (char c : a) {
            if (c == '+') {
                if (have[p[j].x] == 1) {
                    cout << c << ' ' << p[j].x << " WA0\n";
                    return;
                }
                sk.push(p[j].x);
                have[p[j].x] = 1;
                j ++;
            } else if (c == '?') {
                if (p[j].op == 'T') {
                    if (!have[p[j].x]) {
                        cout << c << ' ' << p[j].x << " WA1\n";
                        return;
                    }
                } else {
                    if (have[p[j].x]) {
                        cout << c << ' ' << p[j].x << " WA2\n";
                        return;
                    }
                }
                j ++;
            } else {
                if (sk.empty()) {
                    cout << c << ' ' << p[j].x << " WA3\n";
                    return;
                }
                have[sk.top()] = 0;
                sk.pop();
            }
        }
        cout << "OK\n";
    };

    // check();

    /*
    1
    5
    + 1
    + 1
    + 2
    + 1
    T 2
    +-++--+?
    ? 2 WA1
    */
}

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}