#include <bits/stdc++.h>

#define x first 

#define y second

#define siz(x) ((int)x.size())

#define all(x) begin(x),end(x)

using namespace std;

using LL = long long;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> p;
    for (int i = 0;i < n;) {
        int len = 1, j = i;
        while (j + 1 < n && s[j + 1] == s[i]) {
            j ++;
            ans += 
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}