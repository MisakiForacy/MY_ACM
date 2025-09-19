#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define debug(x) cerr << #x << ':' << x << ' ';
#define nl cerr << '\n';
using namespace std;
const int N = 1e6 + 10; // 需调整
using LL = long long;
const LL inf = LLONG_MAX;
const LL MOD7 = 1e9 + 7;
const LL MOD3 = 998244353;

int pre[1000005][30];

void fxy_ac(){
    int n;
    cin >> n;
    string s, ss = " ";
    cin >> s;
    s = ' ' + s;
    int id = 1;
    for (int i = 1;i <= n;i ++){
        ss.push_back(s[i]);
        int ok = 1;
        for (int j = 0;j < 26;j ++){
            // cout << pre[id - 1][j] << " \n"[j == 25];
            if (s[i] - 'a' == j && pre[id - 1][j] != 0){
                id = pre[id - 1][j];
                ok = 0;
            }
        }
        for (int j = 0;j < 26;j ++){
            pre[id][j] = pre[id - 1][j];
        }
        if (ok) pre[id][s[i] - 'a'] = id, id ++;
        else ss.erase(id, siz(ss) - id);
    }
    string sss = "";
    for (int i = 1;i < siz(ss);i ++){
        sss.push_back(ss[i]);
    }
    cout << sss << '\n';
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