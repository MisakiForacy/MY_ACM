#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
int n, k, ans;
string s, t;
// int check(string s1) {
//     int x = 0, y = 0;
//     // cout << s1 << '\n';
//     // cout << t << '\n';
//     for (int i = 0;i < n;i ++) {
//         // cout << t[1] << ' ' << t[0] << '\n';
//         // cout << s1[i] << ' ' << x << ' ' << y << '\n';
//         if (s1[i] == t[1]) y += x;
//         if (s1[i] == t[0]) x ++;
//     }
//     // cout << y << '\n';
//     return y;
// }
// void dfs(string ss, int p, int kk) {
//     // cout << p << ' ' << kk << '\n';
//     if (!kk || p == n) {
//         ans = max(ans, check(ss));
//         return;
//     }
//     if (ss[p] == t[0]) {
//         string t1 = ss;
//         t1[p] = t[1]; 
//         dfs(ss, p + 1, kk);
//         dfs(t1, p + 1, kk - 1);
//     }
//     if (ss[p] == t[1]) {
//         string t1 = ss;
//         t1[p] = t[0];
//         dfs(ss, p + 1, kk);
//         dfs(t1, p + 1, kk - 1);
//     }
//     if (ss[p] != t[0] && ss[p] != t[1]) {
//         string t1 = ss, t2 = ss;
//         t1[p] = t[0];
//         t2[p] = t[1];
//         dfs(t1, p + 1, kk - 1);
//         dfs(t2, p + 1, kk - 1);
//     }
// }
int main() {
    //freopen("1.in", "r", stdin);
    //freopen("1.out", "w", stdout);
    int tt = 1;
    // cin >> t;
    while (tt--) {
        cin >> n >> k;
        cin >> s >> t;
        if (t[0] == t[1]) {
            for (int i = 0;i < n && k;i ++) {
                if (s[i] != t[0]) {
                    s[i] = t[0];
                    k --;
                }
            }
        } else {
            
        }
        // ans = check(s);
        // dfs(s, 0, k);
        // cout << ans << '\n';
    }   
}