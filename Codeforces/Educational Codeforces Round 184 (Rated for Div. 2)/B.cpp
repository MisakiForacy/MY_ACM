#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

const LL inf = 1e15;
const int N = 2e5 + 10;

void solve () {
    string s;
    cin >> s;
    int n = siz(s);
    s = ' ' + s + ' ';
    if (n == 1) {
        cout << 1 << '\n';
    } else {
        int ok = 0;
        for (int i = 1;i <= n;i ++) {
            if (s[i] == '*' && (s[i - 1] == '>' || s[i - 1] == '*')) ok = 1;
            if (s[i] == '*' && (s[i + 1] == '<' || s[i + 1] == '*')) ok = 1;
            if (s[i] == '>' && s[i + 1] == '<') ok = 1;
        }
        if (ok) {
            cout << -1 << '\n';
        } else {
            int lenL = 0, lenR = 0;
            for (int i = 1;i <= n;i ++) 
                if (s[i] == '<' || s[i] == '*') lenL ++;
                else break;
            for (int i = n;i >= 1;i --) 
                if (s[i] == '>' || s[i] == '*') lenR ++;
                else break;
            cout << max(lenL, lenR) << '\n';
        }
    }
}

int main () {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}