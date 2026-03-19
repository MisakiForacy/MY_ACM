#include <bits/stdc++.h>

#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

using namespace std;
using LL = long long;

struct node
{
    LL v, id, ans;
};

void solve() {
    int n;
    cin >> n;
    vector<node> a(n + 1);
    LL Mx = 0;
    map<int, int> Mp;
    for (int i = 1;i <= n;i ++) 
        cin >> a[i].v, a[i].id = i, Mx = max(Mx, a[i].v), Mp[a[i].v] ++;
    if (Mp[Mx] & 1) {
        for (int i = 1;i <= n;i ++) {   
            if (a[i].v == Mx) {
                cout << 1;
            } else {
                cout << 0;
            }
        }
    } else {
        for (int i = 1;i <= n;i ++) {
            if (a[i].v == Mx) {
                cout << 0;
            } else {
                cout << 1;
            }
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve();
}