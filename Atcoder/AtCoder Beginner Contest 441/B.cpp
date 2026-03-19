#include <bits/stdc++.h>

#define x first 
#define y second 

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

using namespace std;
using LL = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    int q;
    cin >> q;
    map<char, int> S, T;
    for (char c : s) S[c] = 1;
    for (char c : t) T[c] = 1;
    while (q --) {
        string p;
        cin >> p;
        int Takahashi = 0, Aoki = 0;
        int ok = 1;
        for (char c : p) if (!S.count(c)) ok = 0;
        Takahashi = ok;
        ok = 1;
        for (char c : p) if (!T.count(c)) ok = 0;
        Aoki = ok;
        if (Takahashi == Aoki) {
            cout << "Unknown\n";
        } else {
            if (Takahashi) cout << "Takahashi\n";
            else cout << "Aoki\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T --) solve();
}