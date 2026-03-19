#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

mt19937_64 rnd(time(0));

LL inf = 1e15;

struct node
{
    LL Sm;
    vector<LL> bucket;
    bool operator < (const node&T) const {
        return Sm < T.Sm;
    }
};

void solve() {
    LL n, k, x;
    cin >> n >> k >> x;
    vector<LL> a(n + 1, 0), c(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    sort(a.begin() + 1, a.end(), greater());
    priority_queue<node> que;
    c[1] = k;
    node damn;
    damn.Sm = k * a[1];
    damn.bucket = c;
    que.push(damn);
    vector<LL> Ans;
    set<vector<LL>> fuck;
    int 猪 = 1;
    while (猪) {
        auto [sum, vec] = que.top();
        Ans.push_back(sum);
        que.pop();
        if (siz(Ans) == x) break;
        for (int i = 1;i < n;i ++) {
            if (vec[i]) {
                vector<LL> Tmp = vec;
                Tmp[i] --, Tmp[i + 1] ++;
                if (fuck.count(Tmp)) continue;
                fuck.insert(Tmp);
                LL TmpSm = sum + a[i + 1] - a[i];
                que.push({TmpSm, Tmp});
            }
        }
    }
    for (LL x : Ans) cout << x << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}