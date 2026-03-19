#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; cin >> n;
        vector<int> p(n), a(n);
        for (int &x : p) cin >> x;
        for (int &x : a) cin >> x;

        unordered_map<int,int> need;
        int j = n - 1;
        bool ok = true;

        for (int i = n - 1; i >= 0; --i) {
            // Accumulate duplicate-run requirements in a
            while (j > 0 && a[j] == a[j - 1]) {
                need[a[j]]++;
                --j;
            }
            if (j < 0) break; // already matched everything

            if (p[i] == a[j]) {
                --j; // matched this position
            } else if (need[p[i]] > 0) {
                need[p[i]]--; // consume as an extra copy
            } else {
                ok = false;
                break;
            }
        }
        if (ok && j < 0) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}