#include <bits/stdc++.h>

using namespace std;

const int N = 15;

int n, m;
int a[N];

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

/*
5 3
1 2 3 
1 2 4 
1 2 5 
1 3 4 
1 3 5 
1 4 5 
2 3 4 
2 3 5 
2 4 5 
3 4 5 
*/