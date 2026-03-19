#include <bits/stdc++.h>
#define For(i, n, m) for (ll i = n; i <= m; i++)
#define endl "\n"
using namespace std;
typedef long long ll;
const ll tx[9] = {0, 1, 1, -1, -1, 2, 2, -2, -2};
const ll ty[9] = {0, 2, -2, 2, -2, 1, -1, 1, -1};
const ll ckx[9] = {0, 0, 0, 0, 0, 1, 1, -1, -1};
const ll cky[9] = {0, 1, -1, 1, -1, 0, 0, 0, 0};
ll f[10][11][10][11];
ll T;
int main()
{
	cin.tie(0), ios::sync_with_stdio(false);
	cin >> T;
	// For(i, 1, 9) For(j, 1, 10)
	// {
	// }
	while (T--)
	{
		static ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		bool ck = 0;
		For(i, 1, 8)
		{
			static ll x, y;
			x = x1 + tx[i], y = y1 + ty[i];
			if (x <= 0 || x >= 10 || y <= 0 || y >= 11)
				continue;
			if (ckx[i] && y1 == y2 && x1 + ckx[i] == x2)
				continue;
			if (cky[i] && x1 == x2 && y1 + cky[i] == y2)
				continue;
			if (x == x2 && y == y2)
			{
				ck = 1;
				break;
			}
			if (x != x2 && y != y2)
			{
				ck = 1;
				break;
			}
		}
		cout << (ck ? "NO" : "YES") << endl;
	}
}