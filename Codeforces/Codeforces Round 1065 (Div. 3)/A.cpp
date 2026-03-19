#include <bits/stdc++.h> 
#define all(x) begin(x),end(x) 
#define siz(x) ((int)x.size()) 

#define x first 
#define y second 

#define LOG 20 

using namespace std; 
using LL = long long; 

const LL inf = 1e15; 

void solve () { 
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0;2 * i <= n;i ++) {
        LL x = 2 * i;
        LL y = n - x;
        if (y % 4 == 0) cnt ++;
    }
    cout << cnt << '\n';
} 

int main () { 
    ios::sync_with_stdio(0); 
    cin.tie(0), cout.tie(0); 
    int T = 1; 
    cin >> T; 
    while (T --) solve (); 
} 