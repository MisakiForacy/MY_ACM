#include <bits/stdc++.h>
#define all (x) begin(x), end(x)
#define siz (x)((int)x.size())

#define LOG 12

using namespace std;
using LL = long long;

const LL inf = 1e18;

void solve()
{
	int n, q;
	cin >> n >> q;
	vector<vector<int>> g(n + 1);
	vector<vector<int>> f(4098, vector<int>(n + 1, 0));

	for (int i = 0; i <= 4097; i++)
		for (int j = 0; j <= n; j++)
			f[i][j] = j;

	auto findx = [&](auto findx, int num, int x) -> int
	{
		if (x != f[num][x])
		{
			f[num][x] = findx(findx, num, f[num][x]);
		}
		return f[num][x];
	};

	auto merge = [&](int num, int u, int v) -> void
	{
		u = findx(findx, num, u);
		v = findx(findx, num, v);
		if (u == v)
			return;
		if (u > v)
			swap(u, v);
		f[num][u] = v;
	};

	auto same = [&](int num, int u, int v) -> bool
	{
		u = findx(findx, num, u);
		v = findx(findx, num, v);
		return (u == v);
	};

	LL sum = 0;

	for (int i = 1; i <= q; i++)
	{
		char opt;
		LL u, v, w;
		cin >> opt;
		if (opt == '+')
		{
			cin >> u >> v >> w;
			merge(4097, u, v);
			auto Add = [&](auto Add, int w) -> void
			{
				if (same(w, u, v))
					return;
				merge(w, u, v);
				for (LL sub = 1ll << 11; sub; sub >>= 1)
					if (w & sub)
						Add(Add, w ^ sub);
			};
			Add(Add, w);
			// LL mask = w;
			// for (LL sub = mask; sub; sub = (sub - 1) & mask)
			// {
			// 	merge(sub, u, v);
			// }
		}
		else
		{
			cin >> u >> v;
			if (!same(4097, u, v))
			{
				sum -= 1;
			}
			else
			{
				LL use = 0;
				LL mask = (1LL << 12) - 1;
				for (LL sub = (1ll << 11); sub; sub >>= 1)
					if (same(use | sub, u, v))
						use |= sub;
				// for (LL sub = mask; sub; sub = (sub - 1) & mask)
				// {
				// 	if (same(sub, u, v))
				// 	{
				// 		use = max(use, sub);
				// 		break;
				// 	}
				// }
				sum += use;
			}
		}
	}
	cout << sum << '\n';
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
	cin >> T;
	while (T--)
		solve();
}