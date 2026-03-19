#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define siz(x) ((int)x.size())
#define lowbit(x) ((x) & (-x))

#define x first 
#define y second 

#define LOG 20

using namespace std;
using LL = long long;

const LL inf = 1e15;
const int N = 2e5 + 10;

void solve () {
    int n;
    cin >> n;
    vector<LL> a(n + 1, 0);
    for (int i = 1;i <= n;i ++) cin >> a[i];
    LL sum = 0, cnt = 0;
    sort(all(a));
    for (int i = 1;i <= n;i ++) {
        string A = to_string(sum);
        string B = to_string(a[i]);
        reverse(all(A));
        reverse(all(B));
        if (siz(A) < siz(B)) swap(A, B);
        int k = siz(A) - siz(B);
        for (int j = 0;j < k;j ++) B.push_back('0');
        LL x, y, z = 0;
        for (int j = 0;j < siz(A);j ++) {
            x = A[j] - '0', y = B[j] - '0';
            if (x + y + z >= 10) {
                cnt += (x + y + z) / 10;
                z = (x + y + z) / 10;
            } else {
                z = 0;
            }
        } 
        sum += a[i];
    }
    cout << cnt << '\n';
}

/*
2
3
9 99 999
1
12345
*/

int main () {
    // freopen("in", "r", stdin);
    // freopen("out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T = 1;
    cin >> T;
    while (T --) solve ();
}