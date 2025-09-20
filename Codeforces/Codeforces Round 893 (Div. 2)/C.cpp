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
    vector<int> vis(n + 1, 0), a;
    for (int i = 1;i <= n;i ++){
        int id = i;
        for (int j = 0;j < 20;j ++){
            if (id * (1LL << j) <= n && !vis[id * (1LL << j)]){
                a.push_back(id * (1LL << j));
                vis[id * (1LL << j)] = 1;
            } else{
                continue;
            }
        }
    }
    for (int i = 0;i < n;i ++){
        cout << a[i] << " \n"[i == n - 1];
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