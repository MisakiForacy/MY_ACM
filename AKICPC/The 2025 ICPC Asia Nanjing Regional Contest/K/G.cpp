#include <bits/stdc++.h>
#define For(i, n, m) for (ll i = n; i <= m; i++)
#define endl "\n"
using namespace std;
typedef long long ll;
struct Bucket
{
	ll v, l, num;
	Bucket(ll a = 0, ll b = 0, ll c = 0) : v(a), l(b), num(c) {}
} a[400010];
struct Quest
{
	ll t, num, ans;
	Quest(ll a = 0, ll b = 0, ll c = 0) : t(a), num(b), ans(c) {}
} Q[200010];
struct sortl
{
	bool operator()(Bucket &lhs, Bucket &rhs) const { return lhs.l < rhs.l; }
};
struct sortv
{
	bool operator()(Bucket &lhs, Bucket &rhs) const { return lhs.v > rhs.v; }
};
struct sortT
{
	bool operator()(Bucket &lhs, Bucket &rhs) const
	{
		if (lhs.l == 0 || rhs.l == 0)
			return lhs.l < rhs.l;
		else
			return (lhs.v + lhs.l - 1) / lhs.l > (rhs.v + rhs.l - 1) / rhs.l;
	}
};
ll T, n, q, Totalv, Totall;
bool vis[400010];

int main()
{
	cin.tie(0), ios::sync_with_stdio(false);
	cin >> T;
	while (T--)
	{
		cin >> n;
		Totalv = Totall = 0;
		For(i, 1, n)
		{
			cin >> a[i].v;
			vis[i] = vis[i + n] = 0;
			a[i].num = i;
			Totalv += a[i].v;
		}
		For(i, 1, n)
		{
			cin >> a[i].l, Totall += a[i].l;
		}
		cin >> q;
		For(i, 1, q)
		{
			cin >> Q[i].t;
			Q[i].num = i;
		}
		sort(Q + 1, Q + q + 1, [](Quest &A, Quest &B)
			 { return (A.t != B.t ? A.t < B.t : A.num < B.num); });
		// t >= min (Vx, Vy) / lx
		priority_queue<Bucket, vector<Bucket>, sortl> ql;
		priority_queue<Bucket, vector<Bucket>, sortv> qv;
		priority_queue<Bucket, vector<Bucket>, sortT> qt;
		For(i, 1, n) if (!vis[a[i].num]) ql.push(a[i]), qv.push(a[i]), qt.push(a[i]);
		For(i, 1, q)
		{
			while (!ql.empty() && !qv.empty())
			{
				while (!ql.empty() && vis[ql.top().num])
					ql.pop();
				while (!qv.empty() && vis[qv.top().num])
					qv.pop();
				while (!ql.empty() && !qv.empty() && qv.top().num == ql.top().num)
				{
					ql.pop(), qv.pop();
					while (!ql.empty() && vis[ql.top().num])
						ql.pop();
					while (!qv.empty() && vis[qv.top().num])
						qv.pop();
				}
				if (!(!ql.empty() && !qv.empty() &&
					  qv.top().num != ql.top().num &&
					  ql.top().l * Q[i].t >= qv.top().v))
					break;
				++n;
				a[n] = Bucket(ql.top().v, qv.top().l, n);
				vis[ql.top().num] = vis[qv.top().num] = 1;
				Totalv -= qv.top().v, Totall -= ql.top().l;
				qv.pop(), ql.pop();
				ql.push(a[n]), qv.push(a[n]), qt.push(a[n]);
			}
			while (!qt.empty() && (vis[qt.top().num] || Q[i].t * qt.top().l >= qt.top().v))
			{
				if (!vis[qt.top().num])
				{
					Totall -= qt.top().l;
					Totalv -= qt.top().v;
					vis[qt.top().num] = 1;
				}
				qt.pop();
			}
			Q[i].ans = Totalv - Q[i].t * Totall;
		}
		sort(Q + 1, Q + q + 1, [](Quest &A, Quest &B)
			 { return A.num < B.num; });
		For(i, 1, q) cout << Q[i].ans << " \n"[i == q];
	}
}