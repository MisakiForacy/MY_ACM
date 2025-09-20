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
    LL n,k,m;
    cin >> n >> k >> m;
    string s;
    cin >> s;
    s = ' ' + s;
    vector<vector<int>> p(26, vector<int>(m + 1, 0));
    for (int i = 1;i <= m;i ++){
        p[s[i] - 'a'][i] ++;
    }
    for (int i = 0;i < 26;i ++){
        for (int j = 1;j <= m;j ++){
            p[i][j] += p[i][j - 1];
        }
    }
    vector<vector<bool>> ok(k, vector<bool>(n + 1, 0));
    for (int i = 1;i <= m;i ++){
        for (int j = 1;j <= n;j ++){
            for (int t = 0;t < k;t ++){
                if (p[t][j - 1] >= j - 1 && p[t][m] - p[t][j] >= n - j){
                    ok[t][j] = 1;
                }
            }
        }
    }
    for (int i = 0;i < k;i ++){
        for (int j = 1;j <= n;j ++){
            if (!ok[i][j]){
                cout << "NO\n";
                cout << 
            }
        }
    }
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