#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;
using PII = pair<LL, LL>;

const int N = 200005;

void solve() {
    string s;
    cin >> s;
    int n = siz(s);
    if (count(all(s), '1') == n || count(all(s), '0') == n) {
        cout << s << '\n';
    } else {
        string t1, t2;
        s = ' ' + s;
        for (int i = 1;i <= n;i ++) {
            if (s[i] == '0' && s[i - 1] != '1') {
                t1.push_back('1');
            } else if (s[i] == '1' && s[i - 1] == '1') {
                t1.push_back('0');
            }
            t1.push_back(s[i]);
        }
        for (int i = 1;i <= n;i ++) {
            if (s[i] == '1' && s[i - 1] != '0') {
                t2.push_back('0');
            } else if (s[i] == '0' && s[i - 1] == '0') {
                t2.push_back('1');
            }
            t2.push_back(s[i]);
        }
        if (siz(t1) & 1) {
            cout << t2 << '\n';
        } else {
            cout << t1 << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}

/*
4
5 4 0
1 5 4 3 2
5 4 1
1 5 4 3 2
5 4 4
10 20 30 40 50
10 7 3
4 6 8 2 9 9 7 4 10 9
*/

/*
1 2 3 4
5 6 7 8
9

9 2 3 4
5 6 7 8
1

9 1 2 3
4 5 6 7
8
*/