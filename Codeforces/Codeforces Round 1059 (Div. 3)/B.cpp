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
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = ' ' + s;
    for (int i = 0;i < 1LL << n;i ++) {
        vector<int> p, a;
        for (int j = 0;j < n;j ++) {
            if (i >> j & 1) {
                p.push_back(s[j + 1] == '1');
            } else {
                a.push_back(s[j + 1] == '1');
            }
        }
        int ok = 1;
        for (int j = 1;j < siz(p);j ++) {
            if (p[j] < p[j - 1]) 
                ok = 0;
        }
        for (int j = 0, k = siz(a) - 1;j < siz(a);j ++, k --) {
            if (a[j] != a[k])
                ok = 0;
        }
        if (ok) {
            cout << siz(p) << '\n';
            for (int j = 0;j < n;j ++) {
                if (i >> j & 1) {
                    cout << j + 1 << ' ';
                }
            }
            cout << '\n';
            return;
        }
    }
}

void brute() {

}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        fxy_ac();
        // brute();
    }
}