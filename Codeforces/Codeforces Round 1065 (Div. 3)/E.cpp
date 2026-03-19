#include <bits/stdc++.h> 
#define all(x) begin(x),end(x) 
#define siz(x) ((int)x.size()) 

#define x first 
#define y second 

#define LOG 20 

using namespace std; 
using LL = long long; 

const LL inf = 1e15; 

void solve () { 
    int n;
    cin >> n;
    vector<LL> p(n + 1, 0);
    set<int> use;
    for (int i = 1;i <= n;i ++) use.insert(i);
    int cur = 2;
    vector<int> used(n + 1, 0);
    if (n >= 2) used[2] = 1;
    if (n >= 3) used[3] = 1;
    if (n >= 5) used[5] = 1;
    auto add = [&](int x, int v) -> int {
        while (x <= n && used[x]) x += v;
        if (x <= n) used[x] = 1;
        return x;
    };
    for (int i = 2;i <= n && cur <= n;i = add(i, 2), cur += (cur % 3 ? 1 : 2)) 
        p[cur] = i, use.erase(i);
    for (int i = 3;i <= n && cur <= n;i = add(i, 3), cur += (cur % 3 ? 1 : 2)) 
        p[cur] = i, use.erase(i);
    for (int i = 5;i <= n && cur <= n;i = add(i, 5), cur += (cur % 3 ? 1 : 2)) 
        p[cur] = i, use.erase(i);
    for (int i = 1;i <= n;i += 3) {
        p[i] = *use.begin();
        use.erase(*use.begin());
    }
    for (int i = 1;i <= n;i ++) cout << p[i] << ' ';
    cout << '\n';
} 

int main () { 
    // ios::sync_with_stdio(0); 
    // cin.tie(0), cout.tie(0); 
    int T = 1; 
    cin >> T; 
    while (T --) solve (); 
} 