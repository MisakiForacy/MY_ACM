#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

void solve() {
    int n, k;
    scanf("%d", &n);
    getchar();
    vector<string> p(n + 1);
    for (int i = 1;i <= n;i ++) getline(cin, p[i]);
    scanf("%d", &k);
    getchar();
    string s;
    getline(cin, s);
    int cnt = 0;
    for (int i = 1;i <= n;i ++) {
        int j = 0;
        while (j <= siz(s)) {
            if (s[j] == '<') {
                while (s[j] != '>') j ++;
            }
            if (s.substr(j, siz(p[i])) == p[i]) {
                string t1 = s.substr(0, j);
                string t2 = s.substr(j + siz(p[i]), siz(s) - j - siz(p[i]));
                s = t1 + "<censored>" + t2;
                cnt ++;
                j = siz(t1) + 10;
            } else {
                j ++;
            }
        }
    }
    if (cnt < k) {
        cout << s;
    } else {
        cout << cnt << '\n';
        cout << "He Xie Ni Quan Jia!";
    }
}

int main() {
    int T = 1;
    while (T --) solve();
}