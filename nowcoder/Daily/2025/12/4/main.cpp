#include <bits/stdc++.h>
using namespace std;
using LL = long long;

const int N = 1e6 + 1;

vector<int> p, s(N, 1);

void Euler() {
    s[1] = s[0] = 0;
    for (int i = 2;i < N;i ++) {
        if (s[i]) p.push_back(i);
        for (int j = 0;j < p.size() && p[j] * i < N;j ++) {
            s[p[j] * i] = 0;
            if (i % p[j] == 0) break;
        }
    }
}

int main() {
    int n;
    cin >> n;
    Euler();
    for (int i = 1;i < N;i ++) s[i] += s[i - 1];
    for (int i = 1;i <= n;i ++) {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << '\n';
    }
}