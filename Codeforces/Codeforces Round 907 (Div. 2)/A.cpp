#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
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

void fxy_ac(){
    int n;
    cin >> n;
    vector<int> a(n + 2);
    for (int i = 1;i <= n;i ++)
        cin >> a[i];
    a[n + 1] = 1010;
    int ok = 1;
    for (int i = n;i >= 1;i --){
        if (a[i] > a[i + 1] && (i - lowbit(i)))
            ok = 0;
    }
    cout << (ok ? "YES\n" : "NO\n");
}

void brute(){ // 暴力

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T; // 多测
    while (T --){
        fxy_ac();
        // brute();
    }
}