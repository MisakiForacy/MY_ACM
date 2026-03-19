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
    auto ask = [&](vector<int> a) -> int {
        cout << "? " << siz(a) << ' ';
        for (int x : a) {
            cout << x << ' ';
        }
        cout << '\n';
        int x;
        cin >> x;
        return x;
    };
    vector<int> f(2 * n + 1, 0);
    vector<int> p;
    for (int i = 1;i <= 2 * n;i ++) {
        p.push_back(i);
        int res = ask(p);
        if (res != 0) {
            f[i] = res;
            p.pop_back();
        }
    }
    p.clear();
    for (int i = 1;i <= 2 * n;i ++)
        if (f[i])
            p.push_back(i);
    for (int i = 1;i <= 2 * n;i ++) {
        if (!f[i]) {
            p.push_back(i);
            f[i] = ask(p);
            p.pop_back();
        }
    }
    cout << "! ";
    for (int i = 1;i <= 2 * n;i ++) {
        cout << f[i] << ' ';
    }
    cout << '\n';
}

void brute() {

}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    // ios::sync_with_stdio(0);
    // cin.tie(0), cout.tie(0);
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