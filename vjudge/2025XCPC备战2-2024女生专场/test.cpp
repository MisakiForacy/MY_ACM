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


vector<int> r = {3, 4, 5, 1, 6, 7};

// O(n)
double cal1Q(int x) {
    LL sum = 0;
    for (int i = 0;i < x - 1;i ++) {
        sum += r[i];
    }
    return 1.0 * sum / (x - 1);
}

// O(1)
double cal2Q(int x) {
    LL res = 0;
    if (x == 0) return 0;
    res += 1.0 * (r[x - 1] - cal2Q(x - 1)) / k;
    return res;
}

void solve() {
    // O(n)
    
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) {
        fxy_ac();
        // brute();
    }
}