#include <bits/stdc++.h>

using namespace std;

using LL = long long;

struct node
{
    int a, b;
};

int main() {
    int n;
    cin >> n;
    vector<int> idx(n);
    vector<node> p(n);
    for (int i = 0;i < n;i ++) cin >> p[i].a;
    for (int i = 0;i < n;i ++) cin >> p[i].b;
    for (int i = 0;i < n;i ++) idx[i] = i;
    LL ans = 1e9;
    do {    
        LL pos = 1;
        for (int i = 1;i < n;i ++) {
            pos += max(p[idx[i - 1]].b, p[idx[i]].a) + 1;
        }
        ans = min(ans, pos);
    } while (next_permutation(idx.begin(), idx.end()));
    cout << ans << '\n';
}