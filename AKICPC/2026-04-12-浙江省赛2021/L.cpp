#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;
using ULL = unsigned long long;
const int P = 13331;
const int N = 1e5 + 10;
ULL p[N], h[N];

int n;
string s;

void solve() {
    cin >> n >> s;
    for (int i = 1;i < n;i ++) {
        if (s[i] == s[0]) {
            cout << "Wrong Answer\n";
            return;
        }
    }
    cout << "Correct\n";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}