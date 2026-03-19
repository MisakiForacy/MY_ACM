#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	if (!(cin >> t)) return 0;
	while (t--) {
		int n;
		cin >> n;
		vector<vector<int>> a;
		a.reserve(n);
		int maxLen = 0;
		for (int i = 0; i < n; ++i) {
			int k; cin >> k; maxLen = max(maxLen, k);
			vector<int> v(k);
			for (int j = 0; j < k; ++j) cin >> v[j];
			a.push_back(move(v));
		}

		// 将数组按字典序升序排序（短前缀更小）
		sort(a.begin(), a.end());

		// 单指针按列选择“第一个长度≥c”的数组
		int p = 0; // 指向当前满足长度条件的最早数组索引
		for (int c = 1; c <= maxLen; ++c) {
			while (p < n && (int)a[p].size() < c) ++p;
			int val = a[p][c - 1];
			cout << val << (c == maxLen ? '\n' : ' ');
		}
	}
	return 0;
}

