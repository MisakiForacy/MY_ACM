#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define nl cout << '\n';
#define debug(x) cerr << #x << ':' << x << ' '
#define x first
#define y second
using namespace std;
using LL = long long;

const int N = 2e5 + 10;
const LL inf = 1e15;

mt19937_64 rng(time(0));

void fxy_ac() {
    LL n, k;
    cin >> n >> k;
    if (n * n - k == 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        int v = n * n - k;
        for (int i = 1;i <= n;i ++) {
            for (int j = 1;j <= n;j ++) {
                if (v) {
                    if (j == 1 && i == 1) {
                        cout << 'R';
                    } else if (i == 1) {
                        cout << 'L';
                    } else {
                        cout << 'U';
                    }
                    v --;
                } else {
                    cout << 'R';
                }
            }
            cout << '\n';
        }
    }
}

void brute() {

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        fxy_ac();
        // brute();
    }
}