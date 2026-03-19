#include <bits/stdc++.h>
#define siz(x) ((int)x.size())
#define all(x) begin(x),end(x)

#define x first 
#define y second 

using namespace std;
using LL = long long;

void solve () {
    LL n;
    cin >> n;
    vector<vector<LL>> a(3, vector<LL> (n + 1));
    map<pair<int, int>, int> mp;
    for (int i = 1;i <= 2;i ++) {
        for (int j = 1;j <= n;j ++) {
            cin >> a[i][j];
        }
    }

    vector<LL> Min1(n + 1, 2 * n + 1), Min2(n + 2, 2 * n + 1);
    vector<LL> Max1(n + 1, 0), Max2(n + 2, 0);

    for (int i = 1;i <= n;i ++) 
        Max1[i] = max(Max1[i - 1], a[1][i]), Min1[i] = min(Min1[i - 1], a[1][i]);
    for (int i = n;i >= 1;i --) 
        Max2[i] = max(Max2[i + 1], a[2][i]), Min2[i] = min(Min2[i + 1], a[2][i]);

    LL Min = 0, Max = 2 * n + 1;
    vector<LL> L(n + 1, 0), R(n + 1, 0);
    for (int i = 1;i <= n;i ++) {
        Min = max(Min, min(Min1[i], Min2[i]));
        Max = min(Max, max(Max1[i], Max2[i]));
    }

    LL ans = 0;

}

/*
2
2 1
3 2
*/

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}