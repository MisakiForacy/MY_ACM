#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, ok = 0;
        cin >> n;
        for (int i = 0;i * 2020 <= n;i ++) {
            if ((n - i * 2020) % 2021 == 0) {
                cout << "YES\n";
                ok = 1;
                break;
            }
        }
        if (!ok) {
            cout << "NO\n";
        }
    }   
}