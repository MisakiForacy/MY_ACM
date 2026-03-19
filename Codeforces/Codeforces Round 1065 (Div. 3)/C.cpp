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
    vector<int> a(n), b(n);
    for (int i = 0;i < n;i ++) cin >> a[i];
    for (int i = 0;i < n;i ++) cin >> b[i];
    int ok = 0, use = -1; 
    for (int i = 0;i < n;i ++) {
        if (a[i] != b[i]) {
            ok ^= 1;
            use = i;
        }
    }
    if (ok == 0) {
        cout << "Tie\n";
    } else {
        if ((use + 1) & 1) {
            cout << "Ajisai\n";
        } else {
            cout << "Mai\n";
        }
    }
} 

int main () { 
    ios::sync_with_stdio(0); 
    cin.tie(0), cout.tie(0); 
    int T = 1; 
    cin >> T; 
    while (T --) solve (); 
} 