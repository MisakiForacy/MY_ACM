#include <bits/stdc++.h>

using namespace std;

int n;
int a[3001][3001];
void solve(){
    cin >> n;
    vector<vector<int>> s(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i][0];
        map<int, int> flag;
        for(int j =  a[i][0]; j >= 1; j--) {
            cin >> a[i][j];
        }
        for(int j = 1; j <= a[i][0]; j++) {
            if (flag[a[i][j]] == 0) {
                flag[a[i][j]] = 1;
                s[i].push_back(a[i][j]);
            }
        }
    }
    map<int, int> flag;
    map<int, int> g;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        int mi = -1;
        vector<int> best;
        for (int i = 1; i <= n; ++i) {
            if (flag[i]) continue;
            vector<int> cur;
            for (int x : s[i]) {
                if (!g[x]) cur.push_back(x);
            }
            if (mi == -1 || cur < best) {
                best = cur;
                mi = i;
            }
        }
        flag[mi] = true;
        for (int x : best) {
            ans.push_back(x);
            g[x] = true;
        }
        // for (int x : ans) {
        //     cout << x << ' ';
        // }
        // cout << '\n';
    }
    for(auto i : ans) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}