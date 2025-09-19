#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define debug(x) cerr << #x << ':' << x << ' ';
#define nl cerr << '\n';
using namespace std;
const int N = 1e5 + 10; // 需调整
using LL = long long;
const LL inf = LLONG_MAX;
const LL MOD7 = 1e9 + 7;
const LL MOD3 = 998244353;

void fxy_ac(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0;i < n;i ++) cin >> a[i];
    sort(all(a));
    map<int, vector<int>> val;
    for (int i = 0;i < n;i ++){
        val[a[i]].push_back(0);
        int t = 0;
        while (a[i]){
            a[i] /= 2;
            t ++;
            val[a[i]].push_back(t);
        }
    }
    LL Min = inf;
    for (auto &[s, v] : val){
        if (v.size() < k) continue;
        sort(all(v));
        LL sum = 0;
        for (int i = 0;i < k;i ++) sum += v[i];
        Min = min(Min, sum);
    }
    cout << Min << '\n';
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