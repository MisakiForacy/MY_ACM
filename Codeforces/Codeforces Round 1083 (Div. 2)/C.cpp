#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n + 1);
    for (int i = 1;i <= n;i ++) {
        int l;
        cin >> l;
        map<int, int> use;
        vector<int> tp;
        for (int j = 1;j <= l;j ++) {
            int x;
            cin >> x;
            tp.push_back(x);
        }
        for (int j = l - 1;j >= 0;j --) {
            if (!use[tp[j]])
                a[i].push_back(tp[j]), use[tp[j]] = 1;
        }
    }
    /**
     * 只考虑最终的序列，因此只要知道第i个数的最小值，
     * 那么它一定是最后出现的，不必关心在此之前它所出现的位置或交换过的位置
     * 因此，只要知道每次倒序的未出现过的数，组成的最小字典序的序列即可
     */ 
    vector<int> use(n + 1, 0), ans;
    map<int, int> g;
    for (int i = 1;i <= n;i ++) {
        int idx = -1;
        vector<int> Mi;
        for (int j = 1;j <= n;j ++) {
            if (use[j]) continue;
            vector<int> Tp;
            for (int x : a[j]) if (!g[x]) Tp.push_back(x);
            if (idx == -1 || Tp < Mi) {
                Mi = Tp;
                idx = j;
            }
        }
        use[idx] = 1;
        for (int x : Mi) ans.push_back(x), g[x] = 1;
    }
    for (int x : ans) cout << x << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}