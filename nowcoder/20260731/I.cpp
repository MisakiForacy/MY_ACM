#include <bits/stdc++.h>

using namespace std;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int N = (1 << n) - 1;
    s = ' ' + s;
    vector<int> cur(N + 1, 0), ans(N + 1, 0);
    queue<int> pos;
    for (int i = 1;i <= N;i ++) {
        if (s[i] == '1') {
            pos.push(i);
            cur[i] = 1;
        }
    }
    vector<int> vis(n + 1, 0);
    while (pos.size() > 1) {
        int y = pos.front(); pos.pop();
        int z = pos.front(); pos.pop();
        int x = y ^ z;
        if (!ans[x]) {
            ans[x] = y;
            cur[x] ^= 1;
            if (cur[x]) pos.push(x);
        } else if (!ans[y]) {
            ans[y] = x;
            cur[x] ^= 1;
            if (cur[x]) pos.push(x);
        } else if (!ans[z]) {
            ans[z] = z;
            cur[x] ^= 1;
            if (cur[x]) pos.push(x);
        }
        // while (vis[y ^ z]) {
        //     pos.push(z);
        //     z = pos.front();
        //     pos.pop();
        // }
        // int x = y ^ z;
        // vis[x] = 1;
        // cur[x] ^= 1;
        // if (cur[x]) pos.push(x);
        // ans[x] = y;
    }
    for (int i = 1;i <= N;i ++) cout << ans[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}
