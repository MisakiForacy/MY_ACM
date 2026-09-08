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

int chk = 0;

void solve() {
    int n;
    cin >> n;
    vector<node> p(n + 1);
    vector<int> d(n + 1, 0);
    map<int, int> cur, lst;
    for (int i = 1;i <= n;i ++) {
        cin >> p[i].op >> p[i].x;
        if (p[i].op == '+') {
            if (cur[p[i].x]) {
                d[cur[p[i].x]] = lst[p[i].x] ? lst[p[i].x] : cur[p[i].x];
            }
            cur[p[i].x] = i;
            lst[p[i].x] = 0;
        } else if (p[i].op == 'T') {
            lst[p[i].x] = i;
        } else {
            if (cur[p[i].x]) {
                d[cur[p[i].x]] = lst[p[i].x] ? lst[p[i].x] : cur[p[i].x];
                cur[p[i].x] = 0;
                lst[p[i].x] = 0;
            }
        }
    }
    for (auto &[x, v] : cur) {
        if (v) {
            d[v] = lst[x] ? lst[x] : v;
        }
    }
    vector<int> stk(n + 1, 0);
    map<int, int> pos;
    vector<char> a;
    int top = 0;
    for (int i = 1;i <= n;i ++) {
        pos[p[i].x] = -1;
    }
    for (int i = 1;i <= n;i ++) {
        if (p[i].op == '+') {
            while (pos[p[i].x] != -1 && top >= pos[p[i].x]) {
                pos[p[stk[top]].x] = -1;
                a.push_back('-');
                top --;
            }
            stk[++ top] = i;
            pos[p[i].x] = top;
            a.push_back('+');
        } else if (p[i].op == 'T') {
            a.push_back('?');
        } else {
            while (pos[p[i].x] != -1 && top >= pos[p[i].x]) {
                pos[p[stk[top]].x] = -1;
                a.push_back('-');
                top --;
            }
            a.push_back('?');
        }
        while (top && d[stk[top]] <= i) {
            pos[p[stk[top]].x] = -1;
            a.push_back('-');
            top --;
        }
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
    if (chk) check();

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