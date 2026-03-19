#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))
#define nl cerr << '\n';
#define debug(x) cerr << #x << ':' << x << ' '
#define x first
#define y second
using namespace std;
using LL = long long;
using ULL = unsigned long long;

const int N = 2e5 + 10;
const LL inf = 1e15;
const int P = 131;

mt19937_64 rng(time(0));

void fxy_ac() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    s = ' ' + s;
    int ans = 0;
    for (int i = 1;i <= n;i ++) {
        if (s[i] == '1') {
            int ok = 1;
            for (int j = max(1, i - k + 1);j < i;j ++) {
                if (s[j] == '1') ok = 0;
            }
            if (ok) ans ++;
        }
    }
    cout << ans << '\n';
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