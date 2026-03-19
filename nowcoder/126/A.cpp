#include <bits/stdc++.h>

#define x first 
#define y second

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;
using PLL = pair<LL, LL>;

void solve() {
    string a, b;
    cin >> a >> b;
    int A = 0, B = 0;
    int Aok = 0, Bok = 0;
    for (char x : a) {
        if (x != '+') A *= 10, A += x - '0';
        else Aok = 1;
    }
    for (char x : b) {
        if (x != '+') B *= 10, B += x - '0';
        else Bok = 1;
    }
    if (A > B) {
        cout << "Yes\n";
    } else if (A == B) {
        if (Aok > Bok) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    } else {
        cout << "No\n";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}