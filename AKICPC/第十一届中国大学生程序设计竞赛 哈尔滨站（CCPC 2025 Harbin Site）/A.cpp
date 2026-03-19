#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

#define LOG 20

using namespace std;
using LL = long long;

const LL inf = 1e15;
const int N = 2e5 + 10;

void solve () {
    int n;
    cin >> n;
    vector<LL> a(n + 1);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    LL g = 0;
    sort(all(a));

    for (int i = 2;i <= n;i ++) g = __gcd(g, a[i] - a[i - 1]);
    if (g == 0) {
        cout << "infinite\n";
    } else {
        LL k = 1;
        for (int i = 1;i <= n;i ++) {
            k = max(k, g / __gcd(a[i], g));
        }
        cout << g << ' ' << k << '\n';
    }
}

/*
2
2
3 6
2
2 2
*/

/*
2
3
1 4 7
4
4 16 28 34
*/

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}