#include <bits/stdc++.h>
using namespace std;

int main() {
    int t = 1;
    int n = 6000;
    cout << t << "\n";
    cout << n << "\n";
    for (int i = 1; i <= n; ++i) {
        cout << i << " \n"[i == n];
    }
    return 0;
}