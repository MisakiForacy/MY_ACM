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

LL n, l, r;
vector<LL> a;

LL random(int l,int r){
    return (rand() % (r - l + 1) + l);
}

LL R1(LL mod){
    LL ans = 2147483647;
    return ans = ans * rand() % mod + 1;
}

int ac;

void fxy_ac(){
    // cin >> n >> l >> r;
    n = random(2, 100);
    int f1 = R1(2), f2 = R1(2);
    l = (f1 == 1 ? 1 : -1) * R1(100);
    r = (f2 == 1 ? 1 : -1) * R1(100);
    if (l > r) swap(l, r);
    // cout << n << ' ' << l << ' ' << r << '\n';
    a.resize(n);
    for (int i = 0;i < n;i ++) a[i] = (R1(2) == 1 ? 1 : -1) * R1(100);
    // for (int i = 0;i < n;i ++){
    .
    
    //     cout << a[i] << " \n"[i == n - 1];
    // }
    sort(all(a));
    LL ans = 0;
    for (int i = 0;i < n;i ++){
        int L = upper_bound(all(a), a[i] - l) - a.begin();
        int R = upper_bound(all(a), r - a[i]) - a.begin();
        int id = min({L, R, i});
        // cout << L << ' ' << R << ' ' << id << '\n';
        ans += id;
    }
    // cout << ans << '\n';
    ac = ans;
}

void brute(){ // 暴力
    int cnt = 0;
    for (int i = 0;i < n;i ++){
        for (int j = 0;j < i;j ++){
            if (a[i] - a[j] >= l && a[i] + a[j] <= r) cnt ++;
        }
    }
    // cout << (ac == cnt) << '\n';
    if (ac != cnt){
        cout << ac << '\n';
        cout << cnt << '\n';
    }
    // cout << cnt << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    struct _timeb _;
    _ftime(&_);
    srand(_.millitm);
    int T = 1;
    cin >> T; // 需调整
    while (T --){
        fxy_ac();
        brute();
    }
}