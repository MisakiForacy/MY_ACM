#include <bits/stdc++.h>

using namespace std;

using LL = long long;

const int N = 15;

int n, m;

int a[N], vis[N];

void dfs(int pos, int x) {
    if (pos > m) {
        for (int i = 1;i <= m;i ++)
            cout << a[i] << ' ';
        cout << '\n';
        return;
    }
    for (int i = x + 1;i <= n;i ++) {
        a[pos] = i;
        dfs(pos + 1, i);
    }
}

int main() {
    cin >> n >> m;
    dfs(1, 0);
}