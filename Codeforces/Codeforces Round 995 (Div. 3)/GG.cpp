#include <bits/stdc++.h>
#define all(x) begin(x),end(x)
#define int long long
using namespace std;

struct Node {
	// 最多两个候选 (val, cnt) 的 Misra-Gries 容器
	array<int,2> val;
	array<int,2> cnt;
	Node() {
		val = {-1,-1};
		cnt = {0,0};
	}
	void add_one(int x, int c = 1) {
		// 向容器加入 c 次值 x
		if (c <= 0) return;
		if (val[0] == x) { cnt[0] += c; return; }
		if (val[1] == x) { cnt[1] += c; return; }
		if (cnt[0] == 0) { val[0] = x; cnt[0] = c; return; }
		if (cnt[1] == 0) { val[1] = x; cnt[1] = c; return; }
		// 需要消元
		int d = min(cnt[0], min(cnt[1], c));
		cnt[0] -= d; cnt[1] -= d; c -= d;
		if (c > 0) {
			// 仍有剩余，继续放入（此时必有空位）
			if (cnt[0] == 0) { val[0] = x; cnt[0] = c; }
			else if (cnt[1] == 0) { val[1] = x; cnt[1] = c; }
			else {
				// 理论上不会发生
			}
		}
	}
	static Node merge(const Node &A, const Node &B) {
		Node C;
		// 将 A、B 的两个候选按计数加入（顺序无关）
		for (int i = 0; i < 2; i++) if (A.cnt[i] > 0) C.add_one(A.val[i], A.cnt[i]);
		for (int i = 0; i < 2; i++) if (B.cnt[i] > 0) C.add_one(B.val[i], B.cnt[i]);
		return C;
	}
};

struct SegTree {
	int n;
	vector<Node> st;
	SegTree(int n=0): n(n), st(4*n+4) {}
	void build(int p, int l, int r, const vector<int> &a) {
		if (l == r) {
			st[p] = Node();
			st[p].add_one(a[l], 1);
			return;
		}
		int m = (l + r) >> 1;
		build(p<<1, l, m, a);
		build(p<<1|1, m+1, r, a);
		st[p] = Node::merge(st[p<<1], st[p<<1|1]);
	}
	Node query(int p, int l, int r, int ql, int qr) {
		if (ql <= l && r <= qr) return st[p];
		int m = (l + r) >> 1;
		if (qr <= m) return query(p<<1, l, m, ql, qr);
		if (ql >  m) return query(p<<1|1, m+1, r, ql, qr);
		Node L = query(p<<1, l, m, ql, qr);
		Node R = query(p<<1|1, m+1, r, ql, qr);
		return Node::merge(L, R);
	}
};

int count_in_range(const vector<int> &pos, int l, int r) {
	auto it1 = lower_bound(all(pos), l);
	auto it2 = upper_bound(all(pos), r);
	return (int)(it2 - it1);
}

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n+1);
	for (int i = 1; i <= n; i++) cin >> a[i];

	// 坐标压缩
	vector<int> comp(a.begin()+1, a.end());
	sort(all(comp));
	comp.erase(unique(all(comp)), comp.end());
	auto get_id = [&](int x)->int {
		return (int)(lower_bound(all(comp), x) - comp.begin()); // 0-based id
	};

	vector<int> id(n+1);
	for (int i = 1; i <= n; i++) id[i] = get_id(a[i]);

	// 每个值的出现位置
	int m = (int)comp.size();
	vector<vector<int>> pos(m);
	for (int i = 1; i <= n; i++) pos[id[i]].push_back(i);

	// 线段树维护 Misra-Gries 候选（存压缩 id）
	SegTree st(n);
	st.build(1, 1, n, id);

	while (q--) {
		int l, r; cin >> l >> r;
		int len = r - l + 1;
		int thr = len / 3 + 1; // 严格大于 floor(len/3)

		Node nd = st.query(1, 1, n, l, r);
		vector<int> cand_ids;
		for (int i = 0; i < 2; i++) if (nd.cnt[i] > 0) cand_ids.push_back(nd.val[i]);
		vector<int> ansv;
		for (int cid : cand_ids) {
			int c = count_in_range(pos[cid], l, r);
			if (c >= thr) ansv.push_back(comp[cid]);
		}
		sort(all(ansv));
		if (ansv.empty()) {
			cout << -1 << '\n';
		} else {
			for (int i = 0; i < (int)ansv.size(); i++) {
				if (i) cout << ' ';
				cout << ansv[i];
			}
			cout << '\n';
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T; 
	cin >> T;
	while (T--) solve();
	return 0;
}