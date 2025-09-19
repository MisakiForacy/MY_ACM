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
    string s;
    cin >> s;
    s = ' ' + s;
    int R = 0, mid, ans = 0;
    vector<int> p(siz(s), 0);
    for (int i = 1;i < siz(s);i ++){
        if (i < R) p[i] = min(p[2 * mid - i], R - i);
        else p[i] = 1;
        while (s[i - p[i]] == s[i + p[i]]) p[i] ++;
        if (i + p[i] > R){
            R = i + p[i];
            mid = i;
        }
        ans = max(ans, p[i] * 2 - 1);
    }
    R = 0;
    for (int i = 1;i < siz(s) - 1;i ++){
        if (s[i] != s[i + 1]) continue;
        if (i < R) p[i] = min(p[2 * mid - i], R - i);
        else p[i] = 1;
        while (s[i - p[i]] == s[i + p[i] + 1]) p[i] ++;
        if (i + p[i] > R){
            R = i + p[i];
            mid = i;
        }
        ans = max(ans, p[i] * 2);
    }
    cout << ans << '\n';
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