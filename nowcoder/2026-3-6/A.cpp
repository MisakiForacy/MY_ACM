#include <bits/stdc++.h>

using namespace std;

bool is_all_zero(const string& s) {
    for (char c : s) {
        if (c == '1') return false;
    }
    return true;
}

bool is_alternating(const string& s) {
    for (int i = 1; i < (int)s.size(); i++) {
        if (s[i] == s[i - 1]) return false;
    }
    return true;
}

void solve() {
    int n;
    string s, t;
    cin >> n >> s >> t;

    if (is_all_zero(s)) {
        cout << (is_all_zero(t) ? "YES\n" : "NO\n");
        return;
    }

    if (is_alternating(t)) {
        cout << (s == t ? "YES\n" : "NO\n");
        return;
    }

    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
