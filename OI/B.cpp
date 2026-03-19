#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    map<int, int> Mp;
    map<int, priority_queue<int, vector<int>, greater<int>>> dp; 
    // dp表示某分组，最后一个数为dp[i]，长度从小至大的序列
    vector<int> a(n + 1);
    for (int i = 1;i <= n;i ++) 
        cin >> a[i], Mp[a[i]] ++;
    for (auto [k, v] : Mp) {
        for (int i = 1;i <= v;i ++) {
            if (!dp.count(k - 1) || siz(dp[k - 1]) == 0) {
                dp[k].push(1);
            } else {
                int len = dp[k - 1].top();
                dp[k - 1].pop();
                dp[k].push(len + 1);
            }
        }
    }
    int Mi = n;
    for (auto [k, v] : dp) {
        while (siz(v)) {
            Mi = min(Mi, v.top());
            v.pop();
        }
    }
    cout << Mi << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}