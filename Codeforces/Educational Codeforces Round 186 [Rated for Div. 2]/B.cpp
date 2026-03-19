#include <bits/stdc++.h>

#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve() {
    LL a, b;
    cin >> a >> b;
    LL a1, a2, b1, b2;
    a1 = a2 = a, b1 = b2 = b;
    int A = 0, B = 0;
    LL p = 1, t = 1;
    while (1) {
        if (t) {
            if (a1 >= p) {
                a1 -= p;
                A ++;
            } else {
                break;
            }
        } else {
            if (b1 >= p) {
                b1 -= p;
                A ++;
            } else {
                break;
            }
        }
        t ^= 1;
        p *= 2;
    }
    p = 1, t = 0;
    while (1) {
        if (t) {
            if (a2 >= p) {
                a2 -= p;
                B ++;
            } else {
                break;
            }
        } else {
            if (b2 >= p) {
                b2 -= p;
                B ++;
            } else {
                break;
            }
        }
        t ^= 1;
        p *= 2;
    }
    cout << max(A, B) << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}