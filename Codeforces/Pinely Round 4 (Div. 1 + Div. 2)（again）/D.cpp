#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

int mex (vector<int> &a) {
    for (int i = 0;i < siz(a);i ++) {
        if (!a[i]) return i;
    }
    return siz(a);
}

int isp (int x) {
    for (int i = 2;i <= sqrt(x);i ++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

void solve () {
    int n;
    cin >> n;
    if (n <= 6) {
        switch (n)
        {
            case 1: {cout << "1\n1\n"; break;}
            case 2: {cout << "2\n1 2\n"; break;}
            case 3: {cout << "2\n1 2 2\n"; break;}
            case 4: {cout << "3\n1 2 2 3\n"; break;}
            case 5: {cout << "3\n1 2 2 3 3\n"; break;}
            case 6: {cout << "4\n1 2 2 3 3 4\n"; break;}
            default: break;
        }
        return;
    }
    cout << "4\n";
    cout << "1 2 ";
    for (int i = 1;i <= (n - 2) / 4;i ++) {
        cout << "3 2 1 4 ";
    }
    int use[4] = {3, 2, 1, 4};
    for (int j = 0;j < (n - 2) % 4;j ++) {
        cout << use[j] << ' ';
    }
    cout << '\n';
}

int main () {
    // freopen ("in", "r", stdin);
    // freopen ("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}