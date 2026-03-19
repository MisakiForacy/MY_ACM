#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

#define LOG 60

using namespace std;
using LL = long long;

const LL inf = 1e15;
const LL MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0;i < n;i ++) cin >> a[i];
    cout << (*max_element(all(a)) - *min_element(all(a)) + 1) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}