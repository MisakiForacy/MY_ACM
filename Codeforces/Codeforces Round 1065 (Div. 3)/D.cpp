#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())

#define x first 
#define y second 

using namespace std;
using LL = long long;

const LL inf = 1e15;

void solve () {
    int n;
    cin >> n;
    vector <LL> p(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> p[i];
    stack <LL> stk;
    vector <pair<LL, LL>> Ans;
    for (int i = 1;i <= n;i ++) {
        LL x = p[i], Min = inf;
        while (siz(stk) && stk.top() < x) {
            LL y = stk.top();
            stk.pop();
            Ans.push_back({y, x});
            Min = min(Min, y);   
        }
        if (Min != inf) stk.push(Min);
        else            stk.push(x);
    }
    if (siz(stk) != 1) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        // for (auto [x, y] : Ans) 
        //     cout << x << ' ' << y << '\n';
    }
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}