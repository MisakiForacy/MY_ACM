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
    vector<string> s(n);
    map<char, int> mp;
    for (int i = 0;i < n;i ++) cin >> s[i];
    for (int i = 0;i < n;i ++){
        for (auto c : s[i]){
            mp[c] ++;
        }
    }
    int ok = 1;
    for (auto [k, v] : mp){
        if (v % n) ok = 0;
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