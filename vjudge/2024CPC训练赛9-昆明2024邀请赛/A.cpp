#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#define tans cout<<"答案:";
#define int long long
#define rep(i,a,b) for(int i = a; i <= b; i++)
using namespace std;

const int N = 4e5 + 10;
struct Node {
	int id;
	int sum, level, cnt;
	vector<int> a;
	int full_k, rest_val;
}node[N];
bool cmp(Node e1, Node e2) {
	if (e1.level == e2.level) return e1.sum < e2.sum;
	return e1.level < e2.level;
}
bool cmp2(Node e1, Node e2) {
	return e1.id < e2.id;
}
void solve() {
	int n, m, k; cin >> n >> m >> k;
	rep(i, 1, n) {
		node[i].a.resize(m+10);
		cin >> node[i].level;
		node[i].id = i;
		node[i].sum = 0, node[i].cnt = 0;
		node[i].full_k = 0, node[i].rest_val = 0;
		rep(j, 1, m) {
			int x; cin >> x;
			node[i].a[j] = x;
			if (x == -1) node[i].cnt++;
			else node[i].sum += x;
		}
	}
	sort(node + 1, node + 1 + n, cmp);

	//tans;
	rep(i, 2, n) {
		if (node[i].level > node[i - 1].level) {
			int d = node[i].sum - node[i - 1].sum;
			if (d <= 0) {
				d = -d;
				if (node[i].cnt * k <= d) {
					cout << "No" << endl;
					return;
				}

				node[i].full_k = d / k; node[i].rest_val = d % k + 1;
				node[i].sum += node[i].full_k * k + node[i].rest_val;
			}

		}
		else if(node[i].level == node[i - 1].level) {
			if (node[i].sum < node[i - 1].sum) {
				int d = node[i].sum - node[i - 1].sum;
				if (d < 0) {
					d = -d;
					if (node[i].cnt * k < d) {
						cout << "No" << endl;
						return;
					}

					node[i].full_k = d / k; node[i].rest_val = d % k;
					node[i].sum += node[i].full_k * k + node[i].rest_val;
				}
			}
		}

	}

	sort(node + 1, node + 1 + n, cmp2);

	cout << "Yes" << endl;
	rep(i, 1, n) {
		rep(j, 1, m) {
			if (j != 1) cout << " ";
			if (node[i].a[j] == -1) {
				if (node[i].full_k > 0) {
					node[i].full_k--;
					cout << k;
				}
				else if (node[i].rest_val > 0) {
					cout << node[i].rest_val;
					node[i].rest_val = 0;
				}
				else {
					cout << 0;
				}
			}
			else {
				cout << node[i].a[j];
			}
		}
		cout << endl;
	}

}

signed main() {

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}

