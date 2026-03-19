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
    vector<int> a(n + 1, 0), b(n + 1, 0), pp;
    set<int> p;
    int ok = 1;
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) b[a[i]] = 1;
    for (int i = 1;i <= n;i ++) 
        if (b[i] == 0) 
            ok = 0;
    if (ok) {
        pp.push_back(a[1]);
        pp.push_back(a[2]);
        pp.push_back(a[3]);
    } else {
        vector<int> use(n + 1, 0);
        for (int i = 1;i <= n;i ++) {
            if (b[i] == 0) {
                use[i] = 1;
                pp.push_back(i);
            }
        }
        while (siz(pp) < 3) {
            for (int i = 1;i <= n;i ++) {
                if (i != a[n] && !use[i]) {
                    use[i] = 1;
                    pp.push_back(i);
                } else if (i == a[n] && siz(pp) > 1 && !use[i]) {
                    use[i] = 1;
                    pp.push_back(i);
                }
            }
        }
    }
    int idx = 0;
    while (k --) {
        cout << pp[idx] << ' ';
        idx ++;
        idx %= 3;
    }
    cout << '\n';
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