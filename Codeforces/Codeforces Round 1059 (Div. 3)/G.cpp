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

vector<LL> p(N, 0);

void init() {
    for (LL i = 1;i < N;i ++) 
        p[i] = i * i;
}

void fxy_ac() {
    LL n;
    cin >> n;
    if (n < 5) {
        if (n == 2) {
            cout << -1 << '\n';
        } else if (n == 3) {
            cout << "1 3\n";
            cout << "2 3\n";
        } else if (n == 4) {
            cout << "1 2\n";
            cout << "3 1\n";
            cout << "4 1\n";
        }
    } else {
        cout << "1 2\n";
        cout << "2 3\n";
        cout << "3 4\n";
        cout << 1 << ' ' << n << '\n';
        for (int i = 5;i < n;i ++) cout << 2 << ' ' << i << '\n';
    }
}

void brute() {

}

int main() {
    init();
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