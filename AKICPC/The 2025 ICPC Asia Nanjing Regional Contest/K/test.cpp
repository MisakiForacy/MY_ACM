#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define siz(x) ((int)x.size ())

#define LOG 12
#define N 4096

using namespace std;
using LL = long long;

const LL inf = 1e18;

void solve()
{
	vector <int> use (N + 1, 0);
    vector <int> p;
    auto range = [&] (auto range, int v) -> void {
        if (use[v]) return;
        p.push_back(v);
        use[v] = 1;
        for (int j = 1LL << 11;j;j >>= 1) {
            if (v & j) {
                range (range, v ^ j);
            }
        }
    };
    for (auto x : p) cout << x << ' ';
    cout << '\n';
}

/* input
2
4 11
+ 1 3 6
+ 3 4 2
? 1 4
+ 1 4 3
? 4 1
+ 4 3 4
? 1 4
+ 3 2 3
? 1 2
+ 1 1 4
? 1 3
4 4
+ 1 2 64
+ 3 4 32
? 1 2
? 3 1
*/

/* output
17
63
*/

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T = 1;
	// cin >> T;
	while (T--)
		solve();
}