#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

const LL inf = 1e15;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (*max_element(all(s)) == '0') {
        cout << 0 << '\n';
    } else {
        cout << (*min_element(all(s)) == '1' ? n : n - 1) << '\n';
    }
}

int main() {
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}