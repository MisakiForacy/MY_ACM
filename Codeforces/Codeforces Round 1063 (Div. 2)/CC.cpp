#include <bits/stdc++.h>    
using namespace std;

int main () {
    int a[4] = {0, 0, 0, 0};
    int x = 74;
    while (x --) {
        a[3] += 1;
        for (int i = 3;i >= 1;i --) {
            a[i - 1] += a[i] / 4;
            a[i] = a[i] % 4;
        }
    }
    for (int i = 0;i < 4;i ++) {
        cout << a[i] + 1 << ' ';
        if (i == 1) cout << '\n';
    }
    cout << '\n';
}