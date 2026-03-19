#include <bits/stdc++.h>
using namespace std;
using LL = long long;

mt19937_64 rnd(time(0));

int main() {
    int n;
    cin >> n;
    vector<LL> a(n + 1, 0), Xor(n + 1, 0), hash(n + 1, 0), pre(n + 1, 0);
    for (int i = 1;i <= n;i ++) {
        cin >> a[i];
        hash[i] = rnd();
        Xor[i] = Xor[i - 1] ^ hash[i];
    }
    for (int i = 1;i <= n;i ++) {
        pre[i] = pre[i - 1] ^ hash[a[i]];
    }
    LL Ans = 0;
    for (int i = 1;i <= n;i ++) {
        if (a[i] == 1) {
            int ok = 1;
            int l = i, r = i;
            while (ok) {
                ok = 0;
                while (l - 2 >= 0 && (pre[r] ^ pre[l - 2]) == Xor[r - l + 2]) {
                    ok = 1, l --;
                }
                while (r + 1 <= n && (pre[r + 1] ^ pre[l - 1]) == Xor[r - l + 2]) {
                    ok = 1, r ++;
                }
            }
            cout << i << ' ' << l << ' ' << r << '\n';
            LL len = r - l + 1;
            Ans += (len + 1) * len / 2;
        }
    }
    cout << Ans << '\n';
}