#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

LL ans;

vector<int> s (5, 0);
vector<int> t (7, 0);

void dfs (int idx) {
    if (idx == 7) {
        LL val = 0;
        for (int i = 1;i <= 4;i ++) val += s[i] / 5;
        ans = max(ans, val);
        return;
    }
    if (t[idx]){
        if (idx <= 4) {
            vector<int> use;
            for (int i = 1;i <= 4;i ++)
                if (i != idx) use.push_back(i);
            for (int i = 0;i <= 3 && i <= s[use[0]];i ++) {
                for (int j = 0;i + j <= 3 && j <= s[use[1]];j ++) {
                    for (int k = 0;i + j + k <= 3 && k <= s[use[2]];k ++) {
                        s[use[0]] -= i;
                        s[use[1]] -= j;
                        s[use[2]] -= k;
                        s[idx] += i + j + k;
                        dfs (idx + 1);
                        s[idx] -= i + j + k;
                        s[use[0]] += i;
                        s[use[1]] += j;
                        s[use[2]] += k;
                    }
                }
            }
        } else if (idx == 5) {
            for (int j = 1;j <= 4;j ++) {
                for (int k = 1;k <= 4;k ++) {
                    if (s[j] && j != k) {
                        s[j] --;
                        s[k] ++;
                        dfs (idx + 1);
                        s[j] ++;
                        s[k] --;
                    }
                }
            }
        } else if (idx == 6) {
            for (int j = 1;j <= 4;j ++) {
                for (int k = 1;k <= 4;k ++) {
                    if (s[j] && s[k] && j != k) {
                        s[j] --;
                        s[k] ++;
                        dfs (idx + 1);
                        s[j] ++;
                        s[k] --;
                    }   
                }
            }
        }
    }
    dfs(idx + 1);
}   

void solve () {
    int n;
    cin >> n;
    ans = 0;
    for (int i = 0;i <= 4;i ++) s[i] = 0;
    for (int i = 0;i <= 6;i ++) t[i] = 0;
    for (int i = 1;i <= n;i ++) {
        string S;
        cin >> S;
        if (S[1] == 'D') s[1] ++;
        if (S[1] == 'C') s[2] ++;
        if (S[1] == 'H') s[3] ++;
        if (S[1] == 'S') s[4] ++;
    }
    for (int i = 1;i <= 6;i ++) cin >> t[i];
    LL ret = 0;
    for (int i = 1;i <= 4;i ++) ret += s[i] / 5, s[i] %= 5;
    dfs (1);
    cout << ans + ret << '\n';
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}