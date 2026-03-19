#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    LL a = 0, b;
    string s;
    cin >> s >> b;
    for (auto c : s) {
        c ^= 48;
        a *= 10;
        a += c;
        a %= b;
    }
    cout << __gcd(a, b) << '\n';
}