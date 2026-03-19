#include <bits/stdc++.h>
#define siz(s) ((int)s.size())
#define all(s) begin(s),end(s)

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve () {
    int n;
    cin >> n;
    vector<int> p(n + 1), pos(n + 1);
    for (int i = 1;i <= n;i ++) cin >> p[i];
    string s;
    cin >> s;
    for (int i = 1;i <= n;i ++) pos[p[i]] = i;
    if (s[0] == '1' || s[n - 1] == '1' || s[pos[1] - 1] == '1' || s[pos[n] - 1] == '1') {
        cout << -1 << '\n';
        return;
    }
    vector<pair<int,int>> ans;
    if (pos[1] < pos[n]) {
        ans.push_back({pos[1], pos[n]});
        ans.push_back({1, pos[n]});
        ans.push_back({1, pos[1]});
        ans.push_back({pos[1], n});
        ans.push_back({pos[n], n});
    } else {
        ans.push_back({pos[n], pos[1]});
        ans.push_back({1, pos[1]});
        ans.push_back({1, pos[n]});
        ans.push_back({pos[n], n});
        ans.push_back({pos[1], n});
    }
    cout << siz(ans) << '\n';
    for (auto [l, r] : ans) cout << l << ' ' << r << '\n';
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}