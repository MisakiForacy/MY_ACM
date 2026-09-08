#include <bits/stdc++.h>

#define all(x) begin(x),end(x)

#define siz(x) ((int)x.size())

using namespace std;

using LL = long long;

struct node
{
    char op;
    int x;
};

void solve() {
    int n;
    cin >> n;
    vector<node> p(n + 1);
    vector<char> a(2 * n + 1);
    map<int, vector<int>> mp;
    map<int, int> pos, have;
    for (int i = 1;i <= n;i ++) {
        cin >> p[i].op >> p[i].x;
        a[i * 2 - 1] = (p[i].op == '+' ? '+' : '?');
        if (p[i].op == 'T' || mp[p[i].x].empty())
            mp[p[i].x].push_back(1);
        else
            mp[p[i].x].push_back(0);
        pos[p[i].x] = 0;    
    }
    for (int i = 1;i <= n;i ++) {
        if ()
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}