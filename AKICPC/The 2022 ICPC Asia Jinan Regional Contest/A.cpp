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
const LL inf = LLONG_MAX;
const LL MOD7 = 1e9 + 7;
const LL MOD3 = 998244353;

void solve(){
    int n, m;
    cin >> n >> m;
    int a[n + 1];
    vector<int> p;
    for (int i = 1;i <= n;i ++){
        cin >> a[i];
        int x = a[i];
        while (x){
            p.push_back(x);
            x /= 2;
        }
    }
    sort(all(p));
    p.erase(unique(all(p)), p.end());
    LL Min = inf;
    int v[n];
    for (int t = 0;t < siz(p);t ++){
        int x = p[t];
        int id = 0;
        for (int i = 1;i <= n;i ++){
            if (a[i] <= x){
                v[id ++] = x - a[i];
                continue;
            }
            LL cnt = 0, xx, num = a[i];
            while (num > x){
                if (num / 2 <= x){
                    xx = cnt + num - x;
                }
                num /= 2;
                cnt ++;
            }
            xx = min(xx, cnt + x - num);
            v[id ++] = xx;
        }
        sort(v, v + n);
        LL val = 0;
        for (int i = 0;i < n - m;i ++){
            val += v[i];
        }
        Min = min(Min, val);
    }
    cout << Min << '\n';
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}