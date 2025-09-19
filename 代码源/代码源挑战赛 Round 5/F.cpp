#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define debug(x) cerr << #x << ':' << x << ' ';
#define nl cerr << '\n';
using namespace std;
const int N = 1e5 + 10; // 需调整
using LL = long long;
const LL inf = LLONG_MAX;
const LL MOD7 = 1e9 + 7;
const LL MOD3 = 998244353;

struct node{
    LL a, b, c;
    bool operator < (const node &that) const {
        return c > that.c;
    }
};

void fxy_ac(){
    LL n, m, t, ans = -1;
    cin >> n >> m >> t;
    vector<node> a(n);
    for (int i = 0;i < n;i ++) cin >> a[i].a;
    for (int i = 0;i < n;i ++) cin >> a[i].b;
    for (int i = 0;i < n;i ++) cin >> a[i].c;
    sort(all(a));
    // for (int i = 0;i < n;i ++){
    //     cout << a[i].a << ' ' << a[i].b << ' ' << a[i].c << '\n';
    // }
    int x = n / 2;
    int y = n - x;
    map<int, vector<pair<LL, LL>>> mp;
    map<int, vector<LL>> tt;
    for (int i = 0;i < (1LL << x);i ++){
        LL cnt = 0, time = 0, val = 0;
        for (int j = 0;j < x;j ++){
            if (i & (1LL << j)){
                cnt ++;
                time += a[j].b + cnt * a[j].c;
                val += a[j].a;
            }
        }
        mp[cnt].push_back({time, val});
    }
    for (auto &[k, v] : mp){
        sort(all(v));
        vector<pair<LL, LL>> b;
        vector<LL> c;
        LL Max = 0;
        for (int i = 0;i < siz(v);i ++){
            if (v[i].second >= Max){
                b.push_back({v[i].first, v[i].second});
                c.push_back(v[i].first);
                Max = v[i].second;
            }
        }
        v = b;
        tt[k] = c;
    }
    for (int i = 0;i < (1LL << y);i ++){
        LL cnt = 0, time = 0, val = 0, base = 0, add = 0;
        for (int j = 0;j < y;j ++){
            if (i & (1LL << j)){
                cnt ++;
                base += a[j + x].b;
                add += a[j + x].c;
                time += cnt * a[j + x].c;
                val += a[j + x].a;
            }
        }
        if (mp.count(m - cnt)){
            // cout << time << ' ' << add << ' ' << base << '\n';
            time = time + add * (m - cnt) + base;
            // cout << cnt << ' ' << i << ' ' << time << ' ' << val << '\n';
            LL rs = t - time;
            int id = upper_bound(all(tt[m - cnt]), rs) - tt[m - cnt].begin() - 1;
            if (id >= 0){
                ans = max(ans, val + mp[m - cnt][id].second);
            }
        }
    }
    cout << ans << '\n';
}

void brute(){ // 暴力

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T; // 需调整
    while (T --){
        fxy_ac();
        // brute();
    }
}