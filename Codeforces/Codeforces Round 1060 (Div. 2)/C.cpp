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

vector<int> p, s(N, 0);
set<int> sp;

void Euler() {
    for (int i = 2;i < N;i ++) {
        if (!s[i]) 
            p.push_back(i);
        for (int j = 0;j < siz(p) && i * p[j] < N;j ++) {
            s[i * p[j]] = 1;
            if (i % p[j] == 0) break;
        }
    }
}

void fxy_ac() {
    int n;
    cin >> n;
    vector<LL> a(n + 2, 0), b(n + 2, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    for (int i = 1;i <= n;i ++) cin >> b[i];
    map<int, int> mp;
    for (int i = 1;i <= n;i ++) {
        for (int j = 1;j * j <= a[i];j ++) {
            if (a[i] % j) continue;
            int x = j, y = a[i] / j;
            if (sp.find(x) != sp.end()) mp[x] ++;
            if (sp.find(y) != sp.end()) mp[y] ++;
            if (sp.find(x) != sp.end() && x == y) mp[x] --;
        }
    }
    for (auto [k, v] : mp) {
        if (v > 1) {
            cout << 0 << '\n';
            return;
        }
    }
    for (int i = 1;i <= n;i ++) {
        int v = a[i] + 1;
        for (int j = 1;j * j <= v;j ++) {
            if (v % j) continue;
            int x = j, y = v / j;
            if (mp.count(x)|| mp.count(y)) {
                cout << 1 << '\n';
                return;
            }
        }
    }
    cout << 2 << '\n';
    return;
}

void brute() {

}

int main() {
    Euler();
    for (int x : p) sp.insert(x);
    // cout << siz(p) << '\n';
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