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

struct node
{
    int i, j, op, a, b, d, v;
};


void fxy_ac() {
    int n;
    cin >> n;
    vector<LL> a(n + 2, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    LL Max = 0;
    map<int, vector<int>> mp;
    for (int i = 1;i <= n;i ++) {
        if (a[i] > Max + 1) {
            cout << -1 << '\n';
            return;
        }
        mp[a[i]].push_back(i);
        Max = max(Max, a[i]);
    }
    int num = 1;
    vector<int> p(n + 1, 0);
    for (auto [k, v] : mp) {
        for (int i = siz(v) - 1;i >= 0;i --) {
            p[v[i]] = num ++;
        } 
    }
    for (int i = 1;i <= n;i ++) cout << p[i] << ' ';
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
    // cin >> T;
    while (T --) {
        fxy_ac();
        // brute();
    }
}