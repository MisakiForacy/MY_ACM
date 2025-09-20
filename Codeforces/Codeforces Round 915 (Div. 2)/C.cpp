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
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ss = s;
    sort(all(ss));
    string t = "";
    int ok = 0;
    char Max = ss.back();
    for (int i = 0;i < n;i ++){
        if (s[i] == Max) ok = 1;
        if (ok && ss[i] != s[i]){
            t.push_back(s[i]);
        } else if (ss[i] != s[i]){
            cout << -1 << '\n';
            return;
        }
    }
    ok = 1;
    for (int i = 1;i < t.size();i ++){
        if (t[i] > t[i - 1]) ok = 0;
    }
    cout << (ok ? t.size() : -1) << '\n';
}

void brute(){ // 暴力

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T; // 需调整
    while (T --){
        fxy_ac();
        // brute();
    }
}