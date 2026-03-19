#include <bits/stdc++.h>
using namespace std;
using LL = long long;

struct node
{
    int u, v, w;
};

const int P = 19260817;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<node> Ans;
    for (int i = 2;i < n;i ++) 
        Ans.push_back({i - 1, i, 1});
    Ans.push_back({n - 1, n, P - n + 2});
    int u = 1, v = u + 2;
    for (int i = 1;i <= m - n + 1;i ++) {
        Ans.push_back({u, v, P});
        v ++;
        if (v > n) u += 1, v = u + 2;
    }
    cout << P << ' ' << P << '\n';
    for (auto T : Ans) {
        cout << T.u << ' ' << T.v << ' ' << T.w << '\n';
    }
}