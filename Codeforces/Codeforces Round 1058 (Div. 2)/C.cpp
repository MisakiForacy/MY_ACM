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
    LL n;
    cin >> n;
    int cnt = 0;
    for (int i = 0;i < 60;i ++) {
        if (n >> i & 1) cnt ++;
    }
    if (cnt & 1) {
        cout << "NO\n";
    } else {
        while (n % 2 == 0 && n != 0) n /= 2;
        vector<int> p1, p2;
        for (int i = 0;i <= log2(n);i ++) {
            p1.push_back((n >> i & 1));
        }
        for (int i = log2(n);i >= 0;i --) {
            p2.push_back((n >> i & 1));
        }
        int ok = 1;
        for (int i = 0;i < siz(p1);i ++) {
            if (p1[i] != p2[i]) ok = 0;
        }
        cout << (ok ? "YES\n" : "NO\n");
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
    // for (int i = 0;i < 10000;i ++) {
    //     fxy_ac(i);
    //     // getchar();
    // }
    cin >> T;
    while (T --) {
        fxy_ac();
        // brute();
    }
}