#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define x first
#define y second
#define debug(x) cerr << #x << ':' << x << ' ';
#define nl cerr << '\n';
using namespace std;
const int N = 1e5 + 10; // 需调整
using LL = long long;
const LL inf = 1e12;
const LL MOD7 = 1e9 + 7;
const LL MOD3 = 998244353;

void fxy_ac(){
    int n, q;
    cin >> n >> q;
    set<LL> p1;
    set<LL,greater<>> p2;
    vector<LL> a(n + 1), b(n + 1);
    vector<array<LL, 3>> p(n + 1);
    for (int i = 1;i <= n;i ++){
        cin >> a[i];
        LL x = inf, y = inf;
        if (p1.lower_bound(a[i]) != p1.end())
            x = abs(a[i] - *p1.lower_bound(a[i]));
        if (p2.lower_bound(a[i]) != p2.end())
            y = abs(a[i] - *p2.lower_bound(a[i]));
        p1.insert(a[i]);
        p2.insert(a[i]);
        b[i] = min({x, y, a[i]});
    }
    for (int i = 1;i <= n;i ++){
        p[i][0] = a[i];
        p[i][1] = b[i];
        p[i][2] = b[i];
    }
    sort(all(p), [&](array<LL, 3> x, array<LL, 3> y){
        return x[2] < y[2];
    });
    for (int i = 1;i <= n;i ++){
        p[i][0] += p[i - 1][0];
        p[i][1] += p[i - 1][1];
    }
    while (q --){
        LL x;
        cin >> x;
        int cur = 0;
        for (int j = 20;j >= 0;j --){
            if (cur + (1LL << j) > n) continue;
            int id = cur + (1LL << j);
            if (p[id][2] <= x) cur += (1LL << j);
        }
        cout << p[cur][1] + p[n][0] - p[cur][0] << '\n';
    }
}

void brute(){ // 暴力

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T; // 多测
    while (T --){
        fxy_ac();
        // brute();
    }
}