#include <bits/stdc++.h> 
#define all(x) begin(x),end(x) 
#define siz(x) ((int)x.size()) 

#define x first 
#define y second 

#define LOG 20 

using namespace std; 
using LL = long long; 

const LL inf = 1e15; 

/*
Tie
Ajisai
Mai
*/

void solve () { 
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) cin >> b[i];
    int dp[n + 1][2];
    memset(dp, 0, sizeof dp);
    for (int i = 1;i <= n;i ++) {
        
    }
} 

int main () { 
    ios::sync_with_stdio(0); 
    cin.tie(0), cout.tie(0); 
    int T = 1; 
    cin >> T; 
    while (T --) solve (); 
} 