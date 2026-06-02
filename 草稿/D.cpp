#include <bits/stdc++.h>

using namespace std;
using LL = long long;

double dp[2000000];
LL vis[2000000], qi[10];
int a[10], mx, n, x;

int alive(int cur) {
    LL base = 1, cnt = 0;
    for (int i = 0;i < n + 1;i ++) {
        if (cur / base % (mx + 1)) cnt ++;
        base *= (mx + 1);
    }
    return cnt;
}

int main() {
    cout << fixed << setprecision(6);
    ios::sync_with_stdio(0), cin.tie(0);
    int cur = 0, base = 1;
    cin >> x >> n;
    mx = x;
    for (int i = 0;i < n;i ++) cin >> a[i], mx = max(mx, a[i]);
    qi[0] = 1;
    for (int i = 1;i < 10;i ++) qi[i] = qi[i - 1] * (mx + 1);
    cur += base * x;
    base *= (mx + 1);
    for (int i = 0;i < n;i ++) {
        cur += base * a[i];
        base *= (mx + 1);
    }    
    dp[cur] = 1.0;
    queue<int> q;
    q.push(cur);
    vis[cur] = 1;
    while (q.size()) {
        cur = q.front();
        q.pop();
        if (cur % (mx + 1) == 0) continue;
        for (int i = 0;i < n + 1;i ++) {
            if (cur / qi[i] % (mx + 1)) {
                int nxt = cur - qi[i];
                dp[nxt] += dp[cur] * (1.0 / alive(cur));
                if (vis[nxt]) continue;
                vis[nxt] = 1;
                q.push(nxt);
            }
        }
    }
    cout << dp[1] << '\n';
}