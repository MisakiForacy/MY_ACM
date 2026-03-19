#include <bits/stdc++.h> 
#define all(x) begin(x),end(x) 
#define siz(x) ((int)x.size()) 

#define x first 
#define y second 

#define LOG 30

using namespace std; 
using LL = long long; 

const LL inf = 1e15; 

void solve () { 
    int n;
    cin >> n;

    vector<LL> a(n), b(n);
    LL ax = 0;
    for (int i = 0;i < n;i ++) {
        cin >> a[i];
        ax ^= a[i];
    }
    vector<int> use(LOG + 1, -1);
    LL bx = 0;
    for (int i = 0;i < n;i ++) {
        cin >> b[i];
        bx ^= b[i];
        LL d = a[i] ^ b[i];
        if (d) {
            for (int k = 0;k <= LOG;k ++) {
                if ((d >> k) & 1LL) use[k] = i;
            }
        }
    }
    LL x = ax ^ bx;
    if (x == 0) {
        cout << "Tie\n";
    } else {
        int p = -1;
        for (int k = LOG;k >= 0;k --) {
            if ((x >> k) & 1LL) { 
                p = k; 
                break; 
            }
        }
        int used = use[p];
        if ((used + 1) % 2 == 1) cout << "Ajisai\n";
        else cout << "Mai\n";
    }
} 

int main () { 
    ios::sync_with_stdio(0); 
    cin.tie(0), cout.tie(0); 
    int T = 1; 
    cin >> T; 
    while (T --) solve (); 
} 