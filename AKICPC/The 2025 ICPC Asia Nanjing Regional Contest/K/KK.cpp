#include <bits/stdc++.h>
#define For(i, n, m) for (ll i = n; i <= m; i++)
#define endl "\n"
using namespace std;
typedef long long ll;
const ll tx[9] = {0, 1, 1, -1, -1, 2, 2, -2, -2};
const ll ty[9] = {0, 2, -2, 2, -2, 1, -1, 1, -1};
const ll ckx[9] = {0, 0, 0, 0, 0, 1, 1, -1, -1};
const ll cky[9] = {0, 1, 1, -1, -1, 0, 0, 0, 0};
ll T, f[10][11][10][11][2];
bool vis[10][11][10][11][2];

ll DFS(ll x1, ll y1, ll x2, ll y2, bool Now = 0)
{
	if (f[x1][y1][x2][y2][Now])
		return f[x1][y1][x2][y2][Now];
	if (vis[x1][y1][x2][y2][Now])
		return 0;
	vis[x1][y1][x2][y2][Now] = 1;
	if (!Now)
	{
		For(i, 1, 8)
		{
			ll x, y;
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
	}
	else
	{
	}
}

int main()
{
	cin.tie(0), ios::sync_with_stdio(false);
	cin >> T;
	while (T--)
	{
		static ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		ll res = DFS(x1, y1, x2, y2);
		cout << (ck ? "NO" : "YES") << endl;
	}
}