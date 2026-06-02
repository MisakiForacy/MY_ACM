- 小明最近沉迷玩炉石传说, 在某场对局中, 敌方英雄血量为 $x$, 且敌方有 $n$ 个随从, 第 $i$ 个随从血量为 $h_i$。现在是小明回合，他释放某法术，总计造成 $x + \sum_{i=1}^{i \leq n} a_i - 1$ 点伤害，问敌方英雄存活的概率为多少，保留小数点后6位

- $1 \leq x \leq 5$, $1 \leq n \leq 9$, $1 \leq a_i \leq 5$

```cpp
#include <bits/stdc++.h>

using namespace std;
using LL = long long;

double dp[2000000];
LL vis[2000000], qi[11];
int a[11], mx, n, x;

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
```