#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

void solve() {
    int n;
    cin >> n;
    map<string, LL> mp;
    for (int i = 1;i <= n;i ++) {
        char op;
        cin >> op;
        if (op != '?') {
            LL x;
            cin >> x;
            string s;
            while (x) {
                int d = x % 10;
                if (d & 1) s.push_back('1');
                else       s.push_back('0');
                x /= 10;
            }
            while (siz(s) < 18) s.push_back('0');
            if (op == '-') mp[s] --;
            else           mp[s] ++;
        } else {
            string s;
            cin >> s;
            reverse(all(s));
            while (siz(s) < 18) s.push_back('0');
            cout << mp[s] << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}