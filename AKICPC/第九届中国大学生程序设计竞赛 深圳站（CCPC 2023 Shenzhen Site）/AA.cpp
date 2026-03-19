Foracy 
登出
QOJ.ac
QOJ
 比赛
 比赛归档
 题库
 提交记录
 Hack!
 博客
 Day 1
 Day 2
搜索题库
ID	题目	提交者	结果	用时	内存	语言	文件大小	提交时间	测评时间
#1599956	#8328. A Good Problem	Foracy#	WA	0ms	3816kb	C++20	1.4kb	2025-10-28 13:31:03	2025-10-28 13:31:03
测评历史
这是最新的提交结果。

[2025-10-28 13:31:03]Judged
Verdict: WATime: 0msMemory: 3816kb
 Show
[2025-10-28 13:31:03]Submitted
answer
#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
using namespace std;
using LL = long long;

void solve() {
    LL n;
    cin >> n;
    vector<int> a(n + 1, 0), b(n + 1, 0), V(n);
    map<int, vector<int>> mp;
    for (int i = 1;i <= n;i ++) cin >> b[i];
    for (int i = 1;i <= n;i ++) {
        mp[b[i]].push_back(i);
    }
    vector<pair<int, int>> p(n);
    for (int i = 1;i <= n;i ++) {
        p[i - 1].first = b[i];
        p[i - 1].second = i;
    }
    sort(all(p));
    for (int i = 1;i <= n;i ++) V[i - 1] = p[i - 1].first;
    int cur = 0;
    vector<pair<int, int>> ans;
    for (auto [k, v] : mp) {
        int idx = lower_bound(all(V), cur) - V.begin();
        if (mp.count(cur)) {
            for (int j = idx + 1;j < n;j ++) {
                // cout << 1 << ' ' << p[j].second << '\n';
                ans.push_back({2, p[j].second});
            }
            cur ++;
        }
        while (cur < k) {
            // cout << 2 << ' ' << cur << '\n';
            ans.push_back({1, cur});
            cur ++;
        }
    }
    cout << siz(ans) << '\n';
    for (auto [x, y] : ans) {
        cout << x << ' ' << y << '\n';
    }

}

/*
4
2 4 3 1
*/

int main() {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}
源文件, 语言: C++20
详细
Test #1:
score: 0
Wrong Answer
time: 0ms
memory: 3816kb
QOJ.ac | QOJ 4.5.21.0.dev | Based on UOJ - 开源项目
Made with ❤️ by Qingyu✨

服务器时间: 2025-10-28 14:06:37

