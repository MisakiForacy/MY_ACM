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
    string s;
    cin >> s;
    int n = siz(s);
    s = ' ' + s;
    if (s.substr(n - 2, 3) != ">>>") {
        cout << "No\n";
        return;
    }
    int cnt = 0;
    for (int i = 1;i <= n;i ++) cnt += s[i] == '>';
    if (cnt == n || s[1] == '-') {
        cout << "No\n";
        return;
    }
    int L = 1, R;
    vector<pair<int, int>> ans;
    for (int i = n;i >= 3;i --) {
        if (s[i] == '>' && s[i - 1] == '>' && s[i - 2] == '>') {
            ans.push_back({L, i - L + 1});
        } else {
            R = i + 1;
            break;
        }
    }
    for (int i = 2;i <= R - 4;i ++) {
        if (s[i] == '>') {
            ans.push_back({i, R - i + 1});
        }
    }
    cout << "Yes " << siz(ans) << '\n';
    for (auto [p, l] : ans) {
        cout << p << ' ' << l << '\n';
    }
}

void brute() {

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) {
        fxy_ac();
        // brute();
    }
}