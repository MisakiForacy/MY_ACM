#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve () {
    LL n, m;
    cin >> n >> m;
    string a, b, A, B, C;
    cin >> a >> b;
    LL g = n * m / __gcd(n, m);
    for (int i = 1;i <= g / n;i ++) A += a;
    for (int i = 1;i <= g / m;i ++) B += b;
    vector<int> AA(g + 1, 0), BB(g + 1, 0);
    for (int i = 0;i < g;i ++) AA[i] = A[i] - '0';
    for (int i = 0;i < g;i ++) BB[i] = B[i] - '0';
    if (A < B) {
        int c = AA[g - 1] == 0;
        AA[g - 1] -= 1;
        AA[g - 1] += 10;
        AA[g - 1] %= 10;
        for (int i = g - 2;i >= 0;i --) {
            if (!c) break;
            c = AA[i] == 0;
            AA[i] -= 1;
            AA[i] += 10;
            AA[i] %= 10;
        }
    }
    int c = 0;
    for (int i = g - 1;i >= 0;i --) {
        AA[i] -= BB[i] + c;
        if (AA[i] < 0) c = 1;
        else c = 0;
        AA[i] = (AA[i] + 10) % 10;
    }
    cout << g << '\n';
    for (int i = 0;i < g;i ++) cout << AA[i];
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve ();
}