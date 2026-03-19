#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x frist 
#define y second 

using namespace std;
using LL = long long;

const LL inf = 1e15;
const int N = 2e5 + 10;

mt19937_64 rnd(time(0));

void solve () {
    LL n;
    cin >> n;
    vector<LL> a(n + 1, 0), b(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) cin >> b[i];
    sort(all(a)), sort(all(b));
    int ok = 1;
    for (int i = 1;i <= n;i ++) {
        if (a[i] != b[i]) ok = 0;
    }
    if (ok) {
        cout << "Yes\n";
        return;
    }
    int A = 0, B = 0, AA = 0, BB = 0;
    for (int i = 1;i <= n;i ++) {
        if (a[i] & 1) A ++;
        if (b[i] & 1) B ++;
    }
    if (A != B) {
        cout << "No\n";
        return;
    }
    for (int i = 2;i <= n;i ++) {
        if (a[i] - a[i - 1] == 1) AA += 1;
        if (b[i] - b[i - 1] == 1) BB += 1;
    }
    if ((BB && !AA) || (AA && !BB) || (!AA && !BB)) {
        cout << "No\n";
        return;
    } else {
        cout << "Yes\n";
        return;
    }
}

/*
2
3
1 2 3
1 2 3
3
1 3 2
2 3 4
*/

/*
3
3
1 10 100
100 10 1
2
1 2
99 100
3
1 2 3
1 1 6
*/

int main () {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}