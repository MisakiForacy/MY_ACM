#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
string s, t;
int check() {
    int x = 0, y = 0;
    for (int i = 0;i < n;i ++) {
        if (s[i] == t[1]) y += x;
        if (s[i] == t[0]) x ++;
    }
    return y;
}
void dfs(string ss, int p, int kk) {
    if (!kk || p == n) {
        ans = max(ans, check());
        return;
    }
    if (ss[p] == t[0]) {
        string t1 = ss;
        t1[p] = t[1]; 
        dfs(ss, p + 1, kk);
        dfs(t1, p + 1, kk - 1);
    }
    if (ss)
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cin >> s >> t;
        ans = 0;
        dfs(s, 0, k);
        cout << ans << '\n';
    }   
}