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
    vector<int> a(n);
    for (int i = 0;i < n;i ++) cin >> a[i];
    int pre = a[n - 2];
    int lst = a[n - 1];
    vector<int> res;
    for (int i = 0;i < k;i ++) {
        int x;
        for (int cur = 1;cur <= 3;cur ++) {
            if (cur != pre && cur != lst) {
                x = cur;
                break;
            }
        }
        res.push_back(x);
        pre = lst;
        lst = x;
    }
    for (int x : res) {
        cout << x << ' ';
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