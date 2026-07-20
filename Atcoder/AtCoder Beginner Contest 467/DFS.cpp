#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int N = 15;

int n;

int a[N], vis[N];

void dfs(int pos) {
    if (pos > n) {
        for (int i = 1;i <= n;i ++) {
            cout << a[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1;i <= n;i ++) {
        if (vis[i]) continue;
        vis[i] = 1;
        a[pos] = i;
        dfs(pos + 1);
        vis[i] = 0;
    }
}

int main() {
    cin >> n;
    dfs(1);
}