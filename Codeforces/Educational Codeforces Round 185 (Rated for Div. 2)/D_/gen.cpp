#include <bits/stdc++.h>
using namespace std;
using LL = long long;

mt19937_64 rnd(time(0));

int randint(int l, int r) {
    return l + rnd() % (r - l + 1);
}

int main () {
    int T = randint(1, 1000);
    LL N_lim = 300000, Q_lim = 30000;
    cout << T << '\n'; 
    for (int i = T;i >= 1;i --) {
        int Cnt = 0;
        int n = randint(1, N_lim - i + 1);
        int q = randint(1, Q_lim - i + 1);
        N_lim -= n;
        Q_lim -= q;
        cout << n << ' ' << q << '\n';
        for (int j = 1;j <= n;j ++) {
            int c = randint(1, 4);
            switch (c) {
                case 1 : cout << 'I'; break;
                case 2 : cout << 'X'; break;
                case 3 : cout << 'V'; break;
                case 4 : cout << '?'; Cnt ++; break;
            }
        }
        cout << '\n';
        while (q --) {
            int cx = randint(0, n);
            int cv = randint(0, n);
            int ci = randint(max(0, Cnt - cx - cv), n);
            cout << cx << ' ' << cv << ' ' << ci << '\n';
        }
    }
}